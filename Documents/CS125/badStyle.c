/*
 * This program illustrates how difficult programs
 * are to read when they are not following consistent
 * coding conventions.  
 *
 * Your job:
 * 1) Update the coding style to make it easier to read.
 *    consistent spaces, consistent } position, etc.
 * 2) Fix the error in the code that causes the conversion to 
 *    be incorrect.
 *
 * File: tempConv.c
 * Project: In Class Work Lect7
 * Purpose: Convert temperatures in Fahrenheit to Celsius.      
 */

#include <stdio.h>

int main(){ 
	int fTemp, cTemp;
	printf("Enter the temp in Fahrenheit: ");
	while (scanf("%d", &fTemp)<=0) {
		printf("Error. Enter number, not letters.");
		printf("Try again.");
		while ((getchar()) != '\n');
	}
	printf("%d Fahrenheit\n", fTemp);
	
	/* convert the temp to Celcius (F-32)*5/9 = C */
	cTemp = (fTemp - 32) * (5.0/9.0);
	
	printf("        =       \n");  printf("%d Celsius\n", cTemp);
	
	return 0;
}

