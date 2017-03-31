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

private:
    ///data members
    int width;  //board width
    int height; //board height
    char** grid;    //2D array
    vector<int> rows;   //keeping track of highest slot
};

#endif //CONNECTN_GAMEBOARD_H
