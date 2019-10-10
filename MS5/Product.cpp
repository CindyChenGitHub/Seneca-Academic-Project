// Final Project Milestone 5
// Version 1.0
// Product.cpp
// -----------------------------------------------------------
//Student:  YC    Date: 2018-04-15
////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'

#define filename "ms3.txt"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"
#include "ErrorState.h"

using namespace std;
namespace AMA {
    // Set name
    void Product::name(const char* _name) {
        if (_name == nullptr) c_name = nullptr;         // If the incoming parameter holds the nullptr address, this function removes the name of the product, if any, from memory.
        else {                                          // Allocate dynamically memory to store name.
            c_name = new char[max_name_length + 1];     // Note: the "max_name_length" exclud the null byte.
            strncpy(c_name, _name, max_name_length + 1);
            c_name[max_name_length] = '\0';
        }
    }
    // Set sku
    void Product::sku(const char* _sku) {
        strcpy(c_sku, _sku);
    }
    // Set unit
    void Product::unit(const char* _unit) {
        strcpy(c_unit, _unit);
    }

    // return name pointer
    const char* Product::name() const {
        return c_name;
    }
    // return sku pointer
    const char* Product::sku() const {
        return c_sku;
    }
    // return unit pointer
    const char* Product::unit() const {
        return c_unit;
    }
    // return if taxable
    bool Product::taxed() const {
        return c_taxable;
    }
    // return preTax price
    double Product::price() const {
        return c_price_preTax;
    }
    // return cost
    double Product::cost() const {
        if (c_taxable)
            return c_price_preTax * (tax_rate + 1);
        else
            return c_price_preTax;
    }
    // set error message by receive a string pointer
    void Product::message(const char* _errorState) {
        c_errorState.message(_errorState);
    }
    // return if error state is clear (no error)
    bool Product::isClear() const {
        return (c_errorState.message() == nullptr);
    }

    // Default constructor, set to safe empty state. Default type is 'N'.
    //
    Product::Product(char _type) {
        c_type = _type;
        c_sku[0] = '\0';
        c_unit[0] = '\0';
        c_name = nullptr;
        c_qua_hand = 0;
        c_qua_need = 0;
        c_price_preTax = 0.00;
        c_taxable = false;
    }

    // Overloading seven argument constructor
    //
    Product::Product(const char* _sku, const char* _name, const char _unit[], int _qua_hand, bool _taxable, double _price_preTax, int _qua_need) {
        sku(_sku);      // call protected member function to set sku
        unit(_unit);    // call protected member function to set unit
        name(_name);    // call protected member function to set name
        c_qua_hand = _qua_hand;
        c_qua_need = _qua_need;
        c_price_preTax = _price_preTax;
        c_taxable = _taxable;
    }

    // Overloading constructor, set by receive reference of Product object.
    //
    Product::Product(const Product& _product) {
        if (_product.c_name != nullptr) {   // if received name is not empty, call protected member function to set name.
            name(_product.c_name);
        }
        sku(_product.c_sku);        // call protected member function to set sku
        unit(_product.c_unit);      // call protected member function to set unit
        c_qua_hand = _product.c_qua_hand;
        c_qua_need = _product.c_qua_need;
        c_price_preTax = _product.c_price_preTax;
        c_taxable = _product.c_taxable;
    }

    // copy function
    //
    Product& Product::operator= (const Product& _product) {
        if (this != &_product) {
            sku(_product.c_sku);        // call protected member function to set sku
            delete[] c_name;
            name(_product.c_name);      // call protected member function to set name
            unit(_product.c_unit);      // call protected member function to set unit
            c_price_preTax = _product.c_price_preTax;
            c_qua_hand = _product.c_qua_hand;
            c_qua_need = _product.c_qua_need;
            c_taxable = _product.c_taxable;
        }
        return *this;
    }

    // Destructor function
    //
    Product::~Product() {
        delete[] c_name;
    }

