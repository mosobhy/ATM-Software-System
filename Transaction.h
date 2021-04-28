// Transaction.h Abstract base class
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "BankDatabase.h"
#include "Screen.h"
#include <iostream>

using namespace std;

class Transaction {

    private:
        int accountNumber;
        Screen &screen;
        BankDatabase &bank;

    public:
        Transaction(int, Screen, BankDatabase);
        virtual ~Transaction() { };
        int getAccountNumber() const;
        Screen &getScreen() const;
        BankDatabase &getBankDatabase() const;

        // this method will be overriden in the child classes
        virtual void execute() = 0;
};

#endif