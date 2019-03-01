/********************************************************************** 
// ICP144 Assignment 1 
// File contacts.c
// Version 1.0 
// Date 2017/12/06 
// Author Cindy Chen 
//-------------------------------------------
//Assignment: 1
//Milestone:  4
/**********************************************************************/

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS
#include <stdio.h>
#include "contacts.h"
// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* fullname) {

	printf("Please enter the contact's first name: ");
	scanf("%[^\n]", fullname->firstName);
	flushkeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (optionalSwitch()) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%[^\n]", fullname->middleInitial);
		flushkeyboard();
	}

	printf("Please enter the contact's last name: ");
	scanf("%[^\n]", fullname->lastName);
	flushkeyboard();
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address* fulladress) {

	printf("Please enter the contact's street number: ");
	scanf("%d", &fulladress->streetNumber);
	flushkeyboard();

	printf("Please enter the contact's street name: ");
	scanf("%[^\n]", fulladress->street);
	flushkeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	if (optionalSwitch()) {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &fulladress->apartmentNumber);
		flushkeyboard();
	}

	printf("Please enter the contact's postal code: ");
	scanf("%[^\n]", fulladress->postalCode);
	flushkeyboard();

	printf("Please enter the contact's city: ");
	scanf("%[^\n]", fulladress->city);
	flushkeyboard();
}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* phonenumber) {

	printf("Do you want to enter a cell phone number? (y or n): ");
	if (optionalSwitch()) {
		printf("Please enter the contact's cell phone number: ");
		scanf("%[^\n]", phonenumber->cell);
		flushkeyboard();
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	if (optionalSwitch()) {
		printf("Please enter the contact's home phone number: ");
		scanf("%[^\n]", phonenumber->home);
		flushkeyboard();
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	if (optionalSwitch()) {
		printf("Please enter the contact's business phone number: ");
		scanf("%[^\n]", phonenumber->business);
		flushkeyboard();
	}
}

void title(void) {
	printf("Contact Management System\n-------------------------\n");
}

void flushkeyboard(void) {
	char characters = '1';
	do {
		scanf("%c", &characters);
	} while (characters != '\n');
}

int readInt(void) {
	int result;
	char firstChar;
	char otherChar;
	do {
		scanf("%d%c", &result, &firstChar);
		if (firstChar != '\n') {
			printf("\nInvalid entry, try again: ");
			do {
				scanf("%c", &otherChar);
			} while (otherChar != '\n');
		}
	} while (firstChar != '\n');
	return result;
}

int optionalSwitch(void) {
	int index = 3;
	char read = '0';
	do {
		if (index != 3)
			printf("Your input are not 'y' or 'n', please enter again.\n");
		scanf("%c", &read);
		flushkeyboard();
		switch (read) {
		case'y':
		case'Y':
			index = 1;
			break;
		case'n':
		case'N':
			index = 0;
			break;
		default:
			index = 2;
		}
	} while (index == 2);
	return index;
}
