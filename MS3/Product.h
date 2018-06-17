#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'
#include <iostream>
#include <fstream>
#include "ErrorState.h"

namespace AMA {
    const int max_sku_length = 7;    // Maximum number of characters in a sku (stock keeping unit) 
    const int max_unit_length = 10; // Maximum number of characters in the units� descriptor for a product
    const int max_name_length = 75;  // Maximum number of characters in the user�s name descriptor for a product length
    const double tax_rate = 0.13;  // The current tax rate

    class Product {
        char c_type;
        char c_sku[max_sku_length + 1];
        char c_unit[max_unit_length +1];
        char* c_name;
        int c_qua_hand;
        int c_qua_need;
        double c_price_preTax;
        bool c_taxable;
        ErrorState c_errorState;
    protected:
        void name(const char* _name);
		void sku(const char* _sku);
		void unit(const char* _unit);

        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double price() const;
        double cost() const;
        void message(const char* _errorState);
        bool isClear() const;
    public:
        Product(char _type = 'N');
        Product(const char* _sku, const char* _name, const char _unit[], int _qua_hand = 0, bool _Taxable = true, double _price_preTax = 0.0, int _qua_need = 0);
        Product(const Product& _product);
        Product& operator= (const Product& _product);
        ~Product();
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear = true) const;
        std::istream& read(std::istream& is);
        bool operator == (const char* _sku) const;
        double total_cost() const;
        void quantity(int _qua_hand);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char* _sku) const;
        bool operator<(const Product& _product) const;
        int operator+=(int _unit_added);
    };
        std::ostream& operator<< (std::ostream& _cout, const Product& _product);
        std::istream& operator>> (std::istream& _cin, Product& _product);
        double operator+= (double& _cost, const Product& _product);
}
#endif