#ifndef SIMPLECOMPUTERPLAYER_H
#define SIMPLECOMPUTERPLAYER_H
#include "Player.h"
#include "Board.h"
#include <string>

using namespace std;

/*
* A child class of Player and represents a
* player that chooses the left most column on the 
* game board every single turn and whose name is already
* predetermined by a string constant.
*/
class SimpleComputerPlayer : public Player {
    /*
    * A constant string for the name 
    * of the SimpleComputerPlayerClass
    */
    const string NAME = "Zoey";
    public:
        /*
        * A constructor for a SimpleComputerPlayer Object
        * calls setName() when invoked
        */
        SimpleComputerPlayer();
        /* 
        * Sets the name of this object to the
        * constant string NAME
        */
        void setName();
        /*
        * returns negative 1, which indicates to the updateBoard() method
        * found in Board.h, to choose the left most available column to
        * update the board
        */
        int choose();
        /*
        * Returns the name of this object
        */
        string getName();
        /*
        * A destructor for the SimpleComputerPlayer object
        */
        ~SimpleComputerPlayer();
};


#endif