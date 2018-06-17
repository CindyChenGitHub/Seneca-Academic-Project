#include <cstring>
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

using namespace sict;
namespace sict {

	// define interest rate
	//
	double intRate = 0.05;
    double transFee = 0.50;
    double monthlyFee = 2.00;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* _type, double _balance) {
		iAccount* acc = nullptr;
        if (_type[0] == 's' || _type[0] == 'S') {

            acc = new SavingsAccount(_balance, intRate);
        }
        else if (_type[0] == 'c' || _type[0] == 'C') {
            acc = new ChequingAccount(_balance, transFee, monthlyFee);
        }
        else
            acc = nullptr;
		return acc;
	}
}