
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account: public iAccount {
		double acc_balance;

	protected:
		double balance() const { return acc_balance; }

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
        Account(double _balance);
		
		// TODO: credit adds +ve amount to the balance 
        bool credit(double _addCredit);

		// TODO: debit subtracts a +ve amount from the balance
        bool debit(double _desDebit);
	};

	// TODO: add prototype for Allocator function
	iAccount* CreateAccount(const char* _type, double _balance);
}
#endif
