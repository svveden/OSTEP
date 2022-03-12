/* 03/11/2022 */

#include <stdio.h>
#include <unistd.h>

int main(void){
	close(STDOUT_FILENO);
	int rc = fork();
	if(rc == 0){ //child
		printf("This shouldn't work?");
	}
}