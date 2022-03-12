/* 03/11/2022 */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void){
	int x = 100;
	int rc = fork();
	if(rc == 0){ //child process
		printf("Child's x before change: %d\n", x);
		x = 10;
		printf("Child's x after change: %d\n", x);
	} else{
		int rc_wait = wait(NULL);
		printf("Parent's x before change: %d\n", x);
		x = 9;
		printf("Parent's x after change %d\n", x);
	}
	return 0;
}