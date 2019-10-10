// -----------------------------------------------------------
//Student:  YC    Date: 2018-04-06
////////////////////////////////////////////////////////////////
#include <iostream>
#include "SavingsAccount.h"

using namespace sict;
namespace sict {

    SavingsAccount::SavingsAccount(double _balance, double _intRate) :Account(_balance) {
        if (_intRate > 0) acc_intRate = _intRate;
        else acc_intRate = 0.0;
    }

    // TODO: perform month end transactions
    void SavingsAccount::monthEnd() {
        double rate = acc_intRate * balance();
        credit(rate);
    }

    // TODO: display inserts the account information into an ostream			
    void SavingsAccount::display(std::ostream& oss) const {
        std::cout << "Account type: Savings" << std::endl << "Balance: $";
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << balance() << std::endl;
        std::cout << "Interest Rate (%): ";
        std::cout << acc_intRate*100.00 << std::endl;
        std::cout.unsetf(std::ios::fixed);
        std::cout.precision(6);
    }
}

