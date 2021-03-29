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
void check_full_house();
void check_four();
void check_sf();
void check_rf();
struct player{
	int cards[2];
	int hand[13];
	int full[7];
	int money;
};
struct player p[4];

int deck[52],middle[5];


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
	check_full_house();
	check_four();
	check_sf();
	check_rf();
	for (i=0;i<13;i++){
		printf("%3d",p[0].hand[i]);
	}
	printf("\n");
	for (i=0;i<7;i++){
		printf("%3d", card_value(p[0].full[i]));
	}	
	printf("\n");
	for (i=0;i<7;i++){
		printf("%3d", suit(p[0].full[i]));
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
