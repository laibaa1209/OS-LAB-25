#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

#define FIFO_FILE "/home/laiba/Desktop/OS/Lab6/6b/myfifo"
#define BUFISZ 100
int main(){
	int fd;
	char buffer[BUFISZ];
	ssize_t num_bytes;
	
	mkfifo(FIFO_FILE, 0666);
	fd = open(FIFO_FILE, O_WRONLY);
	
	if(fd == -1) {
		perror("open\n");
		exit(EXIT_FAILURE);
	}
	while(1) {
		printf("Producer: Enter a message (or 'exit' to quit): ");
		fgets(buffer, BUFISZ, stdin);
		num_bytes = write(fd, buffer, strlen(buffer));
		if(num_bytes < 0) {
			perror("write\n");
			exit(EXIT_FAILURE);
		}
		if(strncmp(buffer, "exit",4) == 0) { break;}
	}
	
	close(fd);
	unlink(FIFO_FILE);

	return 0;
}
