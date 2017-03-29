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
    PlayerAI(bool,char**,int,int);

    ///destructor
    ~PlayerAI();

    ///member functions
    int takeTurn(GameBoard*);
    char getColor();
    char** copyGrid(int,int,char**);

private:
    ///data members
    char color;
    GameBoard* boardCopy;
};

#endif //CONNECTN_PLAYERAI_H
