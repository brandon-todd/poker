/*
File Name: hw2_BrandonTodd.c
Author: Brandon Todd
Purpose: This program calculates the volume of a pyramid by taking user input
	of length, width, and height
Version: 1.0
Resources: Powerpoint
*/
#include <stdio.h>
int main()
{
	float l,h,w;
	float volume;
	printf("Enter value for length\n");
	scanf("%f", &l);
	while  (l <= 0)
	{
		printf("Not a valid input. Enter new value for lenth\n");
		scanf("%f",&l);
	}
	printf("Enter value for width\n");
	scanf("%f", &w);
	while (w <= 0)
	{
		printf("Not a valid input. Enter new value for width\n");
		scanf("%f", &w);
	}
	printf("Enter value for height\n");
	scanf("%f", &h);
	while (h <= 0)
	{
		printf("Not a valid input. Enter new value for height\n");
		scanf("%f",&w);
	}
	volume = l*w*h/3;
	printf("The volume is: %f \n",volume);
	if (900000 <= volume && volume <= 920000)
		printf("This could be the Great Pyramid of Giza\n");
		
	return 0;
}


