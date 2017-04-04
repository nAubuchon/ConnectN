//
// Created by nick on 3/13/17.
//

#include "Game.h"

//---------------------------------------------------
//  Game()
//
//  Purpose: Default Constructor
//
//  Parameters: (none)
//
//  Returns: Game object
//---------------------------------------------------
Game::Game() {
    mGameBoard = NULL;
    mAI = NULL;
    mHuman = NULL;
    mGameOver = false;
}


//---------------------------------------------------
//  Game(int N, bool playerFirst)
//
//  Purpose: Initializing constructor, sets GameBoard
//  and Player objects
//
//  Parameters:
//      int N -- to specify the number of in-line
//      pieces achieves a win
//
//      bool playerFirst -- to specify whether the
//      human player goes first or not
//
//  Returns: Game object
//---------------------------------------------------
Game::Game(int N, bool playerFirst) {
    int width = (2*N) - 1;
    int height = (2*N) - 2;
    mGameBoard = new GameBoard(N, width, height);
    mAI = new PlayerAI(!playerFirst, mGameBoard);
    mHuman = new PlayerHuman(playerFirst, "Nick");
    mGameOver = false;
}


//---------------------------------------------------
//  ~Game()
//
//  Purpose: Destructor
//
//  Parameters: (none)
//
//  Returns: (none)
//---------------------------------------------------
Game::~Game() {
    //cout << "Deleting Everything" << endl;
//    mGameBoard->~GameBoard();
    delete mGameBoard;
    delete mAI;
    delete mHuman;
}


//---------------------------------------------------
//  playGame()
//
//  Purpose: Does a single turn for each player in
//  the order of "Black" first and "Red" second.
//  Receives the selected column number and after
//  each player's turn, checks if the piece resulted
//  in a winning condition for that player
//
//  Parameters: (none)
//
//  Returns: void
//---------------------------------------------------
void Game::playGame() {
    int col;
    int row;

    if(mGameBoard->isFull()) {
        mGameOver = true;
        return;
    }

    // Human First
    if(mHuman->getColor()=='B') {
        //initiate Human's turn
        col = mHuman->takeTurn(mGameBoard);

        //displayColumn
        displayBoard();

        //get the row where the piece "fell"
        row = mGameBoard->getRow(col) - 1;

        // If placed piece won the game, exit function
        if (mGameBoard->checkWin('B', false, col, row)) {
            cout << "Black Wins!" << endl;
            mGameOver = true;
            return;
        }
        //initiate AI's turn
        col = mAI->takeTurn(mGameBoard);

        //displayColumn
        displayBoard();

        //get the row where the piece "fell"
        row = mGameBoard->getRow(col) - 1;

        // If placed piece won the game, exit function
        if (mGameBoard->checkWin('R', true, col, row)) {
            cout << "Red Wins!" << endl;
            mGameOver = true;
            return;
        }
    }
    // Same process, but with AI First
    else {
        col = mAI->takeTurn(mGameBoard);
        displayBoard();
        row = mGameBoard->getRow(col) - 1;

        if(mGameBoard->checkWin('B', true, col, row)) {
            cout << "Black Wins!";
            mGameOver = true;
            return;
        }
        col = mHuman->takeTurn(mGameBoard);
        displayBoard();
        row = mGameBoard->getRow(col) - 1;

        if(mGameBoard->checkWin('R', false, col, row)) {
            cout << "Red Wins!";
            mGameOver = true;
            return;
        }
    }
}


//---------------------------------------------------
//  isGameOver()
//
//  Purpose: Return the mGameOver boolean value for
//  checking if game is over by a win or by a tie.
//  Returns 'true' if game is over, 'false' if not
//
//  Parameters: (none)
//
//  Returns: bool
//---------------------------------------------------
bool Game::isGameOver() {
    return mGameOver;
}


//---------------------------------------------------
//  clearBoard()
//
//  Purpose: Calls the GameBoard destructor and
//  allocates new GameBoard object for the mGameBoard
//  member
//
//  Parameters: (none)
//
//  Returns: void
//---------------------------------------------------
void Game::clearBoard() {
    int N = mGameBoard->getN();
    int height = mGameBoard->getHeight();
    int width = mGameBoard->getWidth();
    delete mGameBoard;

    mGameBoard = new GameBoard(N, width, height);
    mGameOver = false;
}


//---------------------------------------------------
//  displayBoard()
//
//  Purpose: Prints out the current state of the
//  board row by row from the top
//
//  Parameters: (none)
//
//  Returns: void
//---------------------------------------------------
void Game::displayBoard() {
    mGameBoard->printGrid();
}