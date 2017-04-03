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
    GameBoard(int, int, int);
    GameBoard(GameBoard*);

    ///destructor
    ~GameBoard();

    ///member functions
    //general usage
    void printGrid();
    bool placePiece(char color, int column);
    bool checkWin(char color, int x, int y);
    void setScore(char color);
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
	int getScore(char);

private:
    ///data members
    int mN;          //winning number of lined up pieces
    int mWidth;  //board width
    int mHeight; //board height
    char** mGrid;    //2D array
    vector<int> mRows;   //keeping track of highest slot
    int pieces; //the number of pieces placed onto the board
    bool full;  //if the board is full
    int rScore; //the number of "almost wins" for red
    int bScore; //the number of "almost wins" for black

};

#endif //CONNECTN_GAMEBOARD_H
