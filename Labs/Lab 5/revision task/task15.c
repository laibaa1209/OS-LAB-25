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
    printf("Opening 'input.txt'...\n");
    fd = open("input.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    // Read file contents into buffer
    printf("Reading contents from 'input.txt'...\n");
    ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        exit(1);
    } else {
        printf("Read %zd bytes from 'input.txt'.\n", bytesRead);
    }

    // Fork a child process
    printf("Forking a child process...\n");
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        exit(1);
    }

    if (pid == 0) { // Child process
        printf("Child process started (PID: %d).\n", getpid());
        const char *msg = "Processed by child process\n";
        
        // Write new content to the file
        printf("Child is writing to 'input.txt'...\n");
        lseek(fd, 0, SEEK_END);  // Move to end of file
        write(fd, msg, sizeof(msg));
        printf("Child finished writing to 'input.txt'.\n");

        // Close file descriptor
        close(fd);

        // Execute cat command to display modified content
        printf("Child is executing 'cat input.txt'...\n");
        execlp("cat", "cat", "input.txt", NULL);

        // If execlp fails
        perror("execlp failed");
        exit(1);
    } else { // Parent process
        wait(NULL); // Wait for child process to complete
        printf("Child process completed.\n");
        printf("Parent process completed.\n");
    }

    close(fd);
    return 0;
}

