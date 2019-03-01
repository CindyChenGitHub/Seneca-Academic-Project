/********************************************************************** 
// ICP144 Workshop 2: cash register_at home
// File cashRegister.c
// Version 1.0 
// Date 2017/09/16 
// Author Cindy Chen 
/**********************************************************************/

// Start your code below:
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	double amount;
	float gst = 0.00;
	float roundgst = 0.00;
	float balance = 0.00;
	int intBalance = 0;
	int loonies = 0;
	int quarter = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);
	gst = amount*0.13;
	roundgst = (int)((gst + 0.005) * 100.00) / 100.00;
	printf("GST: %.2f\n", roundgst);
	amount = amount + roundgst;
	printf("Balance owing: $%.2f\n", amount);

	loonies = (int)amount;
	balance = amount - loonies;
	intBalance = (int)(balance * 100);
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, (float)intBalance / 100);

	quarter = intBalance / 25;
	intBalance = intBalance % 25;
	printf("Quarters required: %d, balance owing $%.2f\n", quarter, (float)intBalance / 100);

	dimes = intBalance / 10;
	intBalance = intBalance % 10;
	printf("Dimes required: %d, balance owing $%.2f\n", dimes, (float)intBalance / 100);

	nickels = intBalance / 5;
	intBalance = intBalance % 5;
	printf("Nickels required: %d, balance owing $%.2f\n", nickels, (float)intBalance / 100);

	pennies = intBalance / 1;
	intBalance = intBalance % 1;
	printf("Pennies required: %d, balance owing $%.2f\n", pennies, (float)intBalance / 100);

	return 0;
}