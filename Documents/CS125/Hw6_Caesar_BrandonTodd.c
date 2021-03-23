#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void Caesar_Cipher(char*);

int main(){
        char encrypt[22];
        printf("Type an encrypted word\n");
        fgets(encrypt,22,stdin);
	Caesar_Cipher(encrypt);

        return 0;
}

void Caesar_Cipher(char* enc){
        int x,length,count = -5;
        length = strlen(enc);
	char possible[length+1];
        while (count<=5){
                for (x=0;x<length-1;x++){
			if (enc[x]+count>=60 && enc[x]+count<=126)
                        	possible[x] = enc[x]+count;
			else if (enc[x] + count >=126)
				possible[x]= 126;
			else if (enc[x] +count <=60)
				possible[x] = 60;
		}

       		printf("Shift of: %d decrypted word is %s\n",count,possible);
                ++count;
        }
}


