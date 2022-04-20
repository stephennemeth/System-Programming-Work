#ifndef BOARD_H
#define BOARD_H
#include <string>

using namespace std;

/*
* This class represents the game board,
* which is a 2d char array represented by
* a double char pointer.
*/
class Board {
    /*The number of columns of the game board*/
    const int WIDTH = 7;
    /*The height of rows for the game board*/
    const int HEIGHT = 6;
    /* Number of rounds in the game*/
    int rounds;
    /*A integer representing the left most column to choose from*/
    int leftMost;
    /*A pointer to an array representing the maximum depth of each of the columns*/
    int * maxDepth = new int[this->WIDTH];
    /*A character double pointer to the array of character used for the gameboard*/
    char ** board = nullptr;
    /*Integer used to denote if the game is won or not*/
    int won;
    /*String representing player 1s name*/
    string p1Name;
    /*String representing player 2s name*/
    string p2Name;
    public:
        /*Constructor for a Board object, used to create the max depth array, intialize
        * the board array, set left most, and set won
        */
        Board();
        /*Prints the contents of the board to standard output*/
        void printBoard();
        /*Function used to update the board with the correct token
        * based on the choose() method found in the SimpleComputerPlayer and
        * HumanPlayer classes. Also calls the isWon() for all eight directions'
        * to see if the player has connected four
        */
        void updateBoard(int choice, char token);
        /*
        * A method that checks if the player has connected four. Starts at the
        * location the player just updated and goes in all eight adjacent directions
        * in a recursive depth first search. If the count is equal to 4 that means
        * the player has connected four and the game is won. A winning message is
        * displayed and won is update to 1 and the game is ended.
        */
        void isWon(int count, int row, int column, int rowStep, int colStep, char token);
        /*
        * Returns the contents of won
        */
        int getWon();
        /*
        * Sets the names of player 1 and player 2 for the winning messages
        */
        void setName(string p1, string p2);
        /*
        * A destructor for the Board object. Frees up all memory used for the
        * board char pointer and the maxDepth array
        */
        ~Board();
};
#endif
