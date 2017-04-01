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
    cout << "Deleting Everything" << endl;
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
//        displayBoard();

        //get the row where the piece "fell"
        row = mGameBoard->getRow(col) - 1;

        // If placed piece won the game, exit function
        if (mGameBoard->checkWin('B', col, row)) {
            cout << "Black Wins!" << endl;
            mGameOver = true;
            return;
        }

        //initiate AI's turn
        col = mAI->takeTurn(mGameBoard);

        //displayColumn
//        displayBoard();

        //get the row where the piece "fell"
        row = mGameBoard->getRow(col) - 1;

        // If placed piece won the game, exit function
        if (mGameBoard->checkWin('R', col, row)) {
            cout << "Red Wins!" << endl;
            mGameOver = true;
            return;
        }
    }
    // Same process, but with AI First
    else {
        col = mAI->takeTurn(mGameBoard);
//        displayBoard();
        row = mGameBoard->getRow(col) - 1;

        if(mGameBoard->checkWin('B', col, row)) {
            cout << "Black Wins!";
            mGameOver = true;
            return;
        }

        col = mHuman->takeTurn(mGameBoard);
//        displayBoard();
        row = mGameBoard->getRow(col) - 1;

        if(mGameBoard->checkWin('R', col, row)) {
            cout << "Red Wins!";
            mGameOver = true;
            return;
        }
    }
}


////---------------------------------------------------
////  checkWin(char color, int x, int y)
////
////  Purpose: Checks if the most recently placed piece
////  results in a win in vertical, horizontal and
////  diagonal directions.  Returns 'true' if a win,
////  'false' if not.
////
////  Parameters:
////      char color -- the color of the placed piece
////
////      int x -- the horizontal location of the
////      placed piece
////
////      int y -- the vertical location of the
////      placed piece
////
////  Returns: bool
////---------------------------------------------------
//bool Game::checkWin(char color, int x, int y) {
//    // temporary local variables
//    char** grid = mGameBoard->getGrid();
//    int width = mGameBoard->getWidth();
//    int height = mGameBoard->getHeight();
//
//    int count = 0;
//    int i = 0;
//
//    //------------Note--------------
//    //  + : Up for y, Right for x
//    //  - : Down for y, Left for x
//    //------------------------------
//
//    //check vertical down
//    if (y >= mN-1) {
//        //begin moving down (0,-1)
//        for (i=1; i<mN; ++i) {
//            if(y-i < 0)
//                break;
//            //break if no match on the piece below
//            if (grid[x][y-i] != color)
//                break;
//            //increment the number of pieces in line
//            count++;
//        }
//        // if the count is at least N-1, it is a win
//        // (because we're not counting the placed piece)
//        if(count >= mN-1)
//            return true;
//    }
//
//    //if no completed counts, then reset
//    count = 0;
//
//    //check horizontal left, similar process
//    if (x > 0) {
//        //begin moving left (-1,0)
//        for (i=1; i<mN; ++i) {
//            if (x-i < 0)
//                break;
//            if (grid[x-i][y] != color)
//                break;
//            count++;
//        }
//        if (count >= mN-1)
//            return true;
//    }
//    //check horizontal right, keeping value of count so far
//    if(x < mGameBoard->getWidth() -1) {
//        //begin moving right (+1,0)
//        for (i=1; i<mN; ++i) {
//            if (x+i > width-1)
//                break;
//            if (grid[x+i][y] != color)
//                break;
//            count++;
//        }
//        if (count >= mN-1)
//            return true;
//    }
//
//    //reset count
//    count = 0;
//
//    //check diagonal low left to high right
//    if(y < height-1 && x < width-1) {
//        //begin moving right and up (+1,+1)
//        for (i=1; i<mN; ++i) {
//            if (x+i>width-1 || y+i>height-1)
//                break;
//            if (grid[x+i][y+i] != color)
//                break;
//            count++;
//        }
//        if (count >= mN-1)
//            return true;
//    }
//    //check diagonal high right to low left, keep count
//    if(y>0 && x>0) {
//        //begin moving left and down (-1,-1)
//        for (i=1; i<mN; ++i) {
//            if (x-i<0 || y-i<0)
//                break;
//            if (grid[x-i][y-i] != color)
//                break;
//            count++;
//        }
//        if (count >= mN-1)
//            return true;
//    }
//
//    //reset count
//    count = 0;
//
//    //check diagonal high left to low right
//    if( y>0 && x<(width-1) ) {
//        //begin moving right and down (+1,-1)
//        for (i=1; i<mN; ++i) {
//            if( (x+i)>width-1 || (y-i)<0 )
//                break;
//            if (grid[x+i][y-i] != color)
//                break;
//            count++;
//        }
//        if (count >= mN-1)
//            return true;
//    }
//    //check diagonal low right to high left
//    if( y<(height-1) && x>0 ) {
//        //begin moving left and up (-1,+1)
//        for (i=1; i<mN; ++i) {
//            if(x-i<0 || y+i>height-1)
//                break;
//            if (grid[x-i][y+i] != color)
//                break;
//            count++;
//        }
//        if (count >= mN-1)
//            return true;
//    }
//
//    //if all the above failed, there was no win
//    //so return false
//    return false;
//}


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