/**********************************************************
// Workshop 3: Classes and Privacy
// w3_at_home.cpp
// Student Name : Cindy Chen
// Date: 2018/02/12
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include "CRA_Account.h"
using namespace std;

namespace sict {
    void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
        if ((sin < min_sin) || (sin > max_sin) || familyName[0] == '\0' || givenName[0] == '\0') {
            strncpy(familyNameCRA, "", max_name_length);
            strncpy(givenNameCRA, "", max_name_length);
            sinCRA = 0;
            CRA_Account::numberYears = 0;
            for (int i = 0; i < max_yrs; i++) {
                CRA_Account::yearCRA[i] = 0;
                CRA_Account::balanceCRA[i] = 0;
            }
        }
        else {
            strncpy(familyNameCRA, familyName, max_name_length);
            strncpy(givenNameCRA, givenName, max_name_length);
            sinCRA = sin;
            CRA_Account::numberYears = 0;
            for (int i = 0; i < max_yrs; i++) {
                CRA_Account::yearCRA[i] = 0;
                CRA_Account::balanceCRA[i] = 0;
            }
        }
    }
    void CRA_Account::display() const {
        if (CRA_Account::isEmpty())
            cout << "Account object is empty!" << endl;
        else {
            cout << "Family Name: " << familyNameCRA << endl;
            cout << "Given Name : " << givenNameCRA << endl;
            cout << "CRA Account: " << sinCRA << endl;
            for (int i = 0; i < CRA_Account::numberYears; i++) {
                std::cout.precision(2);
                if (CRA_Account::balanceCRA[i] > 2)
                    cout << "Year (" << CRA_Account::yearCRA[i] << ") balance owing: " <<fixed<< CRA_Account::balanceCRA[i] << endl;
                else if (CRA_Account::balanceCRA[i] < -2)
                    cout << "Year (" << CRA_Account::yearCRA[i] << ") refund due: " <<fixed<< (-CRA_Account::balanceCRA[i]) << endl;
                else
                    cout << "Year (" << CRA_Account::yearCRA[i] << ") No balance owing or refund due!" << endl;
            }
        }
    }
    void CRA_Account::set(int year, double balance) {
        for (int i = 0; i < max_yrs; i++) {
            if (CRA_Account::yearCRA[i] == 0) {
                yearCRA[i] = year;
                balanceCRA[i] = balance;
                numberYears++;
                i = max_yrs;
            }
        }
    }
    bool CRA_Account::isEmpty()const {
        const int sinSize = 9;
        int sinArray[sinSize];
        int sin = CRA_Account::sinCRA;
        int sum = 0;
        int check = 0;
        if ((sin < min_sin) || (sin > max_sin))
            return true;
        else {
            for (int i = 0; i < sinSize; i++) {
                sinArray[sinSize - 1 - i] = sin % 10;
                sin = sin / 10;
            }
            for (int i = 1; i < sinSize; i += 2) {
                sinArray[i] += sinArray[i];
                sinArray[i] = sinArray[i] / 10 + sinArray[i] % 10;
            }
            for (int i = 0; i < sinSize - 1; i++)
                sum += sinArray[i];
            if (sum % 10 == 0)
                check = 0;
            else
                check = (sum / 10 + 1) * 10 - sum;
            return check != sinArray[sinSize - 1];
        }
    }
}

