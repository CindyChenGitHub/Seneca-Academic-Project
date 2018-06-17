// Final Project Milestone 5
// Version 1.0
// Perishable.h
// -----------------------------------------------------------
//Student:  Yue Chen    Date: 2018-04-15
////////////////////////////////////////////////////////////////
#ifndef AMA_PERISHABLE_H_
#define AMA_PERISHABLE_H_
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'

#include <iostream>
#include <fstream>
#include "Product.h"
#include "Date.h"

using namespace std;
namespace AMA {
    //create a derived class, based by Product class.
    //
    class Perishable :public Product {  // run Product constructor first, then Perishable constructor.
        Date c_expiryDate;
    public:
        Perishable();           // Default constructor, set to safe empty state.
        std::fstream& store(std::fstream& file, bool newLine = true) const ;    // Get from file.
        std::fstream& load(std::fstream& file);                                 // Set to file.
        std::ostream& write(std::ostream& os, bool linear) const;               // display to output console.
        std::istream& read(std::istream& is);                                   // Get from input console.
        const Date& expiry() const;                                             // Return expiry date.
    };
}
#endif