    // Get from file.
    //
    std::fstream& Product::store(std::fstream& file, bool newLine) const {
        // file.close();        // It has set open and clos in tester.cpp.
        // file.open();         // It has set open and clos in tester.cpp.
        // if (!(std::fopen))  std::cerr << "File is not open" << std::endl;    // It has set open and clos in tester.cpp.
        // else  std::cout << "File is open" << std::endl;                      // It has set open and clos in tester.cpp.
        file << c_type << ","
            << c_sku << ","
            << c_name << ","
            << c_unit << ","
            << c_taxable << ",";
        if (newLine)        // It needs fix to 2 decimal in Product tester.
            file << fixed << setprecision(2) << c_price_preTax << ",";
        else                // It doesn't need fix in Perishable tester.
            file << c_price_preTax << ",";
        file << c_qua_hand << "," << c_qua_need;
        if (newLine)        // It needs newline in Perishable tester.
            file << std::endl;
        // file.clear();    // It has set open and clos in tester.cpp.
        // file.close();    // It has set open and clos in tester.cpp.
        return file;
    }

    // Set to file.
    //
    std::fstream& Product::load(std::fstream& file) {
        char t_sku[max_sku_length];
        char t_unit[max_unit_length];
        char t_name[max_name_length];
        int t_qua_hand;
        int t_qua_need;
        double t_price_preTax;
        char t_inputTax;    // It would be receive char from input console.
        bool t_taxable;
        char* error = nullptr;
        ErrorState t_errorState;
        // file.open(filename, ios::in);    // It has set open and clos in tester.cpp.
        if (file.is_open()) {
            file.get(t_sku, max_sku_length, ',');
            file.ignore();
            file.get(t_name, max_name_length, ',');
            file.ignore();
            file.get(t_unit, max_unit_length, ',');;
            file.ignore();
            file.get(t_inputTax);
            file.ignore();
            file >> t_price_preTax;
            file.ignore();
            file >> t_qua_hand;
            file.ignore();
            file >> t_qua_need;
            file.ignore();
            // file.clear();        // It has set open and clos in tester.cpp
            // file.close();        // It has set open and clos in tester.cpp
            // t_taxable = (t_inputTax == '0') ? false : true ;      // It is not work.
            if (t_inputTax == '0') t_taxable = false;
            else  t_taxable = true;
            Product temp = Product(t_sku, t_name, t_unit, t_qua_hand, t_taxable , t_price_preTax, t_qua_need);
            if (error != nullptr) {
                temp.c_errorState.message(error);
            }
            *this = temp;
        }
        return file;
    }

    // display to output console.
    //
    std::ostream& Product::write(std::ostream& os, bool linear) const {
        if (c_errorState.message() != nullptr) {
            os << c_errorState;
        }
        else if (linear == true) {
            if (isEmpty()) {
                os << setw(max_sku_length) << "" << "|";
                os << setw(20) << "" << "|";
            }
            else {
                os << left << setw(max_sku_length) << c_sku << "|";
                os << left << setw(20) << c_name << right << "|";
            }
            os << setw(7) << fixed << setprecision(2) << cost() << "|";
            os.std::ios::unsetf(std::ios::fixed);
            os << setprecision(6);
            os << setw(4) << c_qua_hand << "|";

            if (c_unit[0] == '\0') {
                os << setw(10) << "" << "|";
            }
            else {
                os << setw(10) << left << c_unit << right << "|";
            }
            os << setw(4) << c_qua_need << "|";
        }
        else {
            os << " Sku: " << c_sku << std::endl;
            os << " Name (no spaces): " << c_name << std::endl;
            os << fixed << setprecision(2);
            os << " Price: " << c_price_preTax << std::endl;
            if (c_taxable == true)
                os << " Price after tax: " << cost() << std::endl;
            else
                os << " Price after tax: " << " N/A" << std::endl;
            os << " Quantity on Hand: " << c_qua_hand << " " << c_unit << std::endl;
            os << " Quantity needed: " << c_qua_need;
            os.std::ios::unsetf(std::ios::fixed);
            os << setprecision(6);
        }
        return os;
    }

