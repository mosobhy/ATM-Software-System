// BankDatabase.h implementaion
#include <iostream>
#include <vector>
#include "BankDatabase.h"
#include "Account.h"

#define DATABASE_SIZE 4

using namespace std;

BankDatabase::BankDatabase() {

    // create some account objects and push them to the vector
    Account account1(1111, 1999, 7501234.2345, 8000000.0);
    Account account2(1112, 1234, 12343.533, 453533.43);
    Account account3(1113, 6666, 90500.33, 100000.0);
    Account account4(1114, 2323, 43423.2, 750000.0);

    // push_back to the vector
    database.push_back(account1);
    database.push_back(account2);
    database.push_back(account3);
    database.push_back(account4);
}

Account *BankDatabase::getAccount(int accountNumber) {
    // search for in the database for an account with this number

    for (int i = 0; i < database.size(); i++) {
        if (database[i].getAccountNumber() == accountNumber ) {
            
            // return the reference of this account
            return &database[i];
        }
    }
    return NULL;
}

// public methods
bool BankDatabase::authenticateUser(int accountNumber, int pin) {
    // get this account and check for its pin
    Account * const currentAttemptAccount = getAccount(accountNumber);
    
    if (currentAttemptAccount != NULL)
        return currentAttemptAccount->validatePin(pin);
    
    return false;
}

double BankDatabase::getAvailableBalance(int accountNumber) {
    // get the account first and then retrieve its balance
    Account * const currentAccount = getAccount(accountNumber);

    return currentAccount->getAvailableBalance();
}

double BankDatabase::getTotalBalance(int accountNumber) {
    // get the account object and then retrieve its total
    Account * const currentAccount = getAccount(accountNumber);

    return currentAccount->getTotalBalance();
}

void BankDatabase::withdraw(int accountNumber, double amount) {
    // get the account object
    Account * const currentAccount = getAccount(accountNumber);
    
    if (currentAccount == NULL)
        return

    // subtract the amount from the available balance and total balance
    currentAccount->withdraw(amount);
}

void BankDatabase::deposit(int accountNumber, double amount) {

    Account * const currentAccount = getAccount(accountNumber);

    if (currentAccount == NULL) {
        return
    }

    currentAccount->deposit(amount); // deposit is another method implmented in the Account class
}

