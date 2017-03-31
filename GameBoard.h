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
    GameBoard(char**,int,int);

    ///destructor
    ~GameBoard();

    ///member functions
    char** getGrid();
    int getRow(int);
    void printGrid();
    bool placePiece(char, int);

    int getHeight();
    int getWidth();

private:
    ///data members
    int mWidth;  //board width
    int mHeight; //board height
    char** mGrid;    //2D array
    vector<int> mRows;   //keeping track of highest slot
};

#endif //CONNECTN_GAMEBOARD_H
