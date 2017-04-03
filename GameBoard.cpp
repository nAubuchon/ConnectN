//
// Created by NICK AUBUCHON on 3/28/17.
//

#include "GameBoard.h"

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
    mN = 0;
    mWidth = 0;
    mHeight = 0;
    mGrid = NULL;
    pieces = 0;
    full = false;
}


//---------------------------------------------------
//  GameBoard(int width, int height)
//
//  Purpose: Initializing constructor, sets mWidth,
//  mHeight, mGrid (2D char array) and mRows vector
//
//  Parameters:
//      int N -- to specify the number of in-line
//      pieces achieves a win

//      int width -- the width of the array
//
//      int height -- the height of the array
//
//  Returns: GameBoard object
//---------------------------------------------------
GameBoard::GameBoard(int N, int width, int height) {
    mN = N;
    mWidth = width;
    mHeight = height;
    mGrid = createGrid(width, height);

    mRows.reserve((unsigned)width);

    for(int i=0; i<width; ++i)
        mRows.push_back(0);

    pieces = width*height;
    full = false;
}


//---------------------------------------------------
//  GameBoard(GameBoard* board)
//
//  Purpose: Copy Constructor
//
//  Parameters:
//      GameBoard* board -- the pointer to the item
//
//  Returns: GameBoard object
//---------------------------------------------------
GameBoard::GameBoard(GameBoard* board) {
    mN = board->getN();
    mWidth = board->getWidth();
    mHeight = board->getHeight();
    mGrid = copyGrid(mWidth, mHeight, board->getGrid());

    mRows.reserve((unsigned)mWidth);
    for(int i=0; i<mWidth; ++i)
        mRows.push_back(board->getRow(i));

    pieces = board->getPieces();
    full = board->isFull();
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
//  column or the whole grid is full, true otherwise.
//
//  Parameters:
//      char color -- the color of the piece to be placed
//
//      int column -- the chosen column
//
//  Returns: bool
//---------------------------------------------------
bool GameBoard::placePiece(char color, int column) {
    if(!full && (column < mWidth) && (mRows[column] < mHeight) ) {
        mGrid[column][mRows[column]] = color;
        mRows[column]++;
        pieces--;

        if(pieces<1)
            full = true;
        return true;
    }
    else
        return false;
}


//---------------------------------------------------
//  checkWin(char color, int x, int y)
//
//  Purpose: Checks if the most recently placed piece
//  results in a win in vertical, horizontal and
//  diagonal directions.  Returns 'true' if a win,
//  'false' if not.
//
//  Parameters:
//      char color -- the color of the placed piece
//
//      int x -- the horizontal location of the
//      placed piece
//
//      int y -- the vertical location of the
//      placed piece
//
//  Returns: bool
//---------------------------------------------------
bool GameBoard::checkWin(char color, int x, int y) {
    int count = 0;
    int i = 0;

    //------------Note--------------
    //  + : Up for y, Right for x
    //  - : Down for y, Left for x
    //------------------------------

    //check vertical down
    if (y >= mN-2) {
        //begin moving down (0,-1)
        for (i=1; i<mN; ++i) {
            if(y-i < 0)
                break;
            //break if no match on the piece below
            if (mGrid[x][y-i] != color)
                break;
            //increment the number of pieces in line
            count++;
        }

        // if the count is at least N-1, it is a win
        // (because we're not counting the placed piece)
        if(count >= mN-1)
            return true;
        else if(count==mN-2)
            setScore(color);
    }

    //if no completed counts, then reset
    count = 0;

    //check horizontal left, similar process
    if (x > 0) {
        //begin moving left (-1,0)
        for (i=1; i<mN; ++i) {
            if (x-i < 0)
                break;
            if (mGrid[x-i][y] != color) {
                if(count==mN-2 && mGrid[x-i][y]=='.')
                    setScore(color);
                break;
            }
            count++;
        }
        if (count >= mN-1)
            return true;
    }
    //check horizontal right, keeping value of count so far
    if(x < mWidth-1) {
        //begin moving right (+1,0)
        for (i=1; i<mN; ++i) {
            if (x+i > mWidth-1)
                break;
            if (mGrid[x+i][y] != color) {
                if(count==mN-2 && mGrid[x+i][y]=='.')
                    setScore(color);
                break;
            }
            count++;
        }
        if (count >= mN-1)
            return true;
    }

    //reset count
    count = 0;

    //check diagonal low left to high right
    if(y < mHeight-1 && x < mWidth-1) {
        //begin moving right and up (+1,+1)
        for (i=1; i<mN; ++i) {
            if (x+i>mWidth-1 || y+i>mHeight-1)
                break;
            if (mGrid[x+i][y+i] != color) {
                if(count==mN-2 && mGrid[x+i][y+i]=='.')
                    setScore(color);
                break;
            }
            count++;
        }
        if (count >= mN-1)
            return true;
    }
    //check diagonal high right to low left, keep count
    if(y>0 && x>0) {
        //begin moving left and down (-1,-1)
        for (i=1; i<mN; ++i) {
            if (x-i<0 || y-i<0)
                break;
            if (mGrid[x-i][y-i] != color) {
                if(count==mN-2 && mGrid[x-i][y-i]=='.')
                    setScore(color);
                break;
            }
            count++;
        }
        if (count >= mN-1)
            return true;
    }

    //reset count
    count = 0;

    //check diagonal high left to low right
    if( y>0 && x<(mWidth-1) ) {
        //begin moving right and down (+1,-1)
        for (i=1; i<mN; ++i) {
            if( (x+i)>mWidth-1 || (y-i)<0 )
                break;
            if (mGrid[x+i][y-i] != color) {
                if(count==mN-2 && mGrid[x+i][y-i]=='.')
                    setScore(color);
                break;
            }
            count++;
        }
        if (count >= mN-1)
            return true;
    }
    //check diagonal low right to high left
    if( y<(mHeight-1) && x>0 ) {
        //begin moving left and up (-1,+1)
        for (i=1; i<mN; ++i) {
            if(x-i<0 || y+i>mHeight-1)
                break;
            if (mGrid[x-i][y+i] != color) {
                if(count==mN-2 && mGrid[x-i][y+i]=='.')
                    setScore(color);
                break;
            }
            count++;
        }
        if (count >= mN-1)
            return true;
    }

    //if all the above failed, there was no win
    //so return false
    return false;
}


//---------------------------------------------------
//  setScore(char color)
//
//  Purpose: Mutator, increments the score for the
//  specified color
//
//  Parameters:
//      char color -- the color of the score to add
//
//  Returns: void
//---------------------------------------------------
void GameBoard::setScore(char color) {
    if(color=='B')
        bScore++;
    else if(color == 'R')
        rScore++;
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
    char** array = new char*[width];

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
    char** array = new char*[width];
    array = new char*[width];
    for (int i=0; i<width; ++i) {
        array[i] = new char[height];

        for (int j=0; j<height; ++j)
            array[i][j] = grid[i][j];
    }

    return array;
}


//---------------------------------------------------
//  getN()
//
//  Purpose: Accessor, returns the number of pieces
//  needed in line to win
//
//  Parameters: (none)
//
//  Returns: int
//---------------------------------------------------
int GameBoard::getN() {
    return mN;
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
//  getPieces()
//
//  Purpose: Accessor, returns the number of pieces
//  placed onto the board
//
//  Parameters: (none)
//
//  Returns: int
//---------------------------------------------------
int GameBoard::getPieces() {
    return pieces;
}


//---------------------------------------------------
//  getPieces()
//
//  Purpose: Accessor, returns the number of pieces
//  placed onto the board
//
//  Parameters: (none)
//
//  Returns: int
//---------------------------------------------------
bool GameBoard::isFull() {
    return full;
}


//---------------------------------------------------
//  getScore(char color)
//
//  Purpose: Accessor, returns the heuristic score
//  of the specified color
//
//  Parameters:
//      char color -- the color to analyze
//
//  Returns: int
//---------------------------------------------------
int GameBoard::getScore(char color) {
	if (color == 'B')
		return bScore;
	else if (color == 'R')
		return rScore;
}