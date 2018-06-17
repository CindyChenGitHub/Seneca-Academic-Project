/**********************************************************
// Workshop 6 - Class with a Resource
// File: Contact.cpp
// Date: 2018/03/18
// Student: Cindy Chen
// Description: In lab
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"


using namespace std;
using namespace sict;

namespace sict {
    Contact::Contact() {
        c_name[0] = '\0';
        c_phoneNums = 0;
        c_nums = 0;
    }

    Contact::Contact(const char* name, const long long* phoneNum, const int nums) {
        bool valid = !(name == NULL || strcmp(name,"")==0||name[0] == '\0');
        if (valid) {
            strncpy(c_name, name, Max_Name - 1);
            c_name[Max_Name - 1] = '\0';

            int counter = 0;
            long long* phoneNums_ = nullptr;
            phoneNums_ = new long long[nums];

            for (int i = 0; i < nums; i++) {
                long long countryCode = phoneNum[i] / 10000000000;
                long long areaCode = (phoneNum[i] % 10000000000) / 10000000;
                long long number = phoneNum[i] % 10000000;
                bool ok = (countryCode > 0 && countryCode < 100) && areaCode > 100 && number > 1000000;
                if (ok) {
                    phoneNums_[counter] = phoneNum[i];
                    counter++;
                }
            }
            c_nums = counter;
            c_phoneNums = phoneNums_;
        }
        else {
            c_name[0] = '\0';
            c_phoneNums = 0;
            c_nums = 0;
        }
    }
    Contact::~Contact() {
    }

    bool Contact::isEmpty() const {
        return (c_name == NULL || strcmp(c_name, "") == 0 || c_name[0] == '\0');
    }

    void Contact::display() const {
        if (c_name == NULL || strcmp(c_name, "") == 0 || c_name[0] == '\0')
            cout << "Empty contact!" << endl;
        else {
            cout << c_name << endl;
            for (int i = 0; i < c_nums; i++) {
                long long  countryCode = c_phoneNums[i] / 10000000000;
                long long areaCode = (c_phoneNums[i] % 10000000000) / 10000000;
                long long number1 = (c_phoneNums[i] % 10000000) / 10000;
                long long number2 = (c_phoneNums[i] % 10000);
                cout.fill(' ');
                cout << "(+" << countryCode << ") " << areaCode << " " << number1 << "-";
                cout.width(4);
                cout.fill('0');
                cout << number2;
                cout.fill(' ');
                cout << endl;
            }
        }
    }
}
