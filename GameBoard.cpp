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
    mWidth = 0;
    mHeight = 0;
    mGrid = NULL;
}


//---------------------------------------------------
//  GameBoard(char **g, int w, int h)
//
//  Purpose: Initializing constructor, sets mWidth,
//  mHeight, mGrid (2D char array) and mRows vector
//
//  Parameters: (none)
//
//  Returns: GameBoard object
//---------------------------------------------------
GameBoard::GameBoard(char **g, int w, int h) {
    mWidth = w;
    mHeight = h;
    mGrid = g;

    mRows.reserve((unsigned)mWidth);

    for(int i=0; i<mWidth; ++i)
        mRows.push_back(0);
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

    //delete the grid
    for(int j=0; j<mWidth; ++j)
        delete[] mGrid[j];
    delete[] mGrid;

    cout << "GameBoard DESTRUCTOR COMPLETE" << endl; ///testing
}


//---------------------------------------------------
//  printGrid()
//
//  Purpose: Prints out the current state of the
//  grid row by row from the top
//
//  Parameters: (none)
//
//  Returns: void
//---------------------------------------------------
void GameBoard::printGrid() {
    for (int j=(mHeight-1); j>=0; --j) {
        for(int i=0; i<mWidth; ++i)
            cout << mGrid[i][j] << " ";
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
    if((col < mWidth) && (mRows[col] < mHeight) ) {
        mGrid[col][mRows[col]] = c;
        mRows[col]++;

        return true;
    }
    else
        return false;
}


//---------------------------------------------------
//  getGrid()
//
//  Purpose: Accessor, returns pointer to the mGrid
//  2D array
//
//  Parameters: (none)
//
//  Returns: char**
//---------------------------------------------------
char** GameBoard::getGrid() {
    return mGrid;
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
    return mRows[col];
}

//---------------------------------------------------
//  getHeight()
//
//  Purpose: Accessor, returns the height of the 2D
//  array
//
//  Parameters: (none)
//
//  Returns: int
//---------------------------------------------------
int GameBoard::getHeight(){
    return mHeight;
}


//---------------------------------------------------
//  getWidth()
//
//  Purpose: Accessor, returns the width of the 2D
//  array
//
//  Parameters: (none)
//
//  Returns: int
//---------------------------------------------------
int GameBoard::getWidth(){
    return mWidth;
}