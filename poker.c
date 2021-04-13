/* Brandon Todd and Blake Moore
Project: Poker Game
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "cardgames.h"


#define ROWS 10
#define COLS 50


void create_deck();
void shuffle_deck();
void reset_players();
void start_game();
int card_value(int);
char show_value(int);
int suit(int);
char show_suit(int);
void check_pairs();
void check_high();
void check_three();
void check_straight();
void check_flush();
void check_full_house();
void check_four();
void check_sf();
void check_rf();
void print_cards(int, int);
void print_flop(int, int, int);
void print_turn(int, int, int, int);
void print_river(int, int, int, int, int);
void print_array(char lines[ROWS][COLS]);
void game_sequence();
void fold_sequence();
void call_raise_fold(int);
void raise();
void reset_money();
void annie();
void bet();
int choose_winner();

struct player{
	int cards[2];
	int hand[13];
	int full[7];
	int money;
	int fold;
	int max;
	int bet;
};
struct player p[4];
int pot,deck[52],middle[5];


int main(){
	/*This lets the player know what player you are, seeds the
	random number generator and commences the game.Because we used
	a char return for the value of the cards, it returns 10's as 
	1's.*/

	printf("You are player 0\n");
	printf("1's = 10\n");

	srand(time(NULL));
	reset_money();
	game_sequence();	
	
	return 0;
}
void print_cards(int num, int num1){
	/*This function prints the player's cards as an array*/
	char intro[ROWS][COLS]={
    "******************",
    "*       **       *",
    "*       **       *",
    "*       **       *",
    "*       **       *",
    "*       **       *",
    "*       **       *",
    "*       **       *",
    "******************"};
	if (card_value(num)==9){
		intro[7][7] = '0';
		intro[7][6] = '1';
		intro[1][1] = '1';
		intro[1][2] = '0';
	}
	else {
		intro[7][7] = show_value(num);
		intro[1][1] = show_value(num);
	}
	if (card_value(num1)==9){
		intro[1][10] = '1';
		intro[1][11] = '0';
		intro[7][15] = '1';
		intro[7][16] ='0';
	}
	else {	
		intro[1][10] = show_value(num1);
        	intro[7][16] = show_value(num1);
	}
	intro[4][4] = show_suit(num);
	intro[4][12] = show_suit(num1);
	print_array(intro);
}
void print_flop(int num,int num1, int num2){
	/*This function prints the first three middle cards as an array*/
	 char intro[ROWS][COLS]={
    "***************************",
    "*       **       **       *",
    "*       **       **       *",
    "*       **       **       *",
    "*       **       **       *",
    "*       **       **       *",
    "*       **       **       *",
    "*       **       **       *",
    "***************************",};
        if (card_value(num)==9){
                intro[7][7] = '0';
                intro[7][6] = '1';
                intro[1][1] = '1';
                intro[1][2] = '0';
        }
        else {
                intro[7][7] = show_value(num);
                intro[1][1] = show_value(num);
        }
        if (card_value(num1)==9){
                intro[1][10] = '1';
                intro[1][11] = '0';
                intro[7][15] = '1';
                intro[7][16] ='0';
        }
        else {
                intro[1][10] = show_value(num1);
                intro[7][16] = show_value(num1);
        }
	if (card_value(num2)==9){
		intro[1][19]='1';
		intro[1][20]='0';
		intro[7][24]='1';
		intro[7][25]='0';
	}
	else {
		intro[7][25] = show_value(num2);
	        intro[1][19] = show_value(num2);
	}
	
        intro[4][4] = show_suit(num);
        intro[4][13] = show_suit(num1);
        intro[4][22] = show_suit(num2);
        print_array(intro);

}
void print_turn(int num,int num1,int num2,int num3){
	/*This function prints the first four middle cards as ascii art*/
	 char intro[ROWS][COLS]={
    "************************************",
    "*       **       **       **       *",
    "*       **       **       **       *",
    "*       **       **       **       *",
    "*       **       **       **       *",
    "*       **       **       **       *",
    "*       **       **       **       *",
    "*       **       **       **       *",
    "************************************"};
        if (card_value(num)==9){
                intro[7][7] = '0';
                intro[7][6] = '1';
                intro[1][1] = '1';
                intro[1][2] = '0';
        }
        else {
                intro[7][7] = show_value(num);
                intro[1][1] = show_value(num);
        }
        if (card_value(num1)==9){
                intro[1][10] = '1';
                intro[1][11] = '0';
                intro[7][15] = '1';
                intro[7][16] ='0';
        }
        else {
                intro[1][10] = show_value(num1);
                intro[7][16] = show_value(num1);
        }
        if (card_value(num2)==9){
                intro[1][19]='1';
                intro[1][20]='0';
                intro[7][24]='1';
                intro[7][25]='0';
        }
        else {
                intro[7][25] = show_value(num2);
                intro[1][19] = show_value(num2);
        }
	if (card_value(num3)==9){
		intro[1][28]='1';
		intro[1][29]='0';
		intro[7][33]='1';
		intro[7][34]='0';
	}
	else {
		intro[1][28]=show_value(num3);
		intro[7][34]=show_value(num3);
	}
        intro[4][4] = show_suit(num);
        intro[4][13] = show_suit(num1);
	intro[4][22] = show_suit(num2);
        intro[4][31] = show_suit(num3);
        print_array(intro);
}
void print_river(int num,int num1,int num2,int num3,int num4){
	/*This function prints the full middle cards as ascii art*/
	 char intro[ROWS][COLS]={
    "*********************************************",
    "*       **       **       **       **       *",
    "*       **       **       **       **       *",
    "*       **       **       **       **       *",
    "*       **       **       **       **       *",
    "*       **       **       **       **       *",
    "*       **       **       **       **       *",
    "*       **       **       **       **       *",
    "*********************************************"};
	if (card_value(num)==9){
                intro[7][7] = '0';
                intro[7][6] = '1';
                intro[1][1] = '1';
                intro[1][2] = '0';
        }
        else {

                intro[7][7] = show_value(num);
                intro[1][1] = show_value(num);
        }
        if (card_value(num1)==9){
                intro[1][10] = '1';
                intro[1][11] = '0';
                intro[7][15] = '1';
                intro[7][16] ='0';
        }
        else {
                intro[1][10] = show_value(num1);
                intro[7][16] = show_value(num1);
        }
        if (card_value(num2)==9){
                intro[1][19]='1';
                intro[1][20]='0';
                intro[7][24]='1';
                intro[7][25]='0';
        }
        else {
                intro[7][25] = show_value(num2);
                intro[1][19] = show_value(num2);
        }
        if (card_value(num3)==9){
                intro[1][28]='1';
                intro[1][29]='0';
                intro[7][33]='1';
                intro[7][34]='0';
        }
        else {
                intro[1][28]=show_value(num3);
                intro[7][34]=show_value(num3);
        }
	if (card_value(num4)==9){
		intro[1][37]='1';
		intro[1][38]='0';
		intro[7][42]='1';
		intro[7][43]='0';
	}
	else {
		intro[7][43] = show_value(num4);
	        intro[1][37] = show_value(num4);
	}
	intro[4][4] = show_suit(num);
        intro[4][13] = show_suit(num1);
        intro[4][22] = show_suit(num2);
        intro[4][31] = show_suit(num3);
        intro[4][40] = show_suit(num4);
        print_array(intro);

}
void print_array(char lines[ROWS][COLS]){
	/*This funtion takes the arrays of cards created above to print as ascii art*/
	int x;
	for (x=0;x<ROWS;x++){
		printf("%s\n",lines[x]);
	}	
}
void fold_sequence(){
	/*This function checks if the player has folded, an if they have, ensures they can not win the hand
	by making all the values in the hand 0*/
	int i,k;
	for (i=0;i<3;i++){
		if (p[i].fold>0){
			p[i].max = 0;
			for (k=0;k<13;k++){
				p[i].hand[k] = 0;
				
			}
		}
	}
}

