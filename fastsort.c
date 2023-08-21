#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void finfo(){
	printf("\nThis sorts a file, give it one.\n\n");
	exit(0);
}

int sorter(const void *str1, const void *str2){
	char *const *pp1 = str1;
	char *const *pp2 = str2;
	return strcmp(*pp1, *pp2);
}

char **read_file(char *file_name){
	char **lines = malloc(10*sizeof(char*)); //malloc array of pointers to strings
	lines[0] = malloc(sizeof(char)*100); //malloc first string
	int i = 0;
	FILE *fp;
	fp = fopen(file_name, "r"); //open passed file name
	
	while(fgets(lines[i], 100, fp) != NULL){ //while fgets doesnt return null,
		i++;								 //read each line into a pointer in array
		lines[i] = malloc(sizeof(char)*100);
		if(i > 10){
			lines = realloc(lines, i*2); //realloc if more than initial 10
		}
	}

	fclose(fp);
	
	for(int x = 0; x < i; x++){
		printf("%s\n", lines[x]); //print list before sort
	}
	qsort(lines, i, sizeof(*lines), sorter); //sort
	for(int x = 0; x < i; x++){
		printf("%s\n", lines[x]); //print list after sort
	}
	return lines;
}

int main(int argc, char *argv[]){
	if(argc < 2){
		finfo(); //make sure file name is given
	}
	char **lines = read_file(argv[1]);
	return 0;
}
