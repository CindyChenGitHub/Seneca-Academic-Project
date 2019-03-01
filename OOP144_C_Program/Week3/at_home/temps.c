/********************************************************************** 
// ICP144 Workshop 3: Temperatures_at_home
// File cashRegister.c
// Version 1.0 
// Date 2017/09/27 
// Author Cindy Chen 
/**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define NUMS 4
int main(void)
{
	int days = 0;
	int high;
	int low;
	int highest;
	int lowest;
	int highestday;
	int lowestday;
	int i;
	int n;
	float totalhigh = 0.00;
	float totallow = 0.00;

	printf("---=== IPC Temperature Analyzer ===---\n");
	for (i = 1; i <= NUMS; i++)
	{
		n = 0;
		days = i;
		do
		{
			if (n > 0)
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("Enter the high value for day %d: ", i);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i);
			scanf("%d", &low);
			printf("\n");
			n++;
		} while ((high <= low) || (high >= 41) || (low <= -41));
		totalhigh = totalhigh + high;
		totallow = totallow + low;
		if (days == 1)
		{
			highest = high;
			highestday = days;
			lowest = low;
			lowestday = days;
		}
		else
		{
			if (high > highest)
			{
				highest = high;
				highestday = days;
			}
			if (low < lowest)
			{
				lowest = low;
				lowestday = days;
			}
		}
	}
	printf("The average (mean) temperature was: %.2f\n", (totalhigh + totallow) / (days * 2));
	printf("The highest temperature was %d, on day %d\n", highest, highestday);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowestday);
	return 0;
}