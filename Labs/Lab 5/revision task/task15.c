#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open input.txt for reading and writing (create if not exists)
    fd = open("input.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    // Read file contents into buffer
    ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        exit(1);
    }

    // Fork a child process
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        exit(1);
    }

    if (pid == 0) { // Child process
        const char *msg = "Processed by child process\n";
        
        // Write new content to the file
        lseek(fd, 0, SEEK_END);  // Move to end of file
        write(fd, msg, sizeof(msg));

        // Close file descriptor
        close(fd);

        // Execute cat command to display modified content
        execlp("cat", "cat", "input.txt", NULL);
        
        // If execlp fails
        perror("execlp failed");
        exit(1);
    } else { // Parent process
        wait(NULL); // Wait for child process to complete
        printf("Parent process completed.\n");
    }

    close(fd);
    return 0;
}
