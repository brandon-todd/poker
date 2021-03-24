#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void create_deck();
void shuffle_deck();
void reset_players();
void start_game();
int card_value(int);
void show_value(int);
int suit(int);
void show_suit(int);
void check_pairs();
void check_high();
void check_three();
void check_straight();
void check_flush();
stuct player{
	int cards[3];
	int hand[11];
	int full[8];
	int money;
}p1,p2,p3;
player p[4];

int deck[53],player1[3],player2[3],player3[3],middle[6];
int player1_hand[11],player2_hand[11],player3_hand[11];
int player1_full[8],player2_full[8],player3_full[8];

int main(){
	int i;
	create_deck();
	srand(time(NULL));
	shuffle_deck();
	reset_players();
	start_game();	
	check_high();
	check_pairs();
	check_three();
	check_straight();
	check_flush();
	printf("%2d%2d\n",player1_hand[6],player1_hand[7]);
	for (i=0;i<8;i++){
		printf("%3d", card_value(player1_full[i]));
	}	
	printf("\n");

	return 0;
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
	}
	for (i=0;i<11;i++){
		for (x=0;x<3;x++){
		p[x].hand[i] = 0;
		}
	}
	for (i=0;i<5;i++)
		middle[i] = 0;
}
void start_game(){
	int i,x;
	p1.cards[0]= deck[0];
	p1.cards[1]= deck[3];
	p2.cards[0]= deck[1];
	p2.cards[1]= deck[4];
	p3.cards[0]= deck[2];
	p3.cards[1]= deck[5];
	for (i=0;i<5;i++){
		x=i+6;
		middle[i] = deck[x];
	}
	for (i=0;i<2;i++){
		for (x=0;i<3;x++){
			p[x].full[i] = p[x].cards[i];
	}
	for (i=0;i<5;i++){
		for (x=0;x<3;x++){
			p[x].full[i+2]=middle[i];
		}
	}
}
int card_value(int card){
	int num;
	num = card%13+1;
	return num;
}
void show_value(int card){
	int num;
	char value;
	num = card%13+1;
	if (num==1)
		value ='2';
	if (num ==2)
		value ='3';
	if (num==3)
		value = '4';
	if (num ==4)
		value = '5';
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
}	
int suit(int card){
	int num;
	num = card/13;
	return num;
}
void show_suit(int card){
	int num;
	num = card/13;
	char *suit;
	if (num==0)
		suit = "Spades";
	else if (num==1)
		suit = "Hearts";
	else if (num==2)
		suit = "Clubs";
	else if (num==3)
		suit = "Spades";	
}
void check_high(){
	int value,i;
	for (i=0;i<3;i++){
		value = p1.cards[0]%13+1;
		if (card_value(p[i].cards[1])>value)
			p[i].hand[0] = card_value(p[i].cards[1]);
		else
			p[i].hand[0] = value;
	}
}
void check_pairs(){
	int i,x;
	if (card_value(player1[0]) == card_value(player1[1]))
                player1_hand[1] = card_value(player1[0]);
	for (i=0;i<2;i++){
		for (x=0;x<5;x++){
			if (card_value(player1[i]) == card_value(middle[x]) && player1_hand[2] ==0){
				player1_hand[2]= card_value(player1[i]);
			}
			else if (card_value(player1[i]) == card_value(middle[x]) && player1_hand[2]>0){
                                player1_hand[3]= card_value(player1[i]);
			}
		}
	}
	if (card_value(player2[0]) == card_value(player2[1]))
                player2_hand[1] = card_value(player2[0]);
	for (i=0;i<2;i++){
                for (x=0;x<5;x++){
                        if (card_value(player2[i]) == card_value(middle[x]) && player2_hand[2] ==0){
                                player2_hand[2]= card_value(player2[i]);
			}
                        else if (card_value(player2[i]) == card_value(middle[x]) && player2_hand[2]>0){
                                player2_hand[3]= card_value(player2[i]);
			}
                }
        }
	if (card_value(player3[0]) == card_value(player3[1]))
		player3_hand[1] = card_value(player3[0]);
	for (i=0;i<2;i++){
                for (x=0;x<5;x++){
                        if (card_value(player3[i]) == card_value(middle[x]) && player3_hand[2] ==0){
                                player3_hand[2]= card_value(player3[i]);
                        }
			else if (card_value(player3[i]) == card_value(middle[x]) && player3_hand[2]>0){
                                player3_hand[3]= card_value(player3[i]);
			}
                }
        }

}
void check_three(){
	int i,x;
	if (card_value(player1[0])==card_value(player1[1])){
		for (i=0;i<5;i++){
			if (card_value(player1[0])==card_value(middle[i]))
				player1_hand[4] = card_value(player1[0]);
		}
	}
	if (card_value(player2[0])==card_value(player2[1])){
                for (i=0;i<5;i++){
                        if (card_value(player2[0])==card_value(middle[i]))
                                player2_hand[4] = card_value(player2[0]);
                }
        }
	if (card_value(player3[0])==card_value(player3[1])){
                for (i=0;i<5;i++){
                        if (card_value(player3[0])==card_value(middle[i]))
                                player3_hand[4] = card_value(player3[0]);
                }
        }
	for (i=0;i<5;i++){
		for (x=i+1;x<5;x++){
			if (card_value(middle[i])==card_value(middle[x])){
				if (card_value(middle[i])==card_value(player1[0])){
					if (player1_hand[4]==0)
						player1_hand[4] = card_value(player1[0]);
					else
						player1_hand[5] = card_value(player1[0]);
				}
				else if (card_value(middle[i]) == card_value(player1[1])){
					if (player1_hand[4]==0)
						player1_hand[4] = card_value(player1[0]);
					else
						player1_hand[5] = card_value(player1[1]);
				}
			}
		}
	}
	for (i=0;i<5;i++){
                for (x=i+1;x<5;x++){
                        if (card_value(middle[i])==card_value(middle[x])){
                                if (card_value(middle[i])==card_value(player2[0])){
                                        if (player2_hand[4]==0)
                                                player2_hand[4] = card_value(player2[0]);
                                        else
                                                player2_hand[5] = card_value(player2[0]);
				}
                                else if (card_value(middle[i]) == card_value(player2[1])){
                                        if (player2_hand[4]==0)
                                                player2_hand[4] = card_value(player2[0]);
                                        else
                                                player2_hand[5] = card_value(player2[1]);
				}
                        }
                }
        }
	for (i=0;i<5;i++){
                for (x=i+1;x<5;x++){
                        if (card_value(middle[i])==card_value(middle[x])){
                                if (card_value(middle[i])==card_value(player3[0])){
                                        if (player3_hand[4]==0)
                                                player3_hand[5] = card_value(player3[0]);
                                        else
                                                player3_hand[4] = card_value(player3[0]);
				}
                                else if (card_value(middle[i]) == card_value(player3[1])){
                                        if (player3_hand[4]==0)
                                                player3_hand[5] = card_value(player3[0]);
                                        else
                                                player3_hand[4] = card_value(player3[1]);
				}
                        }
                }
        }

}
void check_straight(){
	int i,j,temp1,count;
	for (i=0;i<8;i++){
		for (j=i+1;j<8;j++){
			if (card_value(player1_full[i])> card_value(player1_full[j])){
				temp1=player1_full[i];		
				player1_full[i] = player1_full[j];
				player1_full[j] = temp1;
			}
		}
	}
	for (i=0;i<8;i++){
                for (j=i+1;j<8;j++){
                        if (card_value(player2_full[i])> card_value(player2_full[j])){
                                temp1=player2_full[i];
                                player2_full[i] = player2_full[j];
                                player2_full[j] = temp1;
			}
                }
        }
	for (i=0;i<8;i++) {
                for (j=i+1;j<8;j++){
                        if (card_value(player3_full[i]) > card_value(player3_full[j])){
                                temp1=player3_full[i];
                                player3_full[i] = player3_full[j];
                                player3_full[j] = temp1;
			}
                }
        }
	count = 1;
	for (j=0;j<7;j++){
		if (card_value(player1_full[j]) == (card_value(player1_full[j+1])-1)){
			count++;
			printf("%d\n",count);
			if (count>=5)
				player1_hand[6]= card_value(player1_full[j+1]);
		}
		else if (card_value(player1_full[j])==(card_value(player1_full[j+1])))
			;
		else
			count = 1;
	}
        count=1;
        for (j=0;j<7;j++){
 	       if (card_value(player2_full[j]) == (card_value(player2_full[j+1])-1)){
        	       count++;
                       if (count>=5)
                	       player2_hand[6]= card_value(player2_full[j+1]);
                }
        	else if (card_value(player2_full[j])==(card_value(player2_full[j+1])))
                        ;
                else
                        count = 1;

	}

        count=1;
        for (j=0;j<7;j++){
	        if (card_value(player3_full[j]) == (card_value(player3_full[j+1])-1)){
        	        count++;
                        if (count>=5)
                	        player3_hand[6]= card_value(player3_full[j+1]);
        	}
		else if (card_value(player3_full[j])==(card_value(player3_full[j+1])))
                        ;
                else
                        count = 1;

	}

}
void check_flush(){
	int i,j,count;
	for (i=0;i<8;i++){
		count=0;
		for (j=i+1;j<8;j++){
			if (suit(player1_full[i])==suit(player1_full[j])){
				count++;
				if (count>=4)
					player1_hand[7] = card_value(player1_full[j]);
			}
		}

	}
	for (i=0;i<8;i++){
                count=0;
                for (j=i+1;j<8;j++){
                        if (suit(player2_full[i])==suit(player2_full[j])){
                                count++;
                                if (count>=4)
                                        player2_hand[7] = card_value(player2_full[j]);
                        }
                }

        }
	for (i=0;i<8;i++){
                count=0;
                for (j=i+1;j<8;j++){
                        if (suit(player3_full[i])==suit(player3_full[j])){
                                count++;
                                if (count>=4)
                                        player3_hand[7] = card_value(player3_full[j]);
                        }
                }

        }

}
