/*
Author: Brandon Todd
Purpose: This program uses a brute force approach to guessing a four digit 
password that is greater than 1000 in value.Once it guesses the password, it
exits the loop
Version: 1.0 February 11,2021
Resources: Powerpoint from class
*/

#include <stdio.h>
int main(){
	int pw,guess=1000;
	printf("Please input a four digit password\n");
	scanf("%d", &pw);
	while (pw <1000|| pw >9999){
		printf("Invalid password\n");
		printf("Please type in a four digit password of 1000 or greater\n");
		scanf("%d",&pw);
	}
	while (guess!= pw){
	printf("Trying password: %d\n",guess);
	guess ++;
}
	printf("The password is %d\n",guess);
	printf("Computer cracked the password in %d tries\n", guess-999);
	return 0;
}
/* Most passwords have a minimum length of greater than 4 because each new
digit makes it exponentially harder to brute force guess the password. 
Adding both uppercase and lower case numbers and special charters adds to the
amount of possible values for each character, so instead of only having 26 
possible values for the first character with lower case letters, you double it 
by including capital letters and also make the vlaue of possible combinations 
larger with the use of numbers and special characters. */
