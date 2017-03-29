//
// Created by nick on 3/13/17.
//

#ifndef CONNECTN_PLAYERHUMAN_H
#define CONNECTN_PLAYERHUMAN_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "GameBoard.h"

using namespace std;

class PlayerHuman {
public:
    ///constructors
    PlayerHuman();
    PlayerHuman(string,bool);

    ///destructor
    ~PlayerHuman();

    ///member functions
    int takeTurn(GameBoard*);
    char getColor();
    string getName();

private:
    ///data members
    string name;
    char color;
};

#endif //CONNECTN_PLAYERHUMAN_H
