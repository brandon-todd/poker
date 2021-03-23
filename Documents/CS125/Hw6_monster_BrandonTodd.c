#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void health(int);

int main(){
	int c_health;
	srand(time(NULL));
	printf("Please type the health of the hero:\n");
	scanf("%d",&c_health);
	health(c_health);

	return 0;
}

void health(int c_health){
	int m_health;
	m_health = rand()%100+1;
	printf("Monster health = %d Hero health = %d\n",m_health,c_health);
	if (c_health>m_health)
		printf("Hero wins!\n");
	else
		printf("Monster wins!\n");	
}
