#include "HumanPlayer.h"
#include <iostream>
#include <string>

HumanPlayer::HumanPlayer() {
    setName();
}

void HumanPlayer::setName() {
    cout << "Please enter your name: ";
    cin >> this->name;
}

string HumanPlayer::getName() {
    return this->name;
}

int HumanPlayer::choose() {
    cout << this->getName() << "'s turn, Please enter an integer between 1 and 7: ";
    int choice;
    cin >> choice;
    return choice;
}

HumanPlayer::~HumanPlayer() {}

