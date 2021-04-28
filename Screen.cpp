// screen displayMessage() implementation
#include "Screen.h"
#include <iostream>

using namespace std;

void Screen::displayMessage(string message) const {
    
    cout << message;
}

void Screen::displayMessageLine(string message) const {

    cout << message << endl;
}

void Screen::displayDollarAmount(int amount) const {

    cout << amount << " " << "$" << endl;
}