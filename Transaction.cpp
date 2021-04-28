
#include "Transaction.h"
#include <iostream>

using namespace std;

Transaction::Transaction(int accountNumber, Screen screen, BankDatabase bank)
    :accountNumber(accountNumber),
    screen(screen),
    bank(bank) {

        // empty constructor
}

int Transaction::getAccountNumber() const {
    
    return accountNumber;
}

Screen& Transaction::getScreen() const {

    return screen;
}

BankDatabase& Transaction::getBankDatabase() const {

    return bank;
}