// ATM.h implementaion
#include "ATM.h"
#include <iostream>

using namespace std;

enum manueOptoins { WITDRAWAL = 1, INQUIRY, DEPOSIT, EXIT };

ATM::ATM()
:userAuthenticated(false),
currentAccountNumber(0)
{
}

void ATM::run() {

    while (true) {

        while (!userAuthenticated) {

            screen.displayMessageLine("Welcom!");
            authenticateUser();
        } 
        
        performTransaction();
        // reset
        currentAccountNumber = 0;
        userAuthenticated = false;
        screen.displayMessageLine("Goodbye!...");
    }
}

// helper functions
int ATM::displayManuOfOptions() {

    screen.displayMessageLine("Please, Select transaction to start: ");
    screen.displayMessage("1 - Withdraw Cash");
    screen.displayMessage("2 - View My Balance");
    cout << endl;
    screen.displayMessage("3 - Deposit Funds");
    screen.displayMessage("4 - Exit");
    cout << endl;

    screen.displayMessage("Your choice: ");
    return keypad.getInput();
}

void ATM::authenticateUser() {

    bool is_authenticated = false;
    int pin = 0;

    screen.displayMessageLine("User Authentication");
    screen.displayMessage("Account Number: ");
    int accountNumber = keypad.getInput();

    cout << endl;
    screen.displayMessage("PIN: ");
    pin = keypad.getInput();

    // contact the database
    is_authenticated = bank.authenticateUser(accountNumber, pin);
    
    if (is_authenticated) {
        // change the state
        currentAccountNumber = accountNumber;
        userAuthenticated = true;

    } else {
        screen.displayMessageLine("Invalid AccountNumber or PIN");
    }
}

void ATM::performTransaction() {

    bool userExitted = false;
    // i have used this as pointer.. to allow the polymorphic behavior
    // for this object.. to be able to determine which execute() function to invoke
    // depending on the transaction type.. the execute() was pure virtual function
    Transaction *currentProcessingTransaction = NULL;

    while (!userExitted) {

        int choice = displayManuOfOptions();

        switch (choice) {

            case WITDRAWAL:
            case INQUIRY:
            case DEPOSIT:
                currentProcessingTransaction = createTransaction(choice);

                // execute the transacion
                currentProcessingTransaction->execute();

                // destroy the pointer
                delete currentProcessingTransaction;

            case EXIT:
                screen.displayMessageLine("Exitting the system...");
                userExitted = false;
                break;
            
            default:
                screen.displayMessageLine("Please, Select a vaild input");
            break;
        }
    }
}

Transaction *ATM::createTransaction(int type) {

    Transaction *temp = NULL;

    switch (type) {
        case WITDRAWAL:
            temp = new Withdrawal(currentAccountNumber, screen, bank,
                    cashDispenser, keypad );
            break;
        
        case INQUIRY:
            temp = new BalanceInquiry(currentAccountNumber, screen, bank, keypad);
            break;
        
        case DEPOSIT:
            temp = new Deposit(currentAccountNumber, screen, bank, keypad, slot);
            break;
    }
    return temp;
}

