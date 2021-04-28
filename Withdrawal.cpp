// Withdrawal.cpp

#include "Withdrawal.h"
#include <iostream>

using namespace std;

static const int CANCELLED = 7;

// constructor
Withdrawal::Withdrawal(int accountNubmer, Screen screen, BankDatabase bank
                    , CashDispenser cashDispenser, KeyPad keypad)
    // invoke the parent constructor to initilaize its members
    :Transaction(accountNubmer, screen, bank),
    cashDispenser(cashDispenser),
    keypad(keypad)
{

}

int Withdrawal::displayManueOfOptions() const {

    Screen screen = getScreen();
    KeyPad keypad;
    int amounts[] = {0, 20, 40, 60, 80, 100, 200};
    int choice = 0;

    while (choice == 0) {

        screen.displayMessageLine("Please, Select the amount: ");
        screen.displayMessage("1 - ");
        screen.displayMessage("20$");
        screen.displayMessage("\t");

        screen.displayMessage("2 - ");
        screen.displayMessage("40$");
        cout << endl;

        screen.displayMessage("3 - ");
        screen.displayMessage("60$");
        screen.displayMessage("\t");

        screen.displayMessage("4 - ");
        screen.displayMessage("80$");
        cout << endl;

        screen.displayMessage("5 - ");
        screen.displayMessage("100$");
        screen.displayMessage("\t");

        screen.displayMessage("6 - ");
        screen.displayMessage("200$");
        cout << endl;

        screen.displayMessage("7 - CANCEL");
        cout << endl;

        screen.displayMessage("Your choice: ");

        choice = keypad.getInput();

        switch(choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                choice =  amounts[choice];
                break;
            case CANCELLED:
                choice = CANCELLED;
                break;
            
            // otherwise
            default:
                screen.displayMessageLine("You Entered an Invalid Input....");
        }
    }
    return choice;
}

// override the execute() method
void Withdrawal::execute() {

    // prompt the user with a list of options
    Screen &screen = getScreen();

    bool transactionDone = false;
    bool cancelled = false;

    do {

        int userChoice = displayManueOfOptions();

        if (userChoice != CANCELLED) {
            // interact with database
            int requestedAmount = userChoice;
            BankDatabase &bank = getBankDatabase();     // this in the trasaction abstract class
            int currentAccountNumber = getAccountNumber();

            // check if the user's availableBalance suffice
            double availBalance = bank.getAvailableBalance(currentAccountNumber);

            if (availBalance >= requestedAmount) {

                // check if there is avalible cash in the ATM dispenser
                if (cashDispenser.isSufficientCredit(requestedAmount)) {

                    // withdraw the cash
                    bank.withdraw(currentAccountNumber, requestedAmount);

                    // dispense cash from the ATM
                    cashDispenser.dispenseCash(requestedAmount);

                    // prompt the user to take it
                    screen.displayMessageLine("Please take off your cash!");

                    transactionDone = true;

                } else {
                    screen.displayMessageLine("Sorry, We cannot serve your withdraw now!");
                }

            } else {
                screen.displayMessageLine("Your credit is not sufficient!");
            }

        } else {
            screen.displayMessageLine("Transaction Declined!");
            cancelled = true;
        }
    }

    while (!transactionDone && !cancelled);
}

