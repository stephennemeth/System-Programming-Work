#include "Board.h"
#include <iostream>

using namespace std;

Board::Board() {
    this->board = new char*[this->HEIGHT];
    for (int i = 0; i < this->HEIGHT; i++) {
        this->board[i] = new char[this->WIDTH];
    }

    for (int i = 0; i < this->HEIGHT; i++) {
        for (int j = 0; j < this->WIDTH; j++) {
            this->board[i][j] = '_';
        }
    }

    for (int i = 0; i < this->WIDTH + 1; i++) {
        this->maxDepth[i] = this->HEIGHT - 1;
    }
    this->rounds = 0;
    this->leftMost = 1;
    this->won = 0;
}

void Board::printBoard() {
     for (int i = 0; i < this->HEIGHT; i++) {
        for (int j = 0; j < this->WIDTH; j++) {
            cout << "|" << this->board[i][j];
        }
        cout << '|' << endl;
    }
}

void Board::updateBoard(int choice, char token) {
     if (choice == -1) {
        choice = this->leftMost;
        cout << choice << endl;
    }
    int row = 0; int column = 0;
    row = this->maxDepth[choice - 1];
    column = choice - 1;
    this->board[row][column] = token;
    this->maxDepth[choice - 1]--;
    if (this->maxDepth[leftMost - 1] == -1) {
        this->leftMost++;
    }
    this->rounds++;
    this->isWon(1, row, column, 1, 0, token);
    this->isWon(1, row, column, -1, 0, token);
    this->isWon(1, row, column, 0, 1, token);
    this->isWon(1, row, column, 0, -1, token);
    this->isWon(1, row, column, -1, 1, token);
    this->isWon(1, row, column, 1, -1, token);
    this->isWon(1, row, column, 1, 1, token);
    this->isWon(1, row, column, -1, -1, token);
    if (this->rounds == this->HEIGHT * this->WIDTH && !this->won) {
        this->won = 1;
        this->printBoard();
        cout << "\nThe board is full, it is a draw!" << endl;
    }
}

void Board::setName(string p1, string p2) {
    this->p1Name = p1;
    this->p2Name = p2;
}

void Board::isWon(int count, int row, int column, int rowStep, int colStep, char token) {
    row += rowStep;
    column += colStep;
    if (row < 0 || row > this->HEIGHT - 1 || column < 0 || column > this->WIDTH - 1 || this->board[row][column] != token) {
        return;
    } else {
        count++;
    }
    if (count == 4) {
        this->won = 1;
        this->printBoard();
        string winner = token == 'X' ? this->p1Name : this->p2Name;
        cout << "\n" << winner << " Connected Four and Wins!" << endl;
        return;
    } else {
        this->isWon(count, row, column, rowStep, colStep, token);
    }
}

int Board::getWon() {
    return this->won;
}

Board::~Board() {
    for (int i = 0; i < this->HEIGHT; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
    delete[] this->maxDepth;
}
