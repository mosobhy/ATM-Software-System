// CashDispenser.cpp

#include "CashDispenser.h"
#include <iostream>

using namespace std;

CashDispenser::CashDispenser():count(INITIAL_COUNT) { };    // set the count to 500 of 20$

bool CashDispenser::isSufficientCredit(int amount) {

    // check for the current count of the ATM
    int bills = amount / 20;
    if (count >= bills) {
        return true;
    }
    return false;
}

bool CashDispenser::dispenseCash(int amount) {

    // check for the current count
    bool avail_cash = isSufficientCredit(amount);

    if (avail_cash) {
        /*
        Here we are going to simulate the idea of despensing money just via
        decrementing the current count state of the Cash available in the ATM.
        */
        count -= (amount / 20);
        return true;
    }
    return false;
}