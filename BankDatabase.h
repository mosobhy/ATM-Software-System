// BankDatabase.h
// it will contain a vector of the available accounts in the database
#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

#include <iostream>
#include <vector>
#include "Account.h"

using namespace std;

class BankDatabase {
    
    private:
        vector<Account> database;
        Account *getAccount(int accountNumber); // helper function to use in public API
    
    public:
        // constructor
        BankDatabase();

        // actions
        bool authenticateUser(int accountNumber, int pin);
        double getAvailableBalance(int accountNumber) ; // search for the object with this number
        double getTotalBalance(int accountNumber);
        void withdraw(int accountNumber, double amount);
        void deposit(int accountNumber, double amount);
};

#endif