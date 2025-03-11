#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_FILE "myfifo"  
#define BUFFER_SIZE 500

int main() {
    int fd;
    char buffer[BUFFER_SIZE];

    fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        exit(EXIT_FAILURE);
    }

    int my_bytes = read(fd, buffer, BUFFER_SIZE - 1);  
    if (my_bytes < 0) {
        perror("Error reading from FIFO");
    } else if (my_bytes == 0) {
        printf("FIFO is empty\n");
    } else {
        buffer[my_bytes] = '\0';  
        printf("Received from FIFO:\n%s\n", buffer);
    }

    close(fd);
    unlink(FIFO_FILE);  
    return 0;
}

