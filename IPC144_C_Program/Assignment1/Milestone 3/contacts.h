/********************************************************************** 
// ICP144 Assignment 1 
// File contacts.h
// Version 1.0 
// Date 2017/10/27 
// Author Cindy Chen 
//-------------------------------------------
//Assignment: 1
//Milestone:  3
/**********************************************************************/

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #2 here...
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #2 here...
	struct Numbers {
		char cell[21];
		char home[21];
		char business[21];
	};

// Structure type Contact declaration
// Place your code here...
	struct Contacts {
		struct Name name;
		struct Address address;
		struct Numbers numbers;
	};
