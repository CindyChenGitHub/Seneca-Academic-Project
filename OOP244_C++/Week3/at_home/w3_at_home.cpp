/**********************************************************
// Workshop 3: Classes and Privacy
// w3_at_home.cpp
// Version 2.1
// 2017/09/09
// Chris Szalwinski
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
/**********************************************************
// Student Name : Cindy Chen
// Date: 2018/02/13
**********************************************************/

#include <iostream>
#include "CRA_Account.h"
using namespace std;
using namespace sict;

int main() {
    const int size = 1000;
    char familyName[size];
    char givenName[size];
    sict::CRA_Account myCRA;
    int sin;
    bool quit = false;
    if (sict::max_name_length + 1 > size) {
        cerr << "Increase size to value greater than "
            << sict::max_name_length + 1 << endl;
        return 1;
    }

    cout << "Canada Revenue Agency Account App" << endl
        << "=================================" << endl << endl;

    do {
        cout << "Please enter your family name: ";
        cin.getline(familyName, max_name_length);
        cout << "Please enter your given name: ";
        cin.getline(givenName, max_name_length);
        cout << "Please enter your social insurance number (0 to quit): ";
        cin >> sin;
        cin.ignore();
        if (sin != 0) {
            myCRA.set(familyName, givenName, sin);
            if (myCRA.isEmpty()) {
                cout << "Invalid input! Try again." << endl;
            }
            else {
                int year;
                double balance;
                do {
                    cout << "Please enter the year of your tax return (0 to quit): ";
                    cin >> year;
                    cin.ignore();
                    if (year != 0) {
                        cout << "Please enter the balance owing on your tax return (0 to quit): ";
                        cin >> balance;
                        cin.ignore();
                        myCRA.set(year, balance);
                    }
                } while (year != 0);
                quit = true;
            }
        }
        else {
            quit = true;
        }
    } while (!quit);
    cout << "----------------------------------------" << endl;
    cout << "Testing the display function" << endl;
    cout << "----------------------------------------" << endl;
    myCRA.display();
    cout << "----------------------------------------" << endl;

    return 0;
}
