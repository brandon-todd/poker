#include <stdio.h>

int main(){
	int x,y,low,high,n,total;
	char letter;
	for (x=2;x<=10;x++)
		printf("%d\n", x);
	for (x=1;x<=99;x+=2)
		printf("%d\n",x);
	printf("Type in a number to count up by from 1 to 10\n");
	scanf("%d",&y);
	for (x=1;x<=10;x+=y)
		printf("%d\n",x);
	printf("Type in a low number to start the count from\n");
	scanf("%d",&low);
	printf("Type in a high number to end the count at\n");
	scanf("%d", &high);
	while (low >=high){
		printf("Please type in a high number greater than the low number\n");
		scanf("%d",&high);
	}
	for (x = low;x <= high;x++)
		printf("%d\n", x);
	printf("Please enter a vowel:\n");
	scanf(" %c", &letter);
	while (letter!='a'&&letter!='e'&&letter!='i'&&letter !='o'&&
		letter!='u'&&letter!='y') {
			printf("That is not a vowel. Try again:\n");
			scanf(" %c", &letter);
	}
	printf("Congrats! You picked a vowel!\n");
	printf("Input a number. Type 0 to end the program\n");
	scanf("%d", &n);
	while (n !=0){
		printf("Input a number. Type 0 to get the sum of numbers\n");
	        scanf("%d", &n);
		total += n;
	}		
	printf("Total: %d\n", total);
	return 0;
}

