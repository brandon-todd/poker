/*
Brandon Todd
*/
#include <stdio.h>
void teamPower(int,int,int);

int main(){
	int pikachu = 50, golem = 45, ditto = 30,speed,x;
	float mps;
	teamPower(pikachu,golem,ditto);
	teamPower(-1,pikachu,golem);
	
	printf("Enter starting speed(miles/hr):");
	scanf(" %d", &speed);
	for (x=speed;x<speed+100;x+=10){
		mps=x*5280*0.3048/60/60;
		printf("%d miles/hour = %0.2f meters/sec\n", x,mps); 
	}
	return 0;
}
void teamPower(int x,int y, int z){
	if (x<=0 ||y<=0|| z<=0)
		printf("Team loses\n");
	else
		printf("Total health: %d\n", x+y+z);
}
