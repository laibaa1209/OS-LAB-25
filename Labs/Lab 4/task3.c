#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
	printf("User id:%d\n", getuid());
	
	int id = fork();
	if(id == 0){
		printf("Child Process-Current id: %d\nParent id: %d\n", getpid(), getppid());
	} else if(id > 0){
		printf("Parent Process-Current id: %d\nParent id: %d\n", getpid(), getppid());
	}
	
	return 0;
}
