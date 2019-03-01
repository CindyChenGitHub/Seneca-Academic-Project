/********************************************************************** 
// ICP144 Assignment 1 
// File cashRegister.c
// Version 1.0 
// Date 2017/10/06 
// Author Cindy Chen 
//-------------------------------------------
//Assignment: 1
//Milestone:  2
/**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS
#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


int main(void)
{
	// Declare variables here:
	struct Name fullname;
	struct Address fulladress;
	struct Numbers phonenumber;
	
	// Create a variable of type Contact and call it something self-describing like "contact"
	// - HINT: Be sure to initialize the values to 0 and empty C strings
	struct Contacts contact = { 0 };

	// Display the title
	title();

	// Call the Contact function getName to store the values for the Name member
	getName(&fullname);

	// Call the Contact function getAddress to store the values for the Address member
	getAddress(&fulladress);

	// Call the Contact function getNumbers to store the values for the Numbers member
	getNumbers(&phonenumber);

	// Display Contact summary details
	printf("\nContact Details\n---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", fullname.firstName);
	printf("Middle initial(s): %s\n", fullname.middleInitial);
	printf("Last name: %s\n\n", fullname.lastName);
	printf("Address Details\n");
	printf("Street number: %d\n", fulladress.streetNumber);
	printf("Street name: %s\n", fulladress.street);
	printf("Apartment: %d\n", fulladress.apartmentNumber);
	printf("Postal code: %s\n", fulladress.postalCode);
	printf("City: %s\n\n", fulladress.city);
	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n", phonenumber.cell);
	printf("Home phone number: %s\n", phonenumber.home);
	printf("Business phone number: %s\n", phonenumber.business);

	// Display Completion Message
	printf("\nStructure test for Contact using functions done!\n");

	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Wilma
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Dino
Please enter the contact's last name: Flintstone
Please enter the contact's street number: 100
Please enter the contact's street name: Bedrock
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 14
Please enter the contact's postal code: Z8Z 7R7
Please enter the contact's city: Markham
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 647-505-5555
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 905-222-3333
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-491-5050

Contact Details
---------------
Name Details
First name: Wilma
Middle initial(s): Dino
Last name: Flintstone

Address Details
Street number: 100
Street name: Bedrock
Apartment: 14
Postal code: Z8Z 7R7
City: Markham

Phone Numbers:
Cell phone number: 647-505-5555
Home phone number: 905-222-3333
Business phone number: 416-491-5050

Structure test for Contact using functions done!
*/
