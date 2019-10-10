/**********************************************************
// Workshop 3: Classes and Privacy
// w3_at_home.h
// Student Name : Cindy Chen
// Date: 2018/02/12
**********************************************************/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
    const int max_name_length = 40;
    const int min_sin = 100000000;
    const int max_sin = 999999999;
    const int max_yrs = 4;
    class CRA_Account {
        char familyNameCRA[max_name_length];
        char givenNameCRA[max_name_length];
        int sinCRA;
        int yearCRA[max_yrs];
        double balanceCRA[max_yrs];
        int numberYears;
    public:
        void set(const char* familyName, const char* givenName, int sin);
        bool isEmpty() const;
        void display() const;
        void set(int year, double balance);
    };
}
#endif