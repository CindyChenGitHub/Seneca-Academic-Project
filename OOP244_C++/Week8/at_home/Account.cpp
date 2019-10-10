// -----------------------------------------------------------
//Student:  YC    Date: 2018-04-06
////////////////////////////////////////////////////////////////
#include<iostream>
#include"iAccount.h"
#include"Account.h"
using namespace std;
using namespace sict;

namespace sict {

    // TODO: constructor initializes account balance, defaults to 0.0 
    Account::Account(double _balance = 0.0) {
        if (_balance > 0) acc_balance = _balance;
        else acc_balance = 0.0;
    }

    // TODO: credit adds +ve amount to the balance 
    bool Account::credit(double _addCredit) {
        if (_addCredit > 0.0) {
            acc_balance += _addCredit;
            return true;
        }
        else
            return false;
    }

    // TODO: debit subtracts a +ve amount from the balance
    bool Account::debit(double _desDebit) {
        if (_desDebit > 0.0) {
            acc_balance -= _desDebit;
            return true;
        }
        else
            return false;
    }

}