void game_sequence(){
	/*This is the sequence of the game, making sure the functions run in the correct order while completing the game the way its supposed to be played*/
	int win,i,k;
	while (p[0].money>0){
		for (i=0;i<3;i++){
			printf("Player %d has $%d\n",i,p[i].money);
		}
		create_deck();
        	shuffle_deck();
        	reset_players();
        	start_game();
        	check_high();
        	check_pairs();
        	check_three();
        	check_straight();
       		check_flush();
	        check_full_house();
	        check_four();
	        check_sf();
	        check_rf();

		for (i=1;i<3;i++){
                        if (p[i].money <=0)
                                p[i].fold = 1;
                }


		printf("Your cards are\n");
       		print_cards(p[0].cards[0],p[0].cards[1]);
		annie();

		printf("Your cards are\n");
        	print_cards(p[0].cards[0],p[0].cards[1]);
		printf("The Flop:\n");
       		print_flop(middle[0],middle[1],middle[2]);
		bet();

		printf("Your cards are\n");
       		print_cards(p[0].cards[0],p[0].cards[1]);	
        	printf("The Turn:\n");
        	print_turn(middle[0],middle[1],middle[2],middle[3]);
		bet();

		printf("Your cards are\n");
        	print_cards(p[0].cards[0],p[0].cards[1]);
        	printf("The River:\n");
        	print_river(middle[0],middle[1],middle[2],middle[3],middle[4]);
		bet();

		fold_sequence();
		win = choose_winner();
		p[win].money+=pot;
		printf("Player %d won!\n",win);
		printf("They had a %c of %c",show_value(p[win].cards[0]),show_suit(p[win].cards[0]));
		printf(" and a %c of %c\n",show_value(p[win].cards[1]),show_suit(p[win].cards[1]));
		printf("They now have $%d\n",p[win].money);
		pot=0;

		for (i=0;i<3;i++){
			printf("%3d",p[i].max);
			for (k=0;k<13;k++){
				printf("%3d",p[i].hand[k]);
			}
			printf("\n");
		}
		
		if (p[1].money <=0)
			printf("Player 1 is out\n");
		if (p[2].money <=0)
			printf("Player 2 is out\n");
		if (p[1].money<=0 &&p[2].money<=0){
			printf("You won!!\n");
			break;
		}
	}
	printf("You Lose!\n");
}
void call_raise_fold(int b){
	/* This function returns a randomized bet by the computer players with a higher chance of raising
	when the computer player has a good hand*/
	int i,k,b2;
	for (k=12;k>=0;k--){
                for (i=1;i<3;i++){
                        if (p[i].hand[k] >0&& k >= p[i].max)
                                p[i].max = k;
                }
        }

	for (i=1;i<3;i++){
		if (p[i].fold==0){
			b2 = rand()%(p[i].max+1);
			if (b2 == 0){
				p[i].fold = 1;
				p[i].bet = 0;
			}
			else if (b2 > 4 &&p[i].money >= (10+b))
				p[i].bet = 20+b;
			else if (b2 > 4 && p[i].money < (10+b))
				p[i].bet = p[i].money;
			else if (b2 < 4 && b2 >0 && p[i].money >= b)
				p[i].bet = b;
			else if (b2 < 4 && b2 >0 && p[i].money < b)
				p[i].bet = p[i].money;
		}	
		else
			p[i].bet = 0;
	}
}
void raise(){
	/*This function gives the user player an option to fold or call the computer player's raise*/
	int b3=1,bet_num;
	if (p[0].bet < p[1].bet){
		while (b3 != p[1].bet && b3!=0){
			printf("Player 1 has raised you to %d. Bet that amount or type 0 to fold\n",p[1].bet);
                	bet_num=scanf("%d", &b3);
		
			while (bet_num != 1){
                		scanf("%*[^\n]");
                		printf("Please enter a valid number(%d to bet 0 to fold)\n",p[1].bet);
               			bet_num = scanf("%d",&b3);
			}
		}
		if (b3 == p[1].bet){
			p[0].bet = b3;
			p[2].bet = b3;
		}

		else if (b3 == 0){
			p[0].fold = 1;
		}
	}
	if (p[0].bet < p[2].bet){
		while (b3!=p[2].bet&&b3!=0){	
                	printf("Player 2 has raised you to %d. Bet that amount or type 0 to fold\n",p[2].bet);
                	bet_num=scanf("%d", &b3);

			while (bet_num != 1){
                        	scanf("%*[^\n]");
                        	printf("Please enter a valid number(%d to bet 0 to fold)\n",p[2].bet);
                        	bet_num = scanf("%d",&b3);
                	}
		}

		if (b3 == p[2].bet){
        	        p[1].bet = b3;
                        p[0].bet = b3;
                }
                else if (b3 == 0){
                        p[0].fold = 1;
		}
	}
	if (p[1].bet ==0)
		printf("Player 1 folded\n");
	if (p[2].bet== 0)
		printf("Player 2 folded\n");
}
void annie(){
	/*This is the antie bet, which is the first bet in a game of poker with a $20 minimum. This function
	also calls the raise and call_hold_raise functions to complete the entire first round of betting*/
	int bet,i,bet_num;	
	printf("Antie Up ($20) (type 0 to fold)\n");
	bet_num = scanf("%d",&bet);
	while (bet_num != 1){
		scanf("%*[^\n]");
		printf("Please enter a valid number(20 to bet 0 to fold)\n");
		bet_num = scanf("%d",&bet);
	}
	while (bet!=20){
                if (bet == 0){
                        p[0].fold = 1;
           		break;
	        }
                else {
                        printf("You must bet the annie or fold to start\n");
                        scanf("%d",&bet);
                }
        }
        if (bet > 0 && bet < p[0].money){
		p[0].bet = bet;
		call_raise_fold(p[0].bet);
		raise();			
                for (i=0;i<3;i++){
                        p[i].money -= p[i].bet;
                        pot += p[i].bet;
			printf("Player %d has $%d left\n",i,p[i].money);
                        p[i].bet = 0;
		}       
        	p[0].bet = 0;
	}
	else if (bet>0 && bet>= p[0].money){
		p[0].bet = p[0].money;
                call_raise_fold(p[0].bet);
		raise();
                for (i=0;i<3;i++){
                        p[i].money -= p[i].bet;
                        pot += p[i].bet;
                        printf("Player %d has $%d left\n",i,p[i].money);
                        p[i].bet = 0;
                }
                p[0].bet = 0;
	}
	
}
void bet(){
	/*This is the bet function, which completes all other bets in game of poker using the player structure to keep track of bets and money
	and an integer to keep track of the pot. This function also calls the raise and call_hold_raise functions 
	to complete the entire first round of betting*/
	int bet_num,bet,i;
	if (p[0].money>0&& p[0].fold == 0){
        	printf("How much would you like to bet? (type -1 to fold)\n");
	        bet_num = scanf("%d",&bet);

		while (bet_num != 1){
                	scanf("%*[^\n]");
               		printf("Please enter a valid number(0 to fold)\n");
        	        bet_num = scanf("%d",&bet);
	        }


		while (bet<0){
               		if (bet == -1){
                       		p[0].fold = 1;
                	}

                	else {
                        	printf("You must bet or fold\n");
                        	scanf("%d",&bet);
                	}
        	}
        	if (bet>0&& bet< p[0].money){
	                p[0].bet = bet;
        	        call_raise_fold(p[0].bet);
               		raise();
			for (i=0;i<3;i++){
                        	p[i].money -= p[i].bet;
                        	pot += p[i].bet;
                        	printf("Player %d has $%d left\n",i,p[i].money);
                        	p[i].bet = 0;
                	}
                	p[0].bet = 0;
        	}
        	else if (bet>0 && bet>= p[0].money){
                	p[0].bet = p[0].money;
                	call_raise_fold(p[0].bet);
                	raise();
			for (i=0;i<3;i++){
                        	p[i].money -= p[i].bet;
                        	pot += p[i].bet;
                        	printf("Player %d has $%d left\n",i,p[i].money);
                        	p[i].bet = 0;
                	}
               		p[0].bet = 0;
        	}

	}
	else {
		if (p[0].money ==0)
			printf("You have no money\n");
		else if (p[0].fold ==1)
			printf("You folded\n");
	}

}
int choose_winner(){
	/*This function runs through the player structure and each player's hand checking for the highest hand and returning an integer indicating
	which player won that round and thus gets the money added. If a player has folded, their hand is simply and array of 0, so they could never win*/
	int winner,k,i,num;
	for (k=12;k>=0;k--){
		for (i=0;i<3;i++){
			if (p[i].hand[k] > 0 && k >= p[i].max)
				p[i].max = k;
		}
	}		
	if (p[0].max > p[1].max && p[0].max > p[1].max)
		winner = 0;
	else if (p[1].max > p[0].max && p[1].max >p[2].max)
		winner = 1;
	else if (p[2].max > p[1].max && p[2].max >p[0].max)
		winner = 2;
	else if (p[0].max == p[1].max){
		num = p[0].max;
		if (p[0].hand[num] > p[1].hand[num])
			winner=0;
		else if (p[1].hand[num] > p[0].hand[num])
			winner = 1;
		else {
			for (k=num;k<0;k--){
        			if (p[0].hand[k] >p[1].hand[k]){
					winner=0;
                               		break;
				}
				else if (p[1].hand[k]> p[0].hand[k]){
					winner = 1;
					break;
				}
	                }
	        }
	}
	else if (p[0].max == p[2].max){
		num = p[0].max;
                if (p[0].hand[num]> p[2].hand[num])
                        winner=0;
                else if (p[2].hand[num]> p[0].hand[num])
                        winner = 2;
                else {
                        for (k=num;k>=0;k--){
                                if (p[0].hand[k] >p[2].hand[k]){
                                        winner=0;
                                        break;
                                }
                                else if (p[2].hand[k]> p[0].hand[k]){
                                        winner = 2;
                                        break;
                                }
                        }
                }

	}
	else if (p[1].max == p[2].max){
		num = p[1].max;
                if (p[1].hand[num]> p[2].hand[num])
                        winner=1;
                else if (p[2].hand[num]> p[1].hand[num])
                        winner = 2;
                else {
                        for (k=num;k>=0;k--){
                                if (p[1].hand[k] >p[2].hand[k]){
                                        winner=1;
                                        break;
                                }
                                else if (p[2].hand[k]> p[1].hand[k]){
                                        winner = 2;
                                        break;
                                }
                        }
                }

	}

	return winner;	
}
void reset_players(){
	/*This function is used to start the game reseting all stats in the player structure except for their money 
	and resets the cards in the player hands and middle*/
	int i,x;
	for (i=0;i<3;i++){
		p[i].cards[0] = 0;
		p[i].cards[1] = 0;
		p[i].max = 0;
		p[i].fold = 0;
	}
	for (i=0;i<11;i++){
		for (x=0;x<3;x++){
		p[x].hand[i] = 0;
		}
	}
	for (i=0;i<5;i++)
		middle[i] = 0;
}
void reset_money(){
	/*This function resets the money statistic for each player in the array of player structures*/
	int i;
	for (i=0;i<3;i++){
		p[i].money = 200;
	}
}
void start_game(){
	/*This function sets the cards in each player's hand and sets the cards in the middle*/
	int i,x,k,j,temp1;
	p[0].cards[0]= deck[0];
	p[0].cards[1]= deck[3];
	p[1].cards[0]= deck[1];
	p[1].cards[1]= deck[4];
	p[2].cards[0]= deck[2];
	p[2].cards[1]= deck[5];
	for (i=0;i<5;i++){
		x=i+6;
		middle[i] = deck[x];
	}
	for (i=0;i<3;i++){
		for (x=0;x<2;x++){
			p[i].full[x] = p[i].cards[x];
		}
	}
	for (i=0;i<3;i++){
		for (x=0;x<5;x++){
			p[i].full[x+2]=middle[x];
		}
	}
        for (k=0;k<3;k++){
                for (i=0;i<8;i++){
                        for (j=i+1;j<7;j++){
                                if (card_value(p[k].full[i]) > card_value(p[k].full[j])){
                                        temp1 = p[k].full[i];
                                        p[k].full[i] = p[k].full[j];
                                        p[k].full[j] = temp1;
                                }
                        }
                }
        }
}

