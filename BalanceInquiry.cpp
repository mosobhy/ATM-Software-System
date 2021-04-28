// BalanceInquiry.h implementation

#include "BalanceInquiry.h"
#include <iostream>

using namespace std;

BalanceInquiry::BalanceInquiry(int accountNumber, Screen screen, BankDatabase bank, 
    KeyPad keypad)
    :Transaction(accountNumber, screen, bank),
    keypad(keypad)
{
    // empty constructor
}

void BalanceInquiry::execute() {

    // get this user account total balance and available balance
    BankDatabase &bank = getBankDatabase();     // this is implemented in the Transaction.cpp
    Screen &screen = getScreen();
    KeyPad keypad;

    int currentAccountNumber = getAccountNumber();

    double totalBalance = bank.getTotalBalance(currentAccountNumber);
    double availableBalance = bank.getAvailableBalance(currentAccountNumber);

    screen.displayMessage("Your Total Balance: ");
    screen.displayDollarAmount(totalBalance);

    screen.displayMessage("Your Available Balance: ");
    screen.displayDollarAmount(availableBalance);
}

