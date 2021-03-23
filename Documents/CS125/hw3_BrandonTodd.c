/*
Author: Brandon Todd
Purpose: This program reads test scores until -1 is entered and classifies
them by grade letter. It then prints the highest grade, lowest grade, and
the average grade.
Version: 1.0 February 2,2021
Resources: Powerpoint from class
*/

#include <stdio.h>

int main(){
	float scores, total=0, min_score = 101, max_score = -2;
	int number = 0;
	printf("Enter test scores, enter -1 to get average, min, and max values\n");
	scanf("%f", &scores);
	while (scores != -1){	
		if (scores >= 90 && scores <=100)
			printf("A\n");
		else if (scores >= 80 && scores <90)
			printf("B\n");
		else if (scores >=70 && scores <80)
			printf("C\n");
		else if (scores >=60 && scores <70)
			printf("D\n");
		else if (scores >=0 &&  scores <60)
			printf("F\n");
		else
			printf("Grade not in range\n");
		total += scores;
		number ++;
		if (scores> max_score && scores <= 100 && scores >= 0)
			max_score = scores;
		if (scores< min_score && scores <= 100 && scores >= 0)
			min_score = scores;
		printf("Enter test scores, enter -1 to get average, min, and max valuesm\n");
	        scanf("%f", &scores);

}
	printf("The average score is: %0.2f\n", total/number);
	printf("The lowest score is: %0.2f\n", min_score);
	printf("The highest score is: %0.2f\n", max_score);
	return 0;
}
