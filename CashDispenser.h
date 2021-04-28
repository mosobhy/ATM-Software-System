// CashDispnser.h

#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H

#include <iostream>

using namespace std;

class CashDispenser {

    private:
        static const int INITIAL_COUNT = 500;  // class attribute to be copied into the count attribute each day
        int count;
    
    public:
        CashDispenser();    // this will be set to 500 bill of 20
        bool isSufficientCredit(int amount);
        bool dispenseCash(int amount);      // if the count suffice, decrement
};

#endif