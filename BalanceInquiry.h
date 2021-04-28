// BalanceInquiry.h
#ifndef BALANCE_INQUIRY_H
#define BALANCE_INQUIRY_H

#include "Transaction.h"
#include "KeyPad.h"
#include <iostream>

using namespace std;

class BalanceInquiry : public Transaction {

    private:
        KeyPad &keypad;
    
    public:
        BalanceInquiry(int, Screen, BankDatabase, KeyPad);
        virtual void execute();
};

#endif 