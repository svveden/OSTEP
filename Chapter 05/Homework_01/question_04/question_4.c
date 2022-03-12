/* 03/11/2022 */

#include <stdio.h>
#include <unistd.h>

int main(void){
	char *args[] = {"/bin/ls", NULL};
	int rc = fork();
	execvp(args[0], args);
	return 0;
}