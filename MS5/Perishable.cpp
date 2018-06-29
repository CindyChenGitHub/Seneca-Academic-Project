// Final Project Milestone 5
// Version 1.0
// Perishable.cpp
// -----------------------------------------------------------
//Student:  YC    Date: 2018-04-15
////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Perishable.h"
#include "Date.h"

using namespace std;
namespace AMA {
    // Default constructor, set to safe empty state and 'P' type.
    // Derive Perishable from Product base class.
    // Run Product('p') first, then Perishable(). When run Perishable(), it will go to run the Date() constructor.
    //
    Perishable::Perishable() : Product('P') {
    }

    // Get from file.
    //
    std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
        Product::store(file, !(newLine));
        // file.open(file,ios::in);     //// It has been opened and closed in tester.cpp. If open or the file here, the tester.cpp could not access it.
        file << ",";
        file << c_expiryDate;
        file << std::endl;
        // file.close();    // It has been opened and closed in tester.cpp. If open or close the file here, the tester.cpp could not access it.
        return file;
    }

    // Set to file.
    //
    std::fstream& Perishable::load(std::fstream& file) {
        Product::load(file);
        file >> c_expiryDate;
        return file;
    }

    // display to output console.
    //
    std::ostream& Perishable::write(std::ostream& os, bool linear) const {
        os.fill(' ');       // Set to fill with ' '(default, just ensure that).
        int t_errCode = c_expiryDate.errCode();     // get errCode.    

        // If it iserror state, will display error massage.
        //
        if (t_errCode != 0) {
            switch (t_errCode) {
            case 0:
                break;
            case 1:
                os << "Invalid Date Entry";
                break;
            case 2:
                os << "Invalid Year in Date Entry";
                break;
            case 3:
                os << "Invalid Month in Date Entry";
                break;
            case 4:
                os << "Invalid Day in Date Entry";
                break;
            }
        }

        // If it is not error state, will display Perishable object.
        //
        else {
            Product::write(os, linear);     // call Product write function.
                                            // after write Product, write others (expiryDate). 
            if (linear) {                   // inline fomate.
                os << c_expiryDate;
            }
            else {                          // line by line fomate.
                std::cout << std::endl << " Expiry date: ";
                os << c_expiryDate;
            }
        }
        return os;
    }

    // Get from input console.
    //
    std::istream& Perishable::read(std::istream& is) {

        Product::read(is);
        std::cout << " Expiry date (YYYY/MM/DD): ";
        is >> c_expiryDate;
        return is;
    }

    // Return expiry date.
    //
    const Date& Perishable::expiry() const {
        return c_expiryDate;
    }
}