//
// Created by NICK AUBUCHON on 3/28/17.
//

#ifndef CONNECTN_GAMEBOARD_H
#define CONNECTN_GAMEBOARD_H

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class GameBoard {
public:
    ///constructors
    GameBoard();
    GameBoard(int, int);
    GameBoard(GameBoard*);

    ///destructor
    ~GameBoard();

    ///member functions
    //general usage
    void printGrid();
    bool placePiece(char color, int column);
    char** createGrid(int width, int height);
    char** copyGrid(int width, int height, char** grid);

    //accessors
    char** getGrid();
    int getRow(int column);
    int getHeight();
    int getWidth();
	int getScore(char);

private:
    ///data members
    int mWidth;  //board width
    int mHeight; //board height
    char** mGrid;    //2D array
    vector<int> mRows;   //keeping track of highest slot
};

#endif //CONNECTN_GAMEBOARD_H
