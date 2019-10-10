/**********************************************************
// Workshop 5: operator overloading
// File:Fraction.h
// Date: 2018/03/05
// Student: Cindy Chen
// Description: At home_B
**********************************************************/

// TODO: header file guard
#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_FRACTION_H

// TODO: create namespace
namespace sict {

    // TODO: define the Fraction class
    class Fraction {
        // TODO: declare instance variables 
        int numerator_c;
        int denominator_c;

        // TODO: declare private member functions

        int max() const;
        int min() const;
        void reduce();
        int gcd() const;

    public:
        // TODO: declare public member functions
        Fraction();
        Fraction(const int numerator, const int denominator);
        bool isEmpty() const;
        void display() const;
        // TODO: declare the + operator overload
        friend Fraction operator+ (const Fraction& rhs, const Fraction& lhs);
        Fraction operator* (const Fraction& rhs) const;
        friend bool operator== (const Fraction& rhs, const Fraction& lhs);
        friend bool operator!= (const Fraction& rhs, const Fraction& lhs);
        Fraction operator+= (const Fraction& rhs);
    };
}
#endif