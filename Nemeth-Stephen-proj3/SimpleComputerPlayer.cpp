#include "SimpleComputerPlayer.h"
#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

SimpleComputerPlayer::SimpleComputerPlayer() {
    setName();
}

string SimpleComputerPlayer::getName() {
    return this->name;
}
void SimpleComputerPlayer::setName() {
    this->name = this->NAME;
    cout << "Please enter your name: " << this->getName() << endl;
}

int SimpleComputerPlayer::choose() {
    cout << this->getName() << "'s turn, Please enter an integer between 1 and 7: ";
    return -1;
}

SimpleComputerPlayer::~SimpleComputerPlayer() {};

