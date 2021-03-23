
#include <stdio.h>

int main(){
        int maxNumber,loop=2, isPrime=0,x,count=0;
        printf("Enter a max number: ");
        scanf("%d",&maxNumber);
	for (loop=2;loop<(maxNumber-1);loop++){
                isPrime=0;
                for (x=2;x <= loop/2;x++){
                        if ((loop % x)==0){
                                isPrime=1;
                                break;
                        }
                }
                if (isPrime==0){
                        printf("%d is prime\n",loop);
			count++;
		}
        }
	printf("The amount of prime numbers between 2 and %d is %d\n",maxNumber,count);

        return 0;
}


