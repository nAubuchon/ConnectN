//
// Created by nick on 3/13/17.
//

#ifndef CONNECTN_PLAYERAI_H
#define CONNECTN_PLAYERAI_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "GameBoard.h"

using namespace std;

class PlayerAI {
public:
    ///constructors
    PlayerAI();
    PlayerAI(bool isFirst, GameBoard* board);

    ///destructor
    ~PlayerAI();

    ///member functions
    int takeTurn(GameBoard* board);
    char getColor();

    char** copyGrid(int,int,char**);
	int minimax(GameBoard, int, int, int, int, bool);

private:
    ///data members
    char mColor;
    GameBoard* mBoardCopy;
	const int MAX_DEPTH = 6;
};

#endif //CONNECTN_PLAYERAI_H
