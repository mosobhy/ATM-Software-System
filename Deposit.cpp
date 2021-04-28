// Deposit.h implementaion
#include "Deposit.h"
#include <iostream>

using namespace std;

static const int CANCELLED = 7;

Deposit::Deposit(int accountNumber, Screen screen, BankDatabase bank, KeyPad keypad
    ,DepositSlot slot)
    :Transaction(accountNumber, screen, bank),
    keypad(keypad),
    slot(slot)
{
    // empty constructor
}

void Deposit::execute() {

    // prompt to enter the envelop into the deposit slot
    Screen &screen = getScreen();

    bool transactionDone = false;
    bool envelopeReceived = false;

    do {
        
        screen.displayMessageLine("Please, Enter your envlop into the slot!");
        envelopeReceived = slot.isEnvelopReceived();

        if (envelopeReceived) {
            
            // contact the bankdatabase
            BankDatabase &bank = getBankDatabase();
            amount = promptForAmount();
            
            if (amount == CANCELLED) {
                return;
            }

            bank.deposit(getAccountNumber(), amount);

            screen.displayMessageLine("Your Transaction succsseed");
            transactionDone = true;
            
        } else {

            screen.displayMessageLine("You did not pass the envelope");
        }
    }
    while (!transactionDone && !envelopeReceived);
}

double Deposit::promptForAmount() {

    Screen &screen = getScreen();
   
    screen.displayMessageLine("Please, State the amount in the envelope in CENTS or exit(7)");
    int input = keypad.getInput();

    if (input == CANCELLED) {
        return CANCELLED;
    }
    return static_cast<double> (input) / 100;
}