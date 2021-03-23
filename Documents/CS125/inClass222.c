#include <stdio.h>
#include <string.h>
int main(){
	char sent[102];
	int x,length;
	printf("Type in a sentence under 30 words\n");
	fgets(sent,102,stdin);
	length = strlen(sent);
	for (x=0;x<=length+1;x++){
		if (sent[x]>=97&&sent[x]<=122)
			sent[x]-=32;	
	}
	printf("Capital Letters:%s\n",sent);
	for (x=0;x<=length+1;x++){
                if (sent[x]<=90&&sent[x]>=65)
                        sent[x]+=32;
        }
	printf("Lowercase Letters:%s\n",sent);
	return 0;
}
