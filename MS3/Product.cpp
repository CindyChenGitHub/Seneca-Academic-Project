
/////////////////////////////////////////////////////////////////
//Student:
//--------------------------------
//Name: Yue Chen    Date: 2018-04-9
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

using namespace std;

namespace AMA {
    void Product::name(const char* _name) {
        if (_name == nullptr) c_name = nullptr;
        else {
            c_name = new char[max_name_length + 1];
            strncpy(c_name, _name, max_name_length + 1);
            c_name[max_name_length] = '\0';
        }
    }
    void Product::sku(const char* _sku) {
        strcpy(c_sku, _sku);
    }
    void Product::unit(const char* _unit) {
        strcpy(c_unit, _unit);
    }
    const char* Product::name() const {
        return c_name;
    }
    const char* Product::sku() const {
        return c_sku;
    }
    const char* Product::unit() const {
        return c_unit;
    }
    bool Product::taxed() const {
        return c_taxable;
    }
    double Product::price() const {
        return c_price_preTax;
    }
    double Product::cost() const {
        if (c_taxable)
            return c_price_preTax * (tax_rate + 1);
        else
            return c_price_preTax;
    }
    void Product::message(const char* _errorState) {
        c_errorState.message(_errorState);
    }
    bool Product::isClear() const {
        return (c_errorState.message() == '\0');
    }
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
    Product::Product(const char* _sku, const char* _name, const char _unit[], int _qua_hand, bool _taxable, double _price_preTax, int _qua_need) {
        sku(_sku);
        unit(_unit);
        name(_name);
        c_qua_hand = _qua_hand;
        c_qua_need = _qua_need;
        c_price_preTax = _price_preTax;
        c_taxable = _taxable;
    }
    Product::Product(const Product& _product) {
        if (_product.c_name != nullptr) {
            name(_product.c_name);
        }
        strncpy(c_sku, _product.c_sku, max_sku_length - 1);
        strncpy(c_name, _product.c_name, max_name_length - 1);
        strncpy(c_unit, _product.c_unit, max_unit_length - 1);

        c_qua_hand = _product.c_qua_hand;
        c_qua_need = _product.c_qua_need;
        c_price_preTax = _product.c_price_preTax;
        c_taxable = _product.c_taxable;
    }
    Product& Product::operator= (const Product& _product) {
        if (this != &_product) {
            strcpy(c_sku, _product.c_sku);
            strcpy(c_unit, _product.c_unit);
            c_price_preTax = _product.c_price_preTax;
            c_qua_hand = _product.c_qua_hand;
            c_qua_need = _product.c_qua_need;
            c_taxable = _product.c_taxable;
            delete[] c_name;
            name(_product.c_name);
        }
        return *this;
    }

    Product::~Product() {
        delete[] c_name;
    }

    std::fstream& Product::store(std::fstream& file, bool newLine) const {
        file.open(filename, ios::out | ios::app);
        file << c_type  << ", "
            << c_name   << ", "
            << c_taxable << ", "
            << fixed << setprecision(2) << c_price_preTax << ", "
            << c_qua_hand << ", "
            << c_qua_need;
        if (newLine)
            file << std::endl;
        file.clear();
        file.close();
        return file;
    }

    std::fstream& Product::load(std::fstream& file) {
        char t_type;
        char t_sku[max_sku_length + 1];
        char t_unit[max_unit_length + 1];
        char* t_name = nullptr;
        int t_qua_hand;
        int t_qua_need;
        double t_price_preTax;
        bool t_taxable;
        ErrorState t_errorState;
        char* error = nullptr;

        file.open(filename, ios::in);
        if (file.is_open()) {
            while (file) {
                file >> t_type;
                file.ignore();
                file >> t_sku;
                file.ignore();
                file >> t_name;  
                file.ignore();
                file >> t_unit;
                file.ignore();
                file >> t_taxable;
                file.ignore();
                file >> t_price_preTax;
                file.ignore();
                file >> t_qua_hand;
                file.ignore();
                file >> t_qua_need;
                file.ignore();
                file.clear();
                file.close();
            }

            Product temp = Product(t_sku, t_name, t_unit, t_qua_hand, t_taxable != 0, t_price_preTax, t_qua_need);
            temp.c_type = t_type;
            if (error != nullptr) {
                temp.c_errorState.message(error);
            }
            *this = temp;
        }
        return file;
    }

