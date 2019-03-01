/********************************************************************** 
// ICP144 Workshop 4: Temperatures2_in_lab
// File cashRegister.c
// Version 1.0 
// Date 2017/10/04 
// Author Cindy Chen 
/**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include<stdio.h>
#define MINDAYS 3
#define MAXDAYS 10

int readInt(void);

int main(void)
{
	int index;
	int days = 0;
	int highTemp[MAXDAYS] = { 0 };
	int lowTemp[MAXDAYS] = { 0 };
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
	days = readInt();
	while (days < MINDAYS || days>MAXDAYS)
	{
		printf("\nInvalid entry, please enter a number between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
		days = readInt();
	}
	printf("\n");
	for (index = 0; index < days; index++)
	{
		printf("Day %d - High: ", index + 1);
		highTemp[index] = readInt();
		printf("Day %d - Low: ", index + 1);
		lowTemp[index] = readInt();
	}
	printf("\nDay\tHi\tLow\n");
	for (index = 0; index < days; index++)
		printf("%d\t%d\t%d\n", index + 1, highTemp[index], lowTemp[index]);
	return 0;
}

int readInt(void)
{
	int intValue;
	char firstChar;
	char otherChar;
	do {
		scanf("%d%c", &intValue, &firstChar);
		if (firstChar != '\n')
		{
			printf("Invalid entry, try again: ");
			do {
				scanf("%c", &otherChar);
			} while (otherChar != '\n');
		}
	} while (firstChar != '\n');
	return intValue;
}