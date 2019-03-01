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
	int inputTimes;
	int days = 0;
	int highTemp[MAXDAYS] = { 0 };
	int lowTemp[MAXDAYS] = { 0 };
	int highestDay;
	int lowestDay;
	int highestTemp;
	int lowestTemp;
	int averDays;
	float totalTemp = 0.00;

	//Ask for input the number of days.
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
	days = readInt();

	//If input wrong, reask for input the number of days.
	while (days < MINDAYS || days>MAXDAYS)
	{
		printf("\nInvalid entry, please enter a number between %d and %d, inclusive: ", MINDAYS, MAXDAYS);
		days = readInt();
	}

	//Ask for input the temperatures.
	printf("\n");
	for (index = 0; index < days; index++)
	{
		inputTimes = 0;
		do
		{
			if (inputTimes != 0)
			{
				printf("\nThe high temperature is lower than the low temperature, try again:\n\n");
			}

			printf("Day %d - High: ", index + 1);
			highTemp[index] = readInt();
			if (index == 0)
			{
				highestTemp = highTemp[index];
				highestDay = index + 1;
			}
			else if (highTemp[index] > highestTemp)
			{
				highestTemp = highTemp[index];
				highestDay = index + 1;
			}

			printf("Day %d - Low: ", index + 1);
			lowTemp[index] = readInt();
			if (index == 0)
			{
				lowestTemp = lowTemp[index];
				lowestDay = index + 1;
			}
			else if (lowTemp[index] < lowestTemp)
			{
				lowestTemp = lowTemp[index];
				lowestDay = index + 1;
			}
			inputTimes++;
		} while (highTemp[index] < lowTemp[index]);
	}

	//Print temperatures out.
	printf("\nDay  Hi  Low\n");
	for (index = 0; index < days; index++)
		printf("%d%5d%6d\n", index + 1, highTemp[index], lowTemp[index]);

	//Print the highest temperature and the lowest temperature.
	printf("\nThe highest temperature was %d, on day %d\n", highestTemp, highestDay);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, lowestDay);

	//Ask for inputting a day, and caculate the average temperature.
	do
	{
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
		averDays = readInt();
		if (averDays >= 0)
		{
			while (averDays<1 || averDays>days)
			{
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", days);
				averDays = readInt();
			}
			totalTemp = 0.00;
			for (index = 0; index < averDays; index++)
				totalTemp = totalTemp + (float)highTemp[index] + (float)lowTemp[index];
			printf("\nThe average temperature up to day %d is: %.2f\n", averDays, totalTemp / averDays / 2.0);
		}
	} while (averDays >= 0);
	printf("\nGoodbye!\n");
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
			printf("\nInvalid entry, try again: ");
			do {
				scanf("%c", &otherChar);
			} while (otherChar != '\n');
		}
	} while (firstChar != '\n');
	return intValue;
}