#include "Board.h"
#include "Player.h"
#include "SimpleComputerPlayer.h"
#include "HumanPlayer.h"
#include <iostream>
using namespace std;

/*
* Main entrance into the Program, handles command line arguments and creates the
* types of player objects based on the command line arguments. Creates a game board,
* and calls on each player object to choose a column to drop their respective token in.
* Once the game is won the, the loop breaks and a winning message is called or a message
* stating the game ended in a draw.
*/
int main(int argc, char * argv[]) {
   cout << "Let's Start a Game of Connect 4\n" << endl;
   Board * board = new Board;
   Player * curr; Player * p1; Player * p2; //creates three polymorphic player pointers, one for the current player and 2 point to the two players
   cout << "Player One, ";
   p1 = string(argv[1]) == "-h" ? (Player *) new HumanPlayer() : (Player *) new SimpleComputerPlayer(); //assigns p1 the approriate object type casted to a player pointer
   cout << "Player Two, ";
   p2 = string(argv[2]) == "-h" ? (Player *) new HumanPlayer() : (Player *) new SimpleComputerPlayer(); //assigns p2 the appropriate object type casted to a player pointer
   curr = p1;
   board->setName(p1->getName(), p2->getName());
   while(!board->getWon()) {
      char token = curr == p1 ? 'X' : 'O';
      board->printBoard();
      board->updateBoard(curr->choose(), token);
      curr = curr == p1 ? p2 : p1; //switches the player pointer to the other player that needs to go next
   }
   delete board; delete p1; delete p2; // calls destructors for all the new objects
}
