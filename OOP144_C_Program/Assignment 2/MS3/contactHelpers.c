/********************************************************************** 
// ICP144 Assignment 2 
// File contactHelpers.c
// Version 1.0 
// Date 2017/12/08 
// Author Cindy Chen 
//-------------------------------------------
//Assignment: 2
//Milestone:  3
/**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	int intValue;
	char newLine = 'x';
	while (newLine != '\n')
	{
		scanf("%d%c", &intValue, &newLine);
		if (newLine != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>:");
		}
	}
	return intValue;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int intInRange;
	do {
		intInRange = getInt();
		if ((intInRange < min) | (intInRange > max))
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
	} while ((intInRange < min) | (intInRange > max));
	return intInRange;
}


// yes:
int yes(void)
{
	int intValue;
	char charValue = 'x';
	char newLine = 'x';
	while (newLine != '\n')
	{
		scanf("%c%c", &charValue, &newLine);
		if (newLine != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else
			switch (charValue)
		{
			case'y':
			case'Y':
				intValue = 1;
				break;
			case'n':
			case'N':
				intValue = 0;
				break;
			default:
				newLine = 'x';
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
				break;
		}
	}
	return intValue;
}


// menu:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:>");
	return getIntInRange(0, 6);
}


// ContactManagerSystem:
void ContactManagerSystem(void)
{
	int value;
	do
	{
		switch (value = menu())
		{
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			if (yes())
			{
				value = 7;
				printf("\nContact Management System: terminated");
			}
			printf("\n");
			break;
		default:
			break;
		}
	} while (value != 7);
}

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[11])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void){

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int){

}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact*){

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact[], int){

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact[], int){

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact[], int){

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact[], int){

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact[], int){

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact[], int){

}