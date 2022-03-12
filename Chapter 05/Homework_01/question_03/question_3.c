/* 03/11/2022 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
	int rc = fork();
	if(rc == 0){
		printf("Hello ");
	} else{
		int rc_wait = wait(NULL);
		printf("Goodbye\n");
	}
}