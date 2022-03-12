/* 03/11/2022 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
	int rc = fork();
	if(rc == 0){ //child
		printf("I'm child!!");
	}else{
		int *store;
		int rc_wait = waitpid(rc, store, 0); //wait returns child's PID!
		printf("I'm parent!!");
	}
	return 0;
}