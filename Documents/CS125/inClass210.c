#include <stdio.h>
void displayMessage();
void triple();
int main(){
	int y;
	displayMessage();
	printf("How many times would you like me to say bye?\n");
	scanf("%d", &y);
	while (y <0){
		printf("Please type an integer greater than 1\n");
	        scanf("%d", &y);
	
}
	triple(y);
	return 0;
}
void displayMessage(){
	int x;
	for (x=0;x<10;x++)
		printf("Hello There\n");
}
void triple(int y){
	int x=0;
	while (x<y){
		printf("Bye\n");
		x++;
}
}
