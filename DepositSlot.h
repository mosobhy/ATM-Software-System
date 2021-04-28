// DepositSlot.h

#ifndef DEPOSIT_SLOT_H
#define DEPOSIT_SLOT_H

#include <iostream>

using namespace std;

class DepositSlot {

    public:
        /*
        In a real world ATM, we have a sencor that check if there is a recieved 
        envlop or not, but in this system, i am going to simulate this idea via
        generating a random value for this boolean type
        */
       bool isEnvelopReceived() const;
};

#endif