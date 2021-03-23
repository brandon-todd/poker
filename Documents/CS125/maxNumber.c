#include <stdio.h>

int main(){
	int maxNumber,loop=2, isPrime=0,x,count=0;
	printf("Enter a max number: ");
	scanf("%d",&maxNumber);
	while ((maxNumber-1)>loop){
		isPrime=0;
		x=2;
		while (x <= loop/2){
			if ((loop % x)==0){
				isPrime=1;
				break;
			}
			x++;	
		}
		if (isPrime==0){
			count++;
			printf("%d is prime\n",loop);
		}
		loop++;
	}
	printf("The amount of prime numbers between 2 and %d is %d\n",maxNumber,count);
	return 0;
}
