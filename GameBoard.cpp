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
//  GameBoard(int width, int height)
//
//  Purpose: Initializing constructor, sets mWidth,
//  mHeight, mGrid (2D char array) and mRows vector
//
//  Parameters:
//      int width -- the width of the array
//
//      int height -- the height of the array
//
//  Returns: GameBoard object
//---------------------------------------------------
GameBoard::GameBoard(int width, int height) {
    mWidth = width;
    mHeight = height;
    mGrid = createGrid(width, height);

    mRows.reserve((unsigned)width);

    for(int i=0; i<width; ++i)
        mRows.push_back(0);
}


//---------------------------------------------------
//  GameBoard(GameBoard* board)
//
//  Purpose: Copy Constructor
//
//  Parameters:
//      GameBoard* board -- pointer to the instance
//      to be copied
//
//  Returns: GameBoard object
//---------------------------------------------------
GameBoard::GameBoard(GameBoard* board) {
    mWidth = board->getWidth();
    mHeight = board->getHeight();
    mGrid = copyGrid(mWidth, mHeight, board->getGrid());

    mRows.reserve((unsigned)mWidth);

    for(int i=0; i<mWidth; ++i)
        mRows.push_back(board->getRow(i));
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
//  placePiece(char color, int column)
//
//  Purpose: Places char arg into the highest slot of
//  the chosen column.  Returns false if the chosen
//  column is full, otherwise returns true.
//
//  Parameters:
//      char color -- the color of the piece to be placed
//
//      int column -- the chosen column
//
//  Returns: bool
//---------------------------------------------------
bool GameBoard::placePiece(char color, int column) {
    if((column < mWidth) && (mRows[column] < mHeight) ) {
        mGrid[column][mRows[column]] = color;
        mRows[column]++;

        return true;
    }
    else
        return false;
}


//---------------------------------------------------
//  createGrid(int width, int height)
//
//  Purpose: Allocates and returns a pointer to new
//  memory for a 2D array of chars for the gameBoard
//  grid
//
//  Parameters:
//      int width -- the width of the grid
//
//      int height -- the height of the grid
//
//  Returns: char**
//---------------------------------------------------
char** GameBoard::createGrid(int width, int height) {
    // declare a pointer
    char** array = 0;

    //allocate memory for pointers
    array = new char*[width];

    //iterate the width
    for (int i=0; i<width; ++i) {
        //allocate memory for chars
        array[i] = new char[height];

        //iterate the height
        for (int j=0; j<height; ++j)
            //set default value
            array[i][j] = '.';
    }

    //return pointer to memory location of new array
    return array;
}


//---------------------------------------------------
//  copyGrid(int width, int height, char** grid)
//
//  Purpose: Allocates and returns a pointer to new
//  memory for a copy of the 2D array of chars for
//  the game grid
//
//  Parameters:
//      int width -- the width of the grid
//
//      int height -- the height of the grid
//
//      char** grid -- the 2D array to be copied
//
//  Returns: char**
//---------------------------------------------------
char** GameBoard::copyGrid(int width, int height, char** grid) {
    char** array = 0;

    array = new char*[height];

    for (int i=0; i<height; ++i) {
        array[i] = new char[width];

        for (int j=0; j<width; ++j)
            array[i][j] = grid[i][j];
    }

    return array;
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
//  getRow(int column)
//
//  Purpose: Accessor, returns the highest open slot
//  in the specified column
//
//  Parameters:
//      int column -- the column to look at
//
//  Returns: int
//---------------------------------------------------
int GameBoard::getRow(int column) {
    return mRows[column];
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
int GameBoard::getHeight() {
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
int GameBoard::getWidth() {
    return mWidth;
}

int GameBoard::getScore(char color) {
	return 0;
}