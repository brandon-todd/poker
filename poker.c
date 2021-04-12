#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
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
	printf("You are player 0\n");
	printf("1's = 10\n");

	srand(time(NULL));
	reset_money();
	game_sequence();	
	
	return 0;
}
void print_cards(int num, int num1){
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
	intro[7][7] = show_value(num);
	intro[1][1] = show_value(num);
	intro[4][4] = show_suit(num);
	intro[1][10] = show_value(num1);
	intro[7][16] = show_value(num1);
	intro[4][12] = show_suit(num1);
	print_array(intro);
}
void print_flop(int num,int num1, int num2){
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
        intro[7][7] = show_value(num);
        intro[1][1] = show_value(num);
        intro[4][4] = show_suit(num);
        intro[7][16] = show_value(num1);
        intro[1][10] = show_value(num1);
        intro[4][13] = show_suit(num1);
        intro[7][25] = show_value(num2);
        intro[1][19] = show_value(num2);
        intro[4][22] = show_suit(num2);
        print_array(intro);

}
void print_turn(int num,int num1,int num2,int num3){
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
        intro[7][7] = show_value(num);
        intro[1][1] = show_value(num);
        intro[4][4] = show_suit(num);
        intro[7][16] = show_value(num1);
        intro[1][10] = show_value(num1);
        intro[4][13] = show_suit(num1);
	intro[7][25] = show_value(num2);
        intro[1][19] = show_value(num2);
        intro[4][22] = show_suit(num2);
        intro[7][34] = show_value(num3);
        intro[1][28] = show_value(num3);
        intro[4][31] = show_suit(num3);
        print_array(intro);
}
void print_river(int num,int num1,int num2,int num3,int num4){

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
        intro[7][7] = show_value(num);
        intro[1][1] = show_value(num);
        intro[4][4] = show_suit(num);
        intro[7][16] = show_value(num1);
        intro[1][10] = show_value(num1);
        intro[4][13] = show_suit(num1);
        intro[7][25] = show_value(num2);
        intro[1][19] = show_value(num2);
        intro[4][22] = show_suit(num2);
        intro[7][34] = show_value(num3);
        intro[1][28] = show_value(num3);
        intro[4][31] = show_suit(num3);
	intro[7][43] = show_value(num4);
        intro[1][37] = show_value(num4);
        intro[4][40] = show_suit(num4);
        print_array(intro);

}
void print_array(char lines[ROWS][COLS]){
	int x;
	for (x=0;x<ROWS;x++){
		printf("%s\n",lines[x]);
	}	
}
void fold_sequence(){
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
	int i,b3;
	while (p[0].bet < p[1].bet){
                        printf("Player 1 has raised you to %d. Bet that amount or type 0 to fold\n",p[1].bet);
                        scanf("%d", &b3);
			if (b3 == p[1].bet){
				for (i=2;i<0;i--){
					p[i].bet = b3;
				}
				break;
			}

			else if (b3 == 0){
				p[0].fold = 1;
			}
	}
	while (p[0].bet < p[2].bet){
                        printf("Player 2 has raised you to %d. Bet that amount or type 0 to fold\n",p[2].bet);
                        scanf("%d", &b3);
			if (b3 == p[1].bet){
                                for (i=2;i<0;i--){
                                        p[i].bet = b3;
                                }
				break;
                        }
                        else if (b3 == 0){
                                p[0].fold = 1;
				break;
			}
	}
	if (p[1].bet ==0)
		printf("Player 1 folded\n");
	if (p[2].bet== 0)
		printf("Player 2 folded\n");
}
void annie(){
	int bet,i,bet_num;	
	printf("Annie Up ($20) (type 0 to fold)\n");
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
	int bet,i;
        
	if (p[0].money>0&& p[0].fold == 0){
        	printf("How much would you like to bet? (type -1 to fold)\n");
	        scanf("%d",&bet);

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
void create_deck(){
	int i;
	
	for (i=1;i<53;i++){
		deck[i-1] = i;
	}
}
void shuffle_deck(){
	int ran,i,old,ran2;
	for (i=1;i<300;i++){
		ran=rand()%52;
		ran2 = rand()%52;
		old= deck[ran];
		deck[ran]=deck[ran2];
		deck[ran2]=old;
	}	
}
void reset_players(){
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
	int i;
	for (i=0;i<3;i++){
		p[i].money = 200;
	}
}
void start_game(){
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
int card_value(int card){
	int num;
	num = card%13+1;
	return num;
}
char show_value(int card){
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
	int num;
	num = card/13;
	return num;
}
char show_suit(int card){
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
void check_high(){
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
	int j,count,k;
        for (k=0;k<3;k++){
                count = 1;
                for (j=0;j<7;j++){
                        if (card_value(p[k].full[j]) == (card_value(p[k].full[j+1])-1)&& suit(p[k].full[j])==suit(p[k].full[j+1])){
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
void check_rf(){
	int k;
	for (k=0;k<3;k++){
		if (p[k].hand[11]>0 && p[k].hand[6]==13)
			p[k].hand[12] = 13;
	}
}
