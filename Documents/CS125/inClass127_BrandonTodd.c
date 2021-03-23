/*
*/
#include <stdio.h>
int main()
{
	int hour;
	printf("Enter the hour of the day\n");
	scanf("%d", &hour);
	if (hour==12)
		printf("The next hour is 1\n");
	else
		printf("The next hour is %d\n", hour+1);
	return 0;
}

