// the Account header file
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;

class Account {

    private:
        const int accountNubmer;
        int pin;
        double totalBalance;    // deposited + available
        double availableBalance;    // available for withdrawaing
    
    public:
        Account(int, int, double, double);
        int getAccountNumber();
        bool validatePin(int);  // pin as a parameter
        double getAvailableBalance();
        double getTotalBalance();
        void withdraw(double amount);
        void deposit(double amount);
};

#endif  // ACCOUNT