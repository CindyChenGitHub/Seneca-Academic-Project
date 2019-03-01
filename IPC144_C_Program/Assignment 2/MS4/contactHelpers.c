/********************************************************************** 
// ICP144 Assignment 2 
// File contactHelpers.c
// Version 1.0 
// Date 2017/12/08 
// Author Cindy Chen 
//-------------------------------------------
//Assignment: 2
//Milestone:  4
/**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contacts.h"
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5
#define DONE 1
#define NOTDONE 0


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)	// #### for avoiding I didn't input "enter", I developed this function ####
{
    char input;
    do
    {
        printf("(Press Enter to Continue)");
        input = getchar();
        if (input != '\n')clearKeyboard();
    } while (input != '\n');
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
        if ((intInRange < min) || (intInRange > max))
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
    } while ((intInRange < min) || (intInRange > max));
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
        {
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
    printf("Select an option:> ");
    return getIntInRange(0, 6);
    printf("\n");
}

// ContactManagerSystem:
void ContactManagerSystem(void)
{
    int size = MAXCONTACTS;
    int value = NOTDONE;
    struct Contact contact[MAXCONTACTS] =
    {
        {
            { "Rick","","Grimes" },
            { 11, "Trailer Park",0,"A7A 2J2", "King City" },
            { "4161112222", "4162223333", "4163334444" }
        },
        {
            { "Maggie", "R.", "Greene" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9051112222", "9052223333", "9053334444" }
        },
        {
            { "Morgan", "A.", "Jones" },
            { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
            { "7051112222", "7052223333", "7053334444" }
        },
        {
            { "Sasha","", "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555" }
        },
    };

    do
    {
        switch (menu())
        {
        case 1:
            printf("\n");
            displayContacts(contact, size);
            pause();
            printf("\n");
            break;
        case 2:
            printf("\n");
            addContact(contact, size);
            pause();
            printf("\n");
            break;
        case 3:
            printf("\n");
            updateContact(contact, size);
            pause();
            printf("\n");
            break;
        case 4:
            printf("\n");
            deleteContact(contact, size);
            pause();
            printf("\n");
            break;
        case 5:
            printf("\n");
            searchContacts(contact, size);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 6:
            printf("\n");
            sortContacts(contact, size);
            pause();
            printf("\n");
            break;
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            if (yes())
            {
                value = DONE;
                printf("\nContact Management System: terminated");
            }
            printf("\n");
            break;
        }
    } while (value != DONE);
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
    int needInput = NOTDONE;
    int i;

    while (needInput == NOTDONE)
    {
        scanf("%[^\n]", telNum);
        if (telNum[strlen(telNum) - 1] != '\n')clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
    //	needInput = DONE;
        if (strlen(telNum) != 10)
        {
            printf("Enter a 10-digit phone number: ");
            needInput = NOTDONE;
        }
        else
        {
            for (i = 0; i < 10; i++)
            {
                if ((telNum[i] < '0') || (telNum[i] > '9'))
                {
                    printf("Enter a 10-digit phone number: ");
                    needInput = NOTDONE;
                    i = 10;
                }
                else
                    needInput = DONE;
            }

        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contact[], int size, const char cellNum[])
{
    int done = NOTDONE;
    int index = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(contact[i].numbers.cell, cellNum) == 0)
        {
            index = i;
            i = size;
            done = DONE;
        }
    }
    if (done == NOTDONE) return -1;
    else return index;
}

// displayContactHeader
void displayContactHeader(void)
{
    int i;

    printf("+");
    for (i = 0; i < 77; i++, printf("-"));
    printf("+\n");

    printf("|");
    for (i = 0; i < 30; i++, printf(" "));
    printf("Contacts Listing");
    for (i = 0; i < 31; i++, printf(" "));
    printf("|\n");

    printf("+");
    for (i = 0; i < 77; i++, printf("-"));
    printf("+\n");
}

// displayContactFooter
void displayContactFooter(int number)
{
    int i;
    printf("+");
    for (i = 0; i < 77; i++, printf("-"));
    printf("+\n");
    printf("Total contacts: %d\n\n", number);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
    printf(" %s", contact->name.firstName);
    if (strlen(contact->name.middleInitial) > 0)
        printf(" %s", contact->name.middleInitial);
    printf(" %s\n", contact->name.lastName);

    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0)
        printf("Apt# %d, ", contact->address.apartmentNumber);
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contact[], int size)
{
    int footer = 0;
    int i;
    displayContactHeader();
    for (i = 0; i < size; i++)
    {
        if (strlen(contact[i].numbers.cell) > 0)
        {
            displayContact(&contact[i]);
            footer++;
        }
    }
    displayContactFooter(footer);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int size)
{
    int find = -1;
    char searchCellNum[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(searchCellNum);
    find = findContactIndex(contact, size, searchCellNum);
    if (find == -1)
        printf("*** Contact NOT FOUND ***\n");
    else
        printf("\n");
        displayContact(&contact[find]);
}

// addContact:
void addContact(struct Contact contact[], int size)
{
    int i;
    int index = NOTDONE;
    for (i = 0; i < size; i++)
    {
        if (strlen(contact[i].numbers.cell) == 0)
        {
            getContact(&contact[i]);
            printf("--- New contact added! ---\n");
            index = DONE;
            i = size;
        }
    }
    if (index == NOTDONE)
    {
        printf("*** ERROR: The contact list is full! ***\n");
    }
}

// updateContact:
void updateContact(struct Contact contact[], int size)
{
    int index;
    char updateCellNum[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(updateCellNum);
    index = findContactIndex(contact, size, updateCellNum);
    if (index == -1)printf("*** Contact NOT FOUND ***\n");
    else
    {
        printf("\nContact found:\n");
        displayContact(&contact[index]);
        printf("\n");
        clearContact(&contact[index]);
        printf("Do you want to update the name? (y or n): ");
        if (yes())
            getName(&contact[index].name);
        printf("Do you want to update the address? (y or n): ");
        if (yes())
            getAddress(&contact[index].address);
        printf("Do you want to update the numbers? (y or n): ");
        if (yes())
            getNumbers(&contact[index].numbers);
        printf("--- Contact Updated! ---\n");
    }
}

// deleteContact:
void deleteContact(struct Contact contact[], int size)
{
    int index;
    char updateCellNum[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(updateCellNum);
    index = findContactIndex(contact, size, updateCellNum);
    if (index == -1)printf("*** Contact NOT FOUND ***\n");
    else
    {
        printf("\nContact found:\n");
        displayContact(&contact[index]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes())
        {
            clearContact(&contact[index]);
            printf("--- Contact deleted! ---\n");
        }
    }
}

// sortContacts:
void sortContacts(struct Contact contact[], int size)
{
    printf("<<< Feature to sort is unavailable >>>");
}

void clearContact(struct Contact* contact)
{
    struct Contact contactClear = { { "", "", "" },{ '\0', "", '\0', "", "" },{ "", "", "" } };
    *contact = contactClear;
}