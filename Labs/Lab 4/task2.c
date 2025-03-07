#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int id = fork();
	
	if(id == 0) {
		int i = 0;
		while(i <= 100) {
			printf("I am a child process\n");
			i++;
		}
	} else if(id > 0) {
		wait(NULL);
		
		int i = 0;
		while(i <= 100) {
			printf("I am a parent process\n");
			i++;
		}
	}

	return 0;
}
