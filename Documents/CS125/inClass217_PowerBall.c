#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int red_ball();
int white_ball();
int guess_lotto();

int main(){
	int x,lotto_num,guess[6],count=0;
	srand(time(NULL));
	printf("*********** Powerball Numbers are...*************\n");
	for (x=1;x<=5;x++){
		printf("%d  ", white_ball());
	}
	lotto_num = red_ball();
	printf("\033[31m %d \033[0m", lotto_num);
	printf("\n");

	while (guess[5] != lotto_num){
		for (x=0;x<=6;x++){
			guess[x] = guess_lotto();
		}	
		printf("%d  %d  %d  %d  %d \033[31m %d \033[0m\n",guess[0],guess[1],guess[2],guess[3],guess[4],guess[5]);
		count++;
	}
	printf("You guess the powerball after buying %d tickets\n",count);
	return 0;
}
int red_ball(){
	int num;
	num = rand()%26 + 1;
	return num;
}
int white_ball(){
	int num;
	num = rand()%69 + 1;
	return num;
}
int guess_lotto(){
	int num = rand()%69 + 1;
	return num;
}
