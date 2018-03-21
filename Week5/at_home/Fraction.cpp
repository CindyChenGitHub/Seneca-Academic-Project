/**********************************************************
// Workshop 5: operator overloading
// File:Fraction.cpp
// Date: 2018/03/05
// Student: Cindy Chen
// Description: At home_B
**********************************************************/

// TODO: insert header files
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Fraction.h"

// TODO: continue the namespace
using namespace std;
using namespace sict;
namespace sict {

    // TODO: implement the default constructor
    Fraction::Fraction() {
        numerator_c = 0;
        denominator_c = 0;
    }
    // TODO: implement the two-argument constructor
    Fraction::Fraction(const int numerator, const int denominator) {
        if (numerator >= 0 && denominator > 0) {
            numerator_c = numerator;
            denominator_c = denominator;
            reduce();
        }
        else {
            *this = Fraction();
        }
    }
    // TODO: implement the max query
    int Fraction::max() const {
        if (numerator_c >= denominator_c)
            return numerator_c;
        else
            return denominator_c;
    }
    // TODO: implement the min query
    int Fraction::min() const {
        if (numerator_c <= denominator_c)
            return numerator_c;
        else
            return denominator_c;
    }
    // gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce() {
        int gcd = Fraction::gcd();
        numerator_c = numerator_c / gcd;
        denominator_c = denominator_c / gcd;
    }
    // TODO: implement the display query
    void Fraction::display() const {
        if (isEmpty())
            cout << "no fraction stored";
        else if (denominator_c == 1)
            cout << numerator_c;
        else
            cout << numerator_c << "/" << denominator_c;
    }
    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const {
        return numerator_c == 0 && denominator_c == 0;
    }
    // TODO: implement the + operator
    Fraction operator+ (const Fraction& rhs, const Fraction& lhs) {
        if ((rhs.denominator_c == 0) || (lhs.denominator_c == 0))
            return Fraction();
        else {
            int a = rhs.numerator_c;
            int b = rhs.denominator_c;
            int c = lhs.numerator_c;
            int d = lhs.denominator_c;
            int e = a*d + b*c;
            int f = b*d;
            return Fraction(e, f);
        }
    }
    // TODO: implement the * operator
    Fraction Fraction::operator* (const Fraction& rhs) const {
        if ((this->denominator_c == 0) || (rhs.denominator_c == 0))
            return Fraction(0, 0);
        else {
            int a = this->numerator_c;
            int b = this->denominator_c;
            int c = rhs.numerator_c;
            int d = rhs.denominator_c;
            int e = a*c;
            int f = b*d;
            return Fraction(e, f);
        }
    }
    // TODO: implement the == operator
    bool operator== (const Fraction& rhs, const Fraction& lhs) {
        if ((rhs.denominator_c == 0) || (lhs.denominator_c == 0)){
            Fraction();
            return false;
        }
        else if ((rhs.numerator_c / rhs.denominator_c == lhs.numerator_c / lhs.denominator_c) && (rhs.numerator_c % rhs.denominator_c == lhs.numerator_c % lhs.denominator_c))
            return true;
        else
            return false;
    }
    // TODO: implement the != operator
    bool operator!= (const Fraction& rhs, const Fraction& lhs) {
        if ((rhs.denominator_c == 0) || (rhs.denominator_c == 0)){
            Fraction();
            return false;
        }
        else if ((rhs.numerator_c / rhs.denominator_c != lhs.numerator_c / lhs.denominator_c) || (rhs.numerator_c % rhs.denominator_c != lhs.numerator_c % lhs.denominator_c))
            return true;
        else
            return false;
    }
    // TODO: implement the += operator
    Fraction Fraction::operator+= (const Fraction& rhs) {
        if ((this->denominator_c == 0) || (rhs.denominator_c == 0))
            return Fraction(0, 0);
        else {
            int a = this->numerator_c;
            int b = this->denominator_c;
            int c = rhs.numerator_c;
            int d = rhs.denominator_c;
            int e = a*d + b*c;
            int f = b*d;
            *this=Fraction(e,f);
            return *this;
        }
    }
}
