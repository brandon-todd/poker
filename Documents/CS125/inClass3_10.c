#include <stdio.h>
#include <stdlib.h>

int main(){
	char name[51];
	int age,age_num,name_num;
	printf("Enter your name:");
	fgets(name,51,stdin);
	name_num = atoi(name);
	while (name_num !=0){
		printf("You did not enter a valid name. Try again:");
		fgets(name,51,stdin);
	        name_num = atoi(name);
	}
	printf("Enter your age:");
	age_num= scanf("%d",&age);
	while (age_num != 1){
		scanf("%*[^\n]");
		printf("You did not enter a number. Enter a valid age:");
		age_num = scanf("%d",&age);
	}
	printf("Name: %s\nAge: %d\n",name,age);
	return 0;
}
