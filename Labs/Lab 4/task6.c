#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<signal.h>

void alarm_handler(int sig){ 
	printf("Time's up!\n"); 
	exit(0);
}

int main(){
	signal(SIGALRM, alarm_handler);
	alarm(5);
	
	int i = 1;
	while(1){
		sleep(1);
		printf("in sleep loop %d\n", i);
		i++;
	}
	
	pause();
	return 0;

}
