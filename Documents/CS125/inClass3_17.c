#include <stdio.h>
#include <stdlib.h>
int main(){
	char *wisdom = malloc(100);
	FILE *f = fopen("recording.txt","a");
	printf("What are some words of wisdom you want to share?\n");
	fgets(wisdom,100,stdin);
	fputs(wisdom, f);
	fprintf(f,"\n");
	fclose(f);
	return 0;
}
