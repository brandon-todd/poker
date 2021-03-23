#include <stdio.h>
int main(){
	int x,c, python, java, matlab;
	printf("How many people like C?\n");
	scanf("%d", &c);
	printf("How many people like Java?\n");
	scanf("%d", &python);
	printf("How many people like Python?\n");
	scanf("%d", &java);
	printf("How many people like Matlab?\n");
	scanf("%d", &matlab);
	printf("C          |");
	for (x=0; x<c;x++)
		printf("*");
	printf("\nJava       |");
	for (x=0;x<java;x++)
		printf("*");
	printf("\nPython     |");
        for (x=0; x<python;x++)
                printf("*");
        printf("\nMatlab     |");
        for (x=0;x<matlab;x++)
                printf("*");
	printf("\n");
	return 0;	
}
