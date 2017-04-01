//
// Created by NICK AUBUCHON on 3/28/17.
//

#ifndef CONNECTN_GAMEBOARD_H
#define CONNECTN_GAMEBOARD_H

#include <iostream>
#include <vector>

using namespace std;

class GameBoard {
public:
    ///constructors
    GameBoard();
    GameBoard(int N, int width, int height);
    GameBoard(GameBoard* board);

    ///destructor
    ~GameBoard();

    ///member functions
    //general usage
    void printGrid();
    bool placePiece(char color, int column);
    bool checkWin(char color, int x, int y);
    char** createGrid(int width, int height);
    char** copyGrid(int width, int height, char** grid);

    //accessors
    int getN();
    int getHeight();
    int getWidth();
    char** getGrid();
    int getRow(int column);
    int getPieces();
    bool isFull();

private:
    ///data members
    int mN;          //winning number of lined up pieces
    int mWidth;  //board width
    int mHeight; //board height
    char** mGrid;    //2D array
    vector<int> mRows;   //keeping track of highest slot
    int pieces; //the number of pieces placed onto the board
    bool full;
};

#endif //CONNECTN_GAMEBOARD_H
