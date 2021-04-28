// Deposit.h
#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Transaction.h"
#include "DepositSlot.h"
#include "KeyPad.h"
#include <iostream>

using namespace std;

class Deposit : public Transaction {

    private:
        double amount;
        KeyPad &keypad;
        DepositSlot &slot;

        // helper function
        double promptForAmount();
    
    public:
        // accountNumber getter method
        // screen getter method
        // bankdatabase getter method
        Deposit(int, Screen, BankDatabase, KeyPad, DepositSlot);
        virtual void execute();

};

#endif