    // Get from input console.
    //
    std::istream& Product::read(std::istream& is) {
        bool ok = true;
        char t_sku[max_sku_length + 1];
        char t_unit[max_unit_length + 1];
        char* t_name = nullptr;
        t_name = new char[max_name_length];
        bool t_taxable;
        double t_price_preTax = 0.00;
        int t_qua_hand;
        int t_qua_need;

        std::cout << " Sku: ";
        is.getline(t_sku, max_sku_length);
        std::cout << " Name (no spaces): ";
        is.getline(t_name, max_name_length);
        std::cout << " Unit: ";
        is >> t_unit;

        while (ok) {
            char inputTaxable;
            std::cout << " Taxed? (y/n): ";
            is >> inputTaxable;
            if ((inputTaxable == 'y') || (inputTaxable == 'Y') || (inputTaxable == 'n') || (inputTaxable == 'N')) {
                if (inputTaxable == 'y' || inputTaxable == 'Y')
                    t_taxable = true;
                else
                    t_taxable = false;
                break;
            }
            else {
                ok = false;
                is.setstate(std::ios::failbit);
                // std::cerr << " Only (Y)es or (N)o are acceptable";   // It will be required to output in tester.cpp, so doesn't need it here.
                message("Only (Y)es or (N)o are acceptable");
                break;
            }
        }

        while (ok) {
            std::cout << " Price: ";
            is >> t_price_preTax;

            if (is.fail()) {
                is.setstate(std::ios::failbit);
                // cerr << " Invalid Price Entry" << endl;      // It will be required to output in tester.cpp, so doesn't need it here.
                message("Invalid Price Entry");
                ok = false;
                break;
            }
            else {
                ok = true;
                break;
            }
            is.ignore(2000, '\n');
        }

        while (ok) {
            std::cout << " Quantity on hand: ";
            is >> t_qua_hand;
            if (is.fail()) {
                is.setstate(std::ios::failbit);
                //  cerr << " Invalid Quantity Entry" << endl;      // It will be required to output in tester.cpp, so doesn't need it here.
                message("Invalid Quantity Entry");
                ok = false;
                break;
            }
            else {

                ok = true;
                break;
            }
            is.ignore(2000, '\n');
        }

        while (ok) {
            std::cout << " Quantity needed: ";
            is >> t_qua_need;
            if (is.fail()) {
                is.setstate(std::ios::failbit);
                //   cerr << " Invalid Quantity Needed Entry" << endl;      // It will be required to output in tester.cpp, so doesn't need it here.
                message("Invalid Quantity Needed Entry");
                ok = false;
                break;
            }
            else {
                ok = true;
                break;
            }
        }
        is.ignore(2000, '\n');

        if (ok) {
            *this = Product(t_sku, t_name, t_unit, t_qua_hand, t_taxable, t_price_preTax, t_qua_need);
            c_errorState.clear();
        }
        return is;
    }

    // Helper Operator member funcation to compare object.
    //
    bool Product::operator == (const char* _sku) const {
        return (strcmp(_sku, c_sku) == 0) ? true : false;
    }

    // Member funcation to calculate total cost.
    //
    double Product::total_cost() const {
        double cost;
        if (c_taxable) cost = c_qua_hand * c_price_preTax*1.13;
        else cost = c_qua_hand * c_price_preTax;
        return cost;
    }

    // Member funcation to set quantity in hand.
    //
    void Product::quantity(int _qua_hand) {
        c_qua_hand = _qua_hand;
    }

    // Member funcation to return if object is empty.
    //
    bool Product::isEmpty() const {
        return (c_name[0] == '\0');
    }

    // Member funcation to return quantity in need.
    //
    int Product::qtyNeeded() const {
        return c_qua_need;
    }
    // Member funcation to return quantity in hand.
    //
    int Product::quantity() const {
        return c_qua_hand;
    }

    // Helper Operator member funcation to compare object.
    //
    bool Product::operator>(const char* _sku) const {
        return (strcmp(c_sku, _sku) > 0) ? true : false;
    }

    // Helper Operator member funcation to compare object.
    //
    bool Product::operator>(const iProduct& _iproduct) const {
        return strcmp(c_name, _iproduct.name()) > 0 ? true : false;
    }

    // Helper Operator member funcation to calculate.
    //
    int Product::operator+=(int _quaHand_added) {
        if (_quaHand_added > 0)  c_qua_hand += _quaHand_added;
        return c_qua_hand;
    }

    // Global helper funcation to write.
    //
    std::ostream& operator<< (std::ostream& os, const iProduct& _iproduct) {
        _iproduct.write(os, true);
        return os;
    }

    // Global helper funcation to read.
    //
    std::istream& operator>> (std::istream& is, iProduct& _iproduct) {
        _iproduct.read(is);
        return is;
    }

    // Global helper operator funcation to calculate.
    //
    double operator+= (double& _addValue, const iProduct& _iproduct) {
        _addValue += _iproduct.total_cost();
        return _addValue;
    }
}
