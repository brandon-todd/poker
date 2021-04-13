#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int deck[52];

void create_deck(){
	/*This function creates a deck represented by an integer array with each card represented by an integer 1 to 52*/
	int i;
	
	for (i=1;i<53;i++){
		deck[i-1] = i;
	}
}
void shuffle_deck(){
	/*This function randomly switches two cards in the deck for 300 times, therefore shuffling the card values in the deck*/
	int ran,i,old,ran2;
	for (i=1;i<300;i++){
		ran=rand()%52;
		ran2 = rand()%52;
		old= deck[ran];
		deck[ran]=deck[ran2];
		deck[ran2]=old;
	}	
}

int card_value(int card){
	/*This function takes a card from the deck array and returns the value from 1 to 13 of that cards using the modulus function*/
	int num;
	num = card%13+1;
	return num;
}
char show_value(int card){
	/*This function takes a card from the deck array and returns the value as a number on the card as a single character.
	This function is used for the printing of each card to the screen as ascii art. In the function, 10's are represented by 1's so we do not have to
	return an array for only a single exception to the rule of only being one letter in length to print to the card*/
	int num;
	char value;
	num = card%13+1;
	if (num==1)
		value ='2' ;
	if (num ==2)
		value ='3' ;
	if (num==3)
		value = '4' ;
	if (num ==4)
		value = '5' ;
	if (num==5)
		value = '6';
	if (num==6)
		value = '7';
	if (num==7)
		value = '8';
	if (num==8)
		value = '9';
	if (num==9)
		value = '1';
	if (num ==10)
		value = 'J';
	if (num==11)
		value = 'Q';
	if (num==12)
		value = 'K';
	if (num==13)
		value = 'A';
	return value;
}	
int suit(int card){
	/*This function divides the integer by 13 from the deck of cards to figure out what suit the card (or integer) represents*/
	int num;
	num = card/13;
	return num;
}
char show_suit(int card){
	/*This function divides the integer from the array of integers that is the deck and returns a single character to represent the suit
	of the card. This function is used to print what suit the card is the the screen in ascii art*/
	int num;
	num = card/13;
	char suit;
	if (num==0){
		suit = 'S';
	}
	else if (num==1){
		suit = 'H';
	}
	else if (num==2){
		suit = 'C';
	}
	else if (num==3){
		suit = 'D';
	}	
	return suit;
}
