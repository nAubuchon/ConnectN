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
    PlayerAI(bool isFirst, GameBoard* board, int depth);

    ///destructor
    ~PlayerAI();

    ///member functions
    int takeTurn(GameBoard* board, int playerChoice);
	int minimax(GameBoard *board, int alpha, int beta, int currentDepth, bool isMax, int lastChoice);

private:
    ///data members
    char mColor;
	char mPlayerColor;
    GameBoard* mBoardCopy;
    int mDepth;
    int branches;
};

#endif //CONNECTN_PLAYERAI_H
