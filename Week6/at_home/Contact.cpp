/**********************************************************
// Workshop 6 - Class with a Resource
// File: Contact.cpp
// Date: 2018/03/18
// Student: Cindy Chen
// Description: At home
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
        bool nameValid = !(name == NULL || strcmp(name, "") == 0 || name[0] == '\0');

        if (nameValid) {
            strncpy(c_name, name, Max_Name - 1);
            c_name[Max_Name - 1] = '\0';
            bool phoneValid = !(phoneNum == NULL || phoneNum[0] == '\0');
            if (phoneValid) {
                int counter = 0;
                long long* phoneNums_ = nullptr;
                phoneNums_ = new long long[nums];

                for (int i = 0; i < nums; i++) {
                    long long countryCode = phoneNum[i] / 10000000000;
                    long long areaCode = (phoneNum[i] % 10000000000) / 10000000;
                    long long number = phoneNum[i] % 10000000;
                    bool valid = (countryCode > 0 && countryCode < 100) && areaCode > 100 && number > 1000000;
                    if (valid) {
                        phoneNums_[counter] = phoneNum[i];
                        counter++;
                    }
                }
                c_nums = counter;
                c_phoneNums = phoneNums_;
            }
            else {
                c_nums = 0;
                c_phoneNums = nullptr;
            }
        }
        else {
            c_name[0] = '\0';
            c_phoneNums = 0;
            c_nums = 0;
        }
    }

    Contact::Contact(const Contact& contact) {
        strncpy(c_name, contact.c_name, Max_Name - 1);
        c_nums = contact.c_nums;
        if (contact.c_phoneNums != nullptr) {
            c_phoneNums = new long long[c_nums];
            for (int i = 0; i < c_nums; i++) c_phoneNums[i] = contact.c_phoneNums[i];
        }
        else c_phoneNums = nullptr;
    }

    Contact::~Contact() {
    }

    bool Contact::isEmpty() const {
        return (c_name == NULL || strcmp(c_name, "") == 0 || c_name[0] == '\0');
    }

    void Contact::display() const {
        if (c_name == NULL || strcmp(c_name, "") == 0 || c_name[0] == '\0')
            cout << "Empty contact!" << endl;
        else if (c_nums == 0) cout << c_name << endl;
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

    Contact& Contact::operator=(const Contact& contact_) {
        if (this != &contact_) {
            strncpy(c_name, contact_.c_name, Max_Name - 1);
            c_nums = contact_.c_nums;
            delete[]c_phoneNums;
            if (contact_.c_phoneNums != nullptr) {
                c_phoneNums = new long long[c_nums];
                for (int i = 0; i < c_nums; i++) c_phoneNums[i] = contact_.c_phoneNums[i];
            }
            else c_phoneNums = nullptr;
        }
        return *this;
    }

    Contact& Contact::operator+=(const long long newPhonenum) {
        long long countryCode = newPhonenum / 10000000000;
        long long areaCode = (newPhonenum % 10000000000) / 10000000;
        long long number = newPhonenum % 10000000;
        bool valid = (countryCode > 0 && countryCode < 100) && areaCode > 100 && number > 1000000;
        if (valid) {
            //Contact temp(c_name, nullptr, c_nums + 1);
            long long* temp_phoneNums = nullptr;
            temp_phoneNums = new long long[c_nums + 1];
            for (int i = 0; i < c_nums + 1; i++)
                if(c_phoneNums != nullptr) temp_phoneNums[i] = c_phoneNums[i];
            temp_phoneNums[c_nums] = newPhonenum;
            Contact temp(c_name,temp_phoneNums,c_nums+1);
            *this = temp;
        }
        return *this;
    }
}