void check_high(){
	/*This function checks for a high value in the player's hand and puts it in the first slot of the p.hand array*/
	int value,i;
	for (i=0;i<3;i++){
		value = card_value(p[i].cards[0]);
		if (card_value(p[i].cards[1])>value)
			p[i].hand[0] = card_value(p[i].cards[1]);
		else
			p[i].hand[0] = value;
	}
}
void check_pairs(){
	/*This function checks for pairs in the player's full hand and puts the value of the pair in slots 
	1,2, and 3 sequentially if the previous one is full*/
	int i,x,k,count;
	for (k=0;k<3;k++){
		for (i=0;i<7;i++){
			count=1;
			for (x=i+1;x<7;x++){
				if (card_value(p[k].full[i])==card_value(p[k].full[x])){
					count++;
                                        if (count >= 2 && p[k].hand[1]==0)
                                        	p[k].hand[1] = card_value(p[k].full[i]);
                                        if (count >= 2 && p[k].hand[1]>0 &&p[k].hand[2]==0&&p[k].hand[1] != card_value(p[k].full[i]))
                                                p[k].hand[2] = card_value(p[k].full[i]);
					if (count >=2 &&p[k].hand[2]>0 && p[k].hand[2] != card_value(p[k].full[i]))
						p[k].hand[3] = card_value(p[k].full[i]);
                                        
                                }
                        }
                }
        }

}
void check_three(){
	/*This function checks for a three of a kind in the player's full hand and puts the value of the triplet in either index 4 
	or if that index is full, index  5 of the p.hand array*/
	int i,x,k,j,count;
	for (k=0;k<3;k++){
		for (j=1;j<4;j++){
			if ( p[k].hand[j] >0){
				for (i=0;i<7;i++){
					count=1;
					for (x=i+1;x<7;x++){
						if (card_value(p[k].full[i])==card_value(p[k].full[x])){
							count++;
							if (count >= 3 && p[k].hand[4]==0)
								p[k].hand[4] = card_value(p[k].full[i]);
							if (count >= 3 && p[k].hand[4]>0 && p[k].hand[4] != card_value(p[k].full[i]))
								p[k].hand[5] = card_value(p[k].full[i]);
						}
					}
				}
			}
		}
	}
}
void check_straight(){
	/*This function checks for straights in the player's full hand and stores the highest value in the straight in index 6 of p.hand*/
	int j,count,k;
	for (k=0;k<3;k++){
		count = 1;
		for (j=0;j<7;j++){
			if (card_value(p[k].full[j]) == (card_value(p[k].full[j+1])-1)){
				count++;
				if (count>=5)
					p[k].hand[6]= card_value(p[k].full[j+1]);
			}
			else if (card_value(p[k].full[j])==(card_value(p[k].full[j+1])))
				;
			else
				count = 1;
		}
	}       
}

