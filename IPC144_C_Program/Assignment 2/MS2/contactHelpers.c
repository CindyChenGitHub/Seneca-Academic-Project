/********************************************************************** 
// ICP144 Assignment 2 
// File contactHelpers.c
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

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to continue)");
	clearKeyboard();
}

// getInt function definition goes here:
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

// getIntInRange function definition goes here:
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

// yes function definition goes here:
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

// menu function definition goes here:
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

// ContactManagerSystem function definition goes here:
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