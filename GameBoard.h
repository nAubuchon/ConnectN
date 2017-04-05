//
// Created by NICK AUBUCHON on 3/28/17.
//

#ifndef CONNECTN_GAMEBOARD_H
#define CONNECTN_GAMEBOARD_H

#include <iostream>
#include <string>
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
    void printScores();   ///TESTING
    bool placePiece(char color, int column);
    bool checkWin(char color, bool isAI, int x, int y);
    bool checkVert(char color, bool isAI, int x, int y);
    bool checkHorz(char color, bool isAI, int x, int y);
    bool checkDiag1(char color, bool isAI, int x, int y);
    bool checkDiag2(char color, bool isAI, int x, int y);
    void setScore(int score, char color, bool isAI, int x, int y);
    char** createGrid(int width, int height);
    char** copyGrid(int width, int height, char** grid);

    //accessors
    int getN();
    int getHeight();
    int getWidth();
    char** getGrid();
    int getRow(int column);
    int getSlots();
    bool isFull();
    int getScore();

private:
    ///data members
    int mN;          //winning number of lined up pieces
    int mWidth;  //board width
    int mHeight; //board height
    char** mGrid;    //2D array of placed pieces
    char** scores;    //2D array of winning slots
    vector<int> mRows;   //keeping track of highest slot
    int slots; //the number of pieces placed onto the board
    bool full;  //if the board is full
    int totalScore; //the number of "almost wins" for black

};

#endif //CONNECTN_GAMEBOARD_H
