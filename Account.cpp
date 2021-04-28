// Account.h implmentation
#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(int acc_num, int pin, double availableBalance, double totalBalance) 
    :accountNubmer(acc_num),
    pin(pin),
    availableBalance(availableBalance),
    totalBalance(totalBalance)
{
    // i used member initializer list, cuz one of the class attributes is const
    // so i will leave the body empty
}

int Account::getAccountNumber() {
    return accountNubmer;
}

bool Account::validatePin(int pin) {

    return (this->pin == pin) ? true : false;
}

double Account::getAvailableBalance() {

    return availableBalance;
}

double Account::getTotalBalance() {
    
    return totalBalance;
}

void Account::withdraw(double amount) {

    availableBalance -= amount;
    totalBalance -= amount;
}

void Account::deposit(double amount) {

    totalBalance += amount;
}

