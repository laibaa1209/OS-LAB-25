#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int id = fork();
	if(id == 0){
		printf("I am child 1 with id: %d\n", getpid());
		exit(0);
	}
	if(id > 0){
		wait(NULL);
		int id2 = fork();
		
		if(id2 == 0){
			printf("I am child 2 and my parent id is: %d\n",getppid());
			exit(0);
		} else if(id2 > 0){
		wait(NULL);
		}
	}
	
	return 0;
}
