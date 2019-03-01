/********************************************************************** 
// ICP144 Assignment 2 
// File contacts.c
// Version 1.0 
// Date 2017/12/08 
// Author Cindy Chen 
//-------------------------------------------
//Assignment: 2
//Milestone:  1
/**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS
#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name* fullname)
{
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


// getAddress:
void getAddress(struct Address* fulladress)
{
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


// getNumbers:
void getNumbers(struct Numbers* phonenumber)
{
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


// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
	// Use an open and close curly brace with a blank line
}