void check_flush(){
	/*This function checks for a flush in the p.full array (5 with the same suit as checked by the suit function) and stores the value of 
	the flush if it is there in index 7 of the p.hand array*/
	int k,i,j,count;
	for (k=0;k<3;k++){
		for (i=0;i<8;i++){
			count=0;
			for (j=i+1;j<7;j++){
				if (suit(p[k].full[i])==suit(p[k].full[j])){
					count++;
					if (count>=4)
						p[k].hand[7] = card_value(p[k].full[j]);
				}
			}
		}	
	}
	
}
void check_full_house(){
	/*This function checks for a full house, which is a triplet and a pair with different card values in the p.full array.
	 It stores the value of the triplet in index 9 of p.hand and the pair in index 8 of p.hand*/
	int i,j,k;
	for (k=0;k<3;k++){
		for (i=4;i<6;i++){
			for (j=1;j<4;j++){
				if (p[k].hand[i]>0){
					if (p[k].hand[i] != p[k].hand[j] && p[k].hand[j]>0){
						p[k].hand[8] = p[k].hand[j];
						p[k].hand[9] = p[k].hand[i];
					}
				}
			}	
		}
	}	
}
void check_four(){
	/*This function checks for a four of a kind in each p.full array. It stores the card value of this four of a kind in 
	index 10 in each p.hand array*/
        int i,x,k,j,count;
        for (k=0;k<3;k++){
                for (j=1;j<4;j++){
                        if ( p[k].hand[j] >0){
                                for (i=0;i<7;i++){
                                        count=1;
                                        for (x=i+1;x<7;x++){
                                                if (card_value(p[k].full[i])==card_value(p[k].full[x])){
                                                        count++;
                                                        if (count >= 4)
                                                                p[k].hand[10] = card_value(p[k].full[i]);
                                                }
                                        }
                                }
                        }
                }
        }
}
void check_sf(){
	/*This function checks for a straight in each p.full and then checks if each 
	card in the straight is the same suit and stores the value of the largest number in index 11 of respective p.hand array*/ 
	int j,count,k;
        for (k=0;k<3;k++){
                count = 1;
                for (j=0;j<7;j++){
                        if (card_value(p[k].full[j]) == (card_value(p[k].full[j+1])-1)&& suit(p[k].full[j])==suit(p[k].full[j+1])){
                                count++;
                                if (count>=5)
                                        p[k].hand[11]= card_value(p[k].full[j+1]);
                        }
                        else if (card_value(p[k].full[j])==(card_value(p[k].full[j+1])))
                                ;
                        else
                                count = 1;
                }
        }
	
	
}
void check_rf(){
	/*This function checks if there is a straight flush, and if the is and the highest card is an ace, then that means 
	The player has a straight flush of the highest value, which is a royal flush. It stores a 13 in index 12 of the respective p.hand array*/
	int k;
	for (k=0;k<3;k++){
		if (p[k].hand[11]>0 && p[k].hand[6]==13)
			p[k].hand[12] = 13;
	}
}
