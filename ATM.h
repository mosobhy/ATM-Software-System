// ATM.h 
#ifndef ATM_H
#define ATM_H

#include "BalanceInquiry.h"
#include "Deposit.h"
#include "Withdrawal.h"
#include "Transaction.h"
#include "Screen.h"
#include "KeyPad.h"
#include <iostream>

using namespace std;

class Transaction;

class ATM {

    private:
        bool userAuthenticated;
        int currentAccountNumber;
        BankDatabase bank;
        CashDispenser cashDispenser;    // to pass to the withdrawal transaction constuctor
        DepositSlot slot;               // to pass to the deposit transaction constructor
        Screen screen;
        KeyPad keypad;

        // helper functions
        int displayManuOfOptions();
        void authenticateUser();
        void performTransaction();
        Transaction *createTransaction(int type);

    public:
        ATM();
        void run();

};

#endif