// Final Project Milestone 5
// Version 1.0
// iProduct.h
// -----------------------------------------------------------
//Student:  YC    Date: 2018-04-15
////////////////////////////////////////////////////////////////
#ifndef AMA_IPRODUCT_H_
#define AMA_IPRODUCT_H_
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'
#include <iostream>
#include <fstream>
using namespace std;
namespace AMA {
    // an abstract interface class, contains only pure virtual functions to derived classes. 
    //
    class iProduct {
    public:
        virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
        virtual std::fstream& load(std::fstream& file) = 0;
        virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool operator == (const char* str) const = 0;
        virtual double total_cost() const = 0;
        virtual const char* name() const = 0;
        virtual void quantity(int _numIProduct) = 0;
        virtual int qtyNeeded() const = 0;
        virtual int quantity() const = 0;
        virtual int operator+= (int numAdded) = 0;
        virtual bool operator> (const iProduct&) const = 0;
    };

    //std::ostream& operator<< (std::ostream& os, const iProduct& _iproduct);     // Global function, has the same prototype in Product.h
    //std::istream& operator>> (std::istream& is, iProduct& _iproduct);           // Global function, has the same prototype in Product.h
    //double operator+= (double& _addValue, const iProduct& _iproduct);           // Global function, has the same prototype in Product.h
    
    iProduct* CreateProduct();      // in Allocator.cpp
    iProduct* CreatePerishable();   // in Allocator.cpp
}
#endif