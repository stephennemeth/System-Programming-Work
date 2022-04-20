#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

/*
* An abstract class that serves
* as the base for other player classes
* consists of a constructor and virual methods
*/
class Player {
    protected:
        /*
        * String used to store the players name
        */
        string name;
    public:
        /*
        * Constructor used for the player objects
        */
        Player();
        /*
        * A virtual method used to return the players name
        */
        virtual string getName() = 0;
        /*
        * A virutal method used to set the players name
        */
        virtual void setName() = 0;
        /*
        * A virtual method used for the player to choose
        * which column to update
        */
        virtual int choose() = 0;
        /* 
        * A virtual deconstructor used to 
        * to deconstrut the player objects
        */
        virtual ~Player();
 };
#endif