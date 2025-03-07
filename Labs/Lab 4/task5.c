#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(){
	int id = fork();
	if(id > 0) {
		wait(NULL);
		printf("Parent process: Child terminated\n");
	} else if(id == 0){
		execlp("ls", "ls", "-l", (char*)NULL);
		
		printf("execlp() failed\n");
		return 1;
		
	}

	return 0;
}
