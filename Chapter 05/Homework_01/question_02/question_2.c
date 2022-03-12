/* 03/11/2022 */

#include <stdio.h>
#include <unistd.h>

int main(void){
	FILE *fp = fopen("test.txt", "w");
	int rc = fork();
	if(rc == 0){
		fputc('a', fp);
	}else{
		fputc('b', fp);
	}

	return 0;
}