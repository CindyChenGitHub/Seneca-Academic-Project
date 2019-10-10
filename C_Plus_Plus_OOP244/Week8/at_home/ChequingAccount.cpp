// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
    ChequingAccount::ChequingAccount(double _balance, double _tranFee , double _monFee ):Account( _balance) {
        if (_tranFee > 0) acc_tranFee = _tranFee;
        else acc_tranFee = 0.0;
        if (_monFee > 0) acc_monFee = _monFee;
        else acc_monFee = 0.0;
    }


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
    bool ChequingAccount::credit(double _tranAmount) {
        if (_tranAmount > 0.0) {
            Account::credit(_tranAmount);
            Account::debit(acc_tranFee);
            return true;
        }
        else
            return false;
    }



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
    bool ChequingAccount::debit(double _tranAmount) {
        if (_tranAmount > 0.0) {
            Account::debit(_tranAmount);
            Account::debit(acc_tranFee);
            return true;
        }
        else
            return false;
    }


	// monthEnd debits month end fee
	//
    void ChequingAccount::monthEnd() { debit(acc_monFee); }


	// display inserts account information into ostream os
	//
    void ChequingAccount::display(std::ostream& oss) const {
        std::cout << "Account type: Chequing"<< std::endl; 
        std::cout << "Balance: $";
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << balance() << std::endl;
        std::cout << "Per Transaction Fee: ";
        std::cout << acc_tranFee << std::endl;
        std::cout << "Monthly Fee: ";
        std::cout << acc_monFee << std::endl;
        std::cout.unsetf(std::ios::fixed);
        std::cout.precision(6);
    }
}