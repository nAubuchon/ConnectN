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
    Game(int,bool);

    ///destructor
    ~Game();

    ///member functions
    void playGame();
    char** createGrid(int,int);
    bool checkWin(char,int,int);
    bool isGameOver();
    void clearBoard();
    void displayBoard();

private:
    ///data members

    //board data
    int N;          //winning number of lined up pieces
    GameBoard* connectN; //the GameBoard object

    //players
    PlayerAI* aemula;
    PlayerHuman* vos;

    //other
    bool gameOver;
};

#endif //CONNECTN_GAME_H
