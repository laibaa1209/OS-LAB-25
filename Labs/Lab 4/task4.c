#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(){
	int fd1, fd2;
	char buffer[100];
	
	fd1=open("input.txt", O_RDONLY);
	if(fd1 < 0){
		printf("Error opening input.txt!\n");
		return 1;
	}
	
	int bytes_read = read(fd1,buffer,sizeof(buffer)-1);
	if(bytes_read < 0){
		printf("Error reading input.txt!");
		return 1;
	}
	else if(bytes_read == 0) {
		printf("input.txt is empty!\n");
		close(fd1);
		return 1;
	}
	
	buffer[bytes_read] = '\0';
	
	fd2 = open("output.txt", O_WRONLY | O_CREAT| O_TRUNC, 0644);
	if(fd2 < 0){
		printf("Error opening output.txt!\n");
		return 1;
	}
	
	int bytes_written = write(fd2, buffer, bytes_read);
	if(bytes_written < 0){
		printf("Error writing to output.txt!\n");
		return 1;
	}
	
	close(fd1);
	close(fd2);

	printf("File copied successfully!\n");
return 0;
}
