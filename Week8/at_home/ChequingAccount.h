
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
    class ChequingAccount:public Account {
        double acc_tranFee;
        double acc_monFee;

    public:
        // TODO: constructor initializes account balance and transaction fee
        ChequingAccount(double _balance, double _tranFee, double __monFee);

        // TODDO: credit adds +ve amount to the balance
        bool credit(double _tranFee);

        // TODO: debit subtracts a +ve amount from the balance
        bool debit(double _monFee);

        // TODO: month end
        void monthEnd();

        // TODO: display inserts the account information into an ostream
        void display(std::ostream& oss) const;

    };
}
#endif
