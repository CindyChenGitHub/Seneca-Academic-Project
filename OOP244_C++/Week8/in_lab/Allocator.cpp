// -----------------------------------------------------------
//Student:  YC    Date: 2018-04-06
////////////////////////////////////////////////////////////////
#include <cstring>
#include "SavingsAccount.h" 

using namespace sict;
namespace sict {

	// define interest rate
	//
	double intRate = 0.05;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* _type, double _balance) {
		iAccount* acc = nullptr;
		if (_type[0] == 's' || _type[0] == 'S') {
			acc = new SavingsAccount(_balance, intRate);
		}
		return acc;
	}
}