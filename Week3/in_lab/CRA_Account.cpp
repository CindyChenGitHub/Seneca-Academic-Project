/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
// Student Name : Cindy Chen
// Date: 2018/02/05
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include "CRA_Account.h"
using namespace std;

namespace sict {
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if ((sin < min_sin) || (sin > max_sin)) {
			strcpy(familyNameCRA, "");
			strcpy(givenNameCRA, "");
			sinCRA = 0;
		}
		else {
			strcpy(familyNameCRA, familyName);
			strcpy(givenNameCRA, givenName);
			sinCRA = sin;
		}
	}

	bool CRA_Account::isEmpty() const {
		return ((sinCRA < min_sin) || (sinCRA > max_sin));
	}

	void CRA_Account::display() const {
		if (CRA_Account::isEmpty())
			cout << "Account object is empty!" << endl;
		else {
			cout << "Family Name: " << familyNameCRA << endl;
			cout << "Given Name : " << givenNameCRA << endl;
			cout << "CRA Account: " << sinCRA << endl;
		}
	}
}
