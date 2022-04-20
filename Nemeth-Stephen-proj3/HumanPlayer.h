#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include <string>

using namespace std;

/*
* A child class of player that represents a player
* controled by a human user, which is able to pick
* their own name for the object and choose which
* columns to play on the game board
*/
class HumanPlayer : public Player {
    public:
        /*
        * A constructor for the HumanPlayer objects
        * calls setName() when the constructor is invoked
        */
        HumanPlayer();
        /* 
        * Prompts the user for the name of this 
        * HumanPlayer object
        */
        void setName();
        /*
        * A method used for the player to choose which
        * column to update the game board.
        */
        int choose();
        /*
        * Returns the name of the player
        */
        string getName();
        /* 
        * A destructor for the player object
        */
        ~HumanPlayer();
};

#endif