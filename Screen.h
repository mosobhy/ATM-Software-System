// screen header file
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

using namespace std;

class Screen {

    public:
        void displayMessage(string message) const;
        void displayMessageLine(string message) const;
        void displayDollarAmount(int amount) const;
        
};

#endif