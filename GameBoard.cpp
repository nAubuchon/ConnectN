//
// Created by NICK AUBUCHON on 3/28/17.
//

#include "GameBoard.h"

using namespace std;

//---------------------------------------------------
//  GameBoard()
//
//  Purpose: Default Constructor
//
//  Parameters: (none)
//
//  Returns: GameBoard object
//---------------------------------------------------
GameBoard::GameBoard() {
    width = 0;
    height = 0;
    board = NULL;
}


//---------------------------------------------------
//  GameBoard(char **d, int w, int h)
//
//  Purpose: Initializing constructor, sets width,
//  height, board (2D char array) and rows vector
//
//  Parameters: (none)
//
//  Returns: GameBoard object
//---------------------------------------------------
GameBoard::GameBoard(char **b, int w, int h) {
    width = w;
    height = h;
    board = b;

    rows.reserve((unsigned)width);

    for(int i=0; i<width; ++i)
        rows.push_back(0);
}


//---------------------------------------------------
//  ~GameBoard()
//
//  Purpose: Destructor
//
//  Parameters: (none)
//
//  Returns: (none)
//---------------------------------------------------
GameBoard::~GameBoard() { // this may need some work
    cout << "GameBoard DESTRUCTOR STARTING" << endl; ///testing

    //then delete the board
    for(int j=0; j<width; ++j)
        delete[] board[j];
    delete[] board;

    cout << "GameBoard DESTRUCTOR COMPLETE" << endl; ///testing
}


//---------------------------------------------------
//  getBoard()
//
//  Purpose: Accessor, returns pointer to te
//  board 2D array
//
//  Parameters: (none)
//
//  Returns: char**
//---------------------------------------------------
char** GameBoard::getBoard() {
    return board;
}


//---------------------------------------------------
//  getRow(int col)
//
//  Purpose: Accessor, returns the highest open slot
//  in the specified column
//
//  Parameters:
//      int col -- the column to look at
//
//  Returns: int
//---------------------------------------------------
int GameBoard::getRow(int col) {
    return rows[col];
}


//---------------------------------------------------
//  printBoard()
//
//  Purpose: Prints out the current state of the
//  board row by row from the top
//
//  Parameters: (none)
//
//  Returns: void
//---------------------------------------------------
void GameBoard::printBoard() {
    for (int j=(height-1); j>=0; --j) {
        for(int i=0; i<width; ++i)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}


//---------------------------------------------------
//  placePiece(char p, int col)
//
//  Purpose: Places char c into the highest slot of
//  the chosen column (col).  Returns false if the
//  chosen column is full
//
//  Parameters:
//      char c -- the color of the piece to be placed
//
//      int col -- the chosen column
//
//  Returns: (none)
//---------------------------------------------------
bool GameBoard::placePiece(char c, int col) {
    if( (rows[col] < height) && (col <= width-1) ) {
        board[col][rows[col]] = c;
        rows[col]++;

        return true;
    }
    else
        return false;
}