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

private:
    ///data members
    char mColor;
    GameBoard* mBoardCopy;
};

#endif //CONNECTN_PLAYERAI_H
