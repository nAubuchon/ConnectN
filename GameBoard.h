//
// Created by NICK AUBUCHON on 3/28/17.
//

#ifndef CONNECTN_GAMEBOARD_H
#define CONNECTN_GAMEBOARD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GameBoard {
public:
    ///constructors
    GameBoard(int N, int width, int height);
    GameBoard(GameBoard* board);

    ///destructor
    ~GameBoard();

    ///member functions
    //general usage
    void printGrid();
    void printWins();   ///TESTING
    bool placePiece(char color, int column);
    bool checkWin(char color, int x, int y);
    bool checkVert(char player, int x, int y);
    bool checkHorz(char player, int x, int y);
    bool checkDiag1(char player, int x, int y);
    bool checkDiag2(char player, int x, int y);
    void setScore(char color, bool isScore, int x, int y);
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
    int getScore(char color);

private:
    ///data members
    int mN;          //winning number of lined up pieces
    int mWidth;  //board width
    int mHeight; //board height
    char** mGrid;    //2D array of placed pieces
    char** wins;    //2D array of winning slots
    vector<int> mRows;   //keeping track of highest slot
    int pieces; //the number of pieces placed onto the board
    bool full;  //if the board is full
    int bScore; //the number of "almost wins" for black
    int rScore; //the number of "almost wins" for red

};

#endif //CONNECTN_GAMEBOARD_H
