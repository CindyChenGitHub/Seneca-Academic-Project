/********************************************************************** 
// ICP144 Assignment 2 
// File contacts.c
// Version 1.0 
// Date 2017/12/08 
// Author Cindy Chen 
//-------------------------------------------
//Assignment: 2
//Milestone:  2
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



// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name* fullname)
{
	printf("Please enter the contact's first name: ");
	scanf("%31[^\n]", fullname->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%7[^\n]", fullname->middleInitial);
		clearKeyboard();
	}

	printf("Please enter the contact's last name: ");
	scanf("%36[^\n]", fullname->lastName);
	clearKeyboard();
}



// getAddress:
void getAddress(struct Address* fulladress)
{
	printf("Please enter the contact's street number: ");
	fulladress->streetNumber = getInt();

	printf("Please enter the contact's street name: ");
	scanf("%41[^\n]", fulladress->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's apartment number: ");
		fulladress->apartmentNumber=getInt();
		clearKeyboard();
	}
	printf("Please enter the contact's postal code: ");
	scanf("%8[^\n]", fulladress->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%41[^\n]", fulladress->city);
	clearKeyboard();
}



// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers* phonenumber)
{
	printf("Please enter the contact's cell phone number: ");
	scanf("%11[^\n]", phonenumber->cell);
	clearKeyboard();

	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's home phone number: ");
		scanf("%11[^\n]", phonenumber->home);
		clearKeyboard();
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's business phone number: ");
		scanf("%11[^\n]", phonenumber->business);
		clearKeyboard();
	}
}



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(struct Contact* contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}