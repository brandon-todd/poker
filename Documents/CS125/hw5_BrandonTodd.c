/*
Author: Brandon Todd
Purpose: This program simulates a monkey typing letters into a keyboard using
random numbers. The first function simulates it typing a single letter. The 
watchMonkeyType program simulates typing a string of 3 letters until the word
cat is written, then it exits and prints the number of tries it took.
Version: 1.0 February 15,2021
Resources: Powerpoint from class
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int randomASCII4LowerCaseLetter();
int watchMonkeyType();

int main(){
	int count;
	printf("The monkey typed %c\n",randomASCII4LowerCaseLetter());
	count = watchMonkeyType();
	if (count >0)
		printf("The monkey typed 'cat' after %d tries\n", count);
	else
		printf("You did not watch the monkey type\n");
	return 0;
}

int randomASCII4LowerCaseLetter(){
	int num;
	srand(time(NULL));
    num = rand()%26 +97;
	return num;
	
}

int watchMonkeyType(){
	srand(time(NULL));
	int letters[3] = {0,0,0},x,input,count=0;
	printf("Do you want to watch the monkey type?(1=yes, 0=no)\n");
    scanf("%d", &input);
	while (input !=0 && input!=1 ){
		printf("Do you want to watch the monkey type?(1=yes, 0=no)\n");
	    scanf("%d", &input);
	
	}
	if (input == 1) {
		while (letters[0] != 'c' || letters[1] != 'a' || letters[2]!='t'){
                for (x=0;x<3;x++){
                	letters[x] = rand()%26+97;
				}
                count++;
            	printf("The monkey typed:%c%c%c\n", letters[0],letters[1],letters[2]);
	        }
	}
	else if (input ==0) {
        	while (letters[0] != 'c' || letters[1] != 'a' || letters[2] !='t'){
				for (x=0;x<3;x++){
               		letters[x] = rand()%26+97;
		    	}
            	count++;
	        }
	}
	return count;
}
