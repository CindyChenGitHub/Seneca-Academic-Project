/********************************************************************** 
// ICP144 Assignment 2 
// File contacts.h
// Version 1.0 
// Date 2017/12/08 
// Author Cindy Chen 
//-------------------------------------------
//Assignment: 2
//Milestone:  3
/**********************************************************************/
// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code here...
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration
// Place your code here...
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};


//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function prototypes below...             |
// +-------------------------------------------------+


// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name* fullname);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address* fulladress);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers* phonenumber);

// Get and store from standard input the values for a Contact
// Place your code here...
void getContact(struct Contact* contact);

// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_
