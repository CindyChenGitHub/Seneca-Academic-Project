/********************************************************************** 
// ICP144 Workshop 2: cash register
// File cashRegister.c
// Version 1.0 
// Date 2017/09/16 
// Author Cindy Chen 
/**********************************************************************/

// Start your code below:
#include<stdio.h>
int main(void) {
	int loonies;
	int quarter;
	double amount;
	double balance;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);
	loonies = (int)amount;
	balance = amount - loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balance);
	quarter = (int)(balance/ 0.25);
	balance = balance - quarter*0.25;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarter, balance);
	return 0;
}