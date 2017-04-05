//
// Created by nick on 3/13/17.
//

#ifndef CONNECTN_GAME_H
#define CONNECTN_GAME_H

#include <iostream>
#include "PlayerAI.h"
#include "PlayerHuman.h"
#include "GameBoard.h"

class Game {
public:
    ///constructors
    Game();
    Game(int N, bool playerFirst);

    ///destructor
    ~Game();

    ///member functions
    void playGame();
    bool isGameOver();
    void clearBoard();
    void displayBoard();

private:
    ///data members

    //board data
    GameBoard* mGameBoard; //the GameBoard object

    //players
    PlayerAI* mAI;
    PlayerHuman* mHuman;

    //other
    bool mGameOver;
    int lastPlayerMove;
};

#endif //CONNECTN_GAME_H
