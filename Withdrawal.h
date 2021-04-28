// withdrawal.h
#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <iostream>
#include "Transaction.h"
#include "CashDispenser.h"
#include "KeyPad.h"

using namespace std;

class Withdrawal: public Transaction {

    private:
        int amount;
        CashDispenser &cashDispenser;
        KeyPad &keypad;

        // helper function
        int displayManueOfOptions() const;
    
    public:
        // accountNumber   we have inherited all these attrbutes' getter functions
        // screen
        // bank
        Withdrawal(int, Screen, BankDatabase, CashDispenser, KeyPad);
        virtual void execute();

};

#endif // #ifndef