    std::ostream& Product::write(std::ostream& os, bool linear) const {
        if (linear == true) {
            if (isEmpty()) {
                os << setw(max_sku_length) << "" << "|";
                os << setw(20) << "" << "|";
            }
            else {
                //os.setf(ios::left);
                os << left<<setw(max_sku_length) << c_sku << "|";
                os <<left<< setw(20) << c_name<<right << "|";
            }

            os << setw(7) << fixed << setprecision(2) << cost() << "|";
            os.std::ios::unsetf(std::ios::fixed);
            os << setprecision(6);
            os << setw(4) << c_qua_hand << "|";

            if (c_unit[0] == '\0') {

                os <<setw(10) << "" << "|";
            }
            else {
                os <<setw(10) <<left << c_unit <<right<< "|";
            }
            os << setw(4) << c_qua_need << "|" ;
        }
        else {
            os << std::endl << "Sku: " << c_sku << std::endl;
            os << std::endl << "Name (no spaces): " << c_name << std::endl;
            os << std::endl << "Price: " << c_price_preTax << std::endl;
            os << std::endl << "either of : " << std::endl;
            if (c_taxable == true)
                os << std::endl << "Price after tax: " << fixed << cost() << std::endl;
            else
                os << std::endl << "N/A" << std::endl;
            os << std::endl << "Quantity on hand: " << c_qua_hand << std::endl;
            os << std::endl << "Quantity needed: " << c_qua_need << std::endl;
        }
        return os;
    }
    std::istream& Product::read(std::istream& is) {
        bool ok = true;
        char t_sku[max_sku_length + 1];
        char t_unit[max_unit_length + 1];
        char* t_name = nullptr;
        t_name = new char[max_name_length];
        int t_qua_hand;
        int t_qua_need;
        double t_price_preTax = 0.00;
        bool t_taxable;

        std::cout << " Sku: ";
        is.getline(t_sku, max_sku_length);
        std::cout << " Name (no spaces): ";
        is.getline(t_name, max_name_length);
        std::cout << " Unit: ";
        is >> t_unit;

        do {
            char inputTaxable;
            std::cout << " Taxed? (y/n): ";
            is >> inputTaxable;
            if (is.fail()) {
                is.setstate(std::ios::failbit);
                c_errorState.message(" Only (Y)es or (N)o are acceptable");
                ok = false;
            }
            else {
                if (inputTaxable == 'y' || inputTaxable == 'Y')
                    t_taxable = true;
                else
                    t_taxable = false;
            }
        } while (ok == false);

        double input_price_preTax;
        std::cout << " Price: ";
        is >> input_price_preTax;
        if (is.fail()) {
            is.setstate(std::ios::failbit);
            cerr << " Invalid Price Entry" << endl;
            message(" Invalid Price Entry");
            ok = false;
        }
        else {
            t_price_preTax = input_price_preTax;
            ok = true;
        }
        is.clear();
        is.ignore(2000, '\n');

        std::cout << " Quantity on hand: ";
        is >> t_qua_hand;
        if (is.fail()) {
            is.setstate(std::ios::failbit);
            cerr << " Invalid Quantity Entry" << endl;
            message(" Invalid Quantity Entry");
            ok = false;
        }
        else {
            c_qua_hand = t_qua_hand;
            ok = true;
        }
        is.clear();
        is.ignore(2000, '\n');

        std::cout << " Quantity needed: "; 
        is >> t_qua_need;
        if (is.fail()) {
            is.setstate(std::ios::failbit);
            cerr << " Invalid Quantity Needed Entry" << endl;
            message(" Invalid Quantity Needed Entry");
            ok = false;
        }
        else {
            c_qua_need = t_qua_need;
            ok = true;
        }
        is.clear();
        is.ignore(2000, '\n');

        if (ok) {
            *this = Product(t_sku, t_name, t_unit, t_qua_hand, t_taxable, t_price_preTax, t_qua_need);
        }
        delete[] t_name;
        return is;
    }

    bool Product::operator == (const char* _sku) const {
        return (strcmp(_sku, c_sku) == 0) ? true : false;
    }

    double Product::total_cost() const {
        double cost;
        if (c_taxable) cost = c_qua_hand * c_price_preTax*1.13;
        else cost = c_qua_hand * c_price_preTax;
        return cost;
    }
    void Product::quantity(int _qua_hand) {
        c_qua_hand = _qua_hand;
    }
    bool Product::isEmpty() const {
        return (c_name[0] == '\0');
    }
    int Product::qtyNeeded() const {
        return c_qua_need;
    }
    int Product::quantity() const {
        return c_qua_hand;
    }
    bool Product::operator>(const char* _sku) const {
        return strcmp(c_sku, _sku) > 0 ? true : false;
    }
    bool Product::operator<(const Product& _product) const {
        return strcmp(c_name, _product.c_name) > 0 ? true : false;
    }
    int Product::operator+=(int _quaHand_added) {
        if (_quaHand_added > 0)  c_qua_hand += _quaHand_added;
        return c_qua_hand;
    }
    std::ostream& operator<< (std::ostream& _cout, const Product& _product) {
        _product.write(_cout);
        return _cout;
    }
    std::istream& operator>> (std::istream& _cin, Product& _product) {
        _product.read(_cin);
        return _cin;
    }
    double operator+= (double& _cost, const Product& _product) {
        _cost += _product.total_cost();
        return _cost;
    }
}