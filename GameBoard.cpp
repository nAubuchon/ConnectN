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
    wins = createGrid(width, height);

    mRows.reserve((unsigned)width);

    for(int i=0; i<width; ++i)
        mRows.push_back(0);

    pieces = width*height;
    full = false;
    bScore = 0;
    rScore = 0;
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
    wins = copyGrid(mWidth, mHeight, board->getGrid());

    mRows.reserve((unsigned)mWidth);
    for(int i=0; i<mWidth; ++i)
        mRows.push_back(board->getRow(i));

    pieces = board->getPieces();
    full = board->isFull();
    bScore = board->getScore('B');
    rScore = board->getScore('R');
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
    //delete the grid
    for(int j=0; j<mWidth; ++j) {
        delete[] mGrid[j];
        delete[] wins[j];
    }
    delete[] mGrid;
    delete[] wins;
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
    cout << "Gameboard:" << endl;
    for (int j=(mHeight-1); j>=0; --j) {
        for(int i=0; i<mWidth; ++i)
            cout << mGrid[i][j] << " ";
        cout << endl;
    }
}


void GameBoard::printWins() {
    cout << "Scores:" << endl;
    for (int j=(mHeight-1); j>=0; --j) {
        for(int i=0; i<mWidth; ++i)
            cout << wins[i][j] << " ";
        cout << endl;
    }
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
     if(!full && (column >= 0) && (column < mWidth) && (mRows[column] < mHeight) ) {
        mGrid[column][mRows[column]] = color;
        mRows[column]++;
        pieces--;

        if(pieces < 1)
            full = true;

        return true;
    }
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
bool GameBoard::checkWin(char player, int x, int y) {
    return checkVert(player, x,y) || checkHorz(player, x, y) || checkDiag1(player, x, y) || checkDiag2(player, x, y);
}


bool GameBoard::checkVert(char player, int x, int y) {
    //------------Note--------------
    //  + : Up
    //  - : Down
    //------------------------------

    int count = 1;
    int i = 1;

    //check vertical down
    if (y >= mN-2) {
        //begin moving down (0,-1)
        while (y-i >= 0 && i < mN) {
            if(mGrid[x][y-i]!=player)
                break;
            else
                count++;
            i++;
        }
        //if count1 is at least N, it's a win
        if(count >= mN) {
            setScore(player, false, x, y);
            return true;
        }
        //if there's now a setup for a win
        else if(count == mN-1 && y < mHeight-1)
            setScore(player, true, x, y+1);

        //if win blocked
        setScore(player, false, x, y);
    }

    return false;
}


bool GameBoard::checkHorz(char player, int x, int y) {
    //------------Note--------------
    //  + : Right
    //  - : Left
    //------------------------------

    int L = 1;
    int R = 1;
    int countScoreL = 0;
    int countScoreR = 0;
    bool emptySlotL = false;
    bool emptySlotR = false;
    int emptyLocL = x;
    int emptyLocR = x;
    bool moveL = true;
    bool moveR = true;
    char leftEnd = ' ';
    char rightEnd = ' ';

    while(moveL || moveR) {
        if(x-L<0 || L>3)
            moveL = false;
        if(x+R>mWidth-1 || R>3)
            moveR = false;

        if(moveL) {
            if(mGrid[x-L][y]==player) {
                countScoreL++;
                if(!emptySlotL)
                    leftEnd = player;
            }
            else if(mGrid[x-L][y]=='.') {
                if(!emptySlotL) {
                    emptyLocL = x-L;
                    emptySlotL = true;
                }
                else
                    moveL = false;
            }
            else
                moveL = false;
            L++;
        }

        if(moveR) {
            if(mGrid[x+R][y]==player) {
                countScoreR++;
                if(!emptySlotR)
                    rightEnd = player;
            }
            else if(mGrid[x+R][y]=='.') {
                if(!emptySlotR) {
                    emptyLocR = x+R;
                    emptySlotR = true;
                }
                else
                    moveR = false;
            }
            else
                moveR = false;
            R++;
        }
    }
    //if there's a win
    if(countScoreL + countScoreR + 1 >= mN && leftEnd!=' ' && rightEnd!=' ') {
        setScore(player, false, x, y);
        return true;
    }
    //if there's a potential win setup (score)
    if(emptySlotL || emptySlotR) {
        if(emptySlotL) {
            if(countScoreL + 1 == mN || countScoreL + countScoreR + 1 == mN-1)
                if(leftEnd==' ') {
                    if (rightEnd != ' ' && countScoreR+1 == mN-1)
                        setScore(player, true, emptyLocL, y);
                }
                else
                    setScore(player, true, emptyLocL, y);
        }

        if(emptySlotR) {
            if(countScoreR + 1 == mN - 1 || countScoreL + countScoreR + 1 == mN-1)
                if(rightEnd==' ') {
                    if(leftEnd!=' ' && countScoreL+1 == mN-1)
                        setScore(player, true, emptyLocR, y);
                }
                else
                    setScore(player, true, emptyLocR, y);
        }
    }

    setScore(player, false, x, y);

    return false;
}


bool GameBoard::checkDiag1(char player, int x, int y) {
    //------------Note--------------
    //  MoveL(-, -) : Left, Down
    //  MoveR(+, +) : Right, Up
    //------------------------------

    int L = 1;
    int R = 1;
    int countScoreL = 0;
    int countScoreR = 0;
    bool emptySlotL = false;
    bool emptySlotR = false;
    int emptyLocL_x = x;
    int emptyLocL_y = y;
    int emptyLocR_x = x;
    int emptyLocR_y = y;
    bool moveL = true;
    bool moveR = true;
    char leftEnd = ' ';
    char rightEnd = ' ';

    while(moveL || moveR) {
        if(x-L<0 || y-L<0 || L>3)
            moveL = false;
        if(x+R>mWidth-1 || y+R>mHeight-1 || R>3)
            moveR = false;

        if(moveL) {
            if(mGrid[x-L][y-L]==player) {
                countScoreL++;
                if(!emptySlotL)
                    leftEnd = player;
            }
            else if(mGrid[x-L][y-L]=='.') {
                if(!emptySlotL) {
                    emptyLocL_x = x-L;
                    emptyLocL_y = y-L;
                    emptySlotL = true;
                }
                else
                    moveL = false;
            }
            else
                moveL = false;
            L++;
        }

        if(moveR) {
            if(mGrid[x+R][y+R]==player) {
                countScoreR++;
                if(!emptySlotR)
                    rightEnd = player;
            }
            else if(mGrid[x+R][y+R]=='.') {
                if(!emptySlotR) {
                    emptyLocR_x = x+R;
                    emptyLocR_y = y+R;
                    emptySlotR = true;
                }
                else
                    moveR = false;
            }
            else
                moveR = false;
            R++;
        }
    }
    //if there's a win
    if(countScoreL + countScoreR + 1 >= mN && leftEnd!=' ' && rightEnd!=' ') {
        setScore(player, false, x, y);
        return true;
    }
    //if there's a potential win setup (score)
    if(emptySlotL || emptySlotR) {
        if(emptySlotL) {
            if(countScoreL + 1 == mN || countScoreL + countScoreR + 1 == mN-1)
                if(leftEnd==' ') {
                    if (rightEnd != ' ' && countScoreR+1 == mN-1)
                        setScore(player, true, emptyLocL_x, emptyLocL_y);
                }
                else
                    setScore(player, true, emptyLocL_x, emptyLocL_y);
        }

        if(emptySlotR) {
            if(countScoreR + 1 == mN - 1 || countScoreL + countScoreR + 1 == mN-1)
                if(rightEnd==' ') {
                    if(leftEnd!=' ' && countScoreL+1 == mN-1)
                        setScore(player, true, emptyLocR_x, emptyLocR_y);
                }
                else
                    setScore(player, true, emptyLocR_x, emptyLocR_y);
        }
    }

    setScore(player, false, x, y);

    return false;
}


bool GameBoard::checkDiag2(char player, int x, int y) {
    //------------Note--------------
    //  MoveL(-, +) : Left, Up
    //  MoveR(+, -) : Right, Down
    //------------------------------

    int L = 1;
    int R = 1;
    int countScoreL = 0;
    int countScoreR = 0;
    bool emptySlotL = false;
    bool emptySlotR = false;
    int emptyLocL_x = x;
    int emptyLocL_y = y;
    int emptyLocR_x = x;
    int emptyLocR_y = y;
    bool moveL = true;
    bool moveR = true;
    char leftEnd = ' ';
    char rightEnd = ' ';

    while(moveL || moveR) {
        if(x-L<0 || y+L>mHeight-1 || L>3)
            moveL = false;
        if(x+R>mWidth-1 || y-R<0 || R>3)
            moveR = false;

        if(moveL) {
            if(mGrid[x-L][y+L]==player) {
                countScoreL++;
                if(!emptySlotL)
                    leftEnd = player;
            }
            else if(mGrid[x-L][y+L]=='.') {
                if(!emptySlotL) {
                    emptyLocL_x = x-L;
                    emptyLocL_y = y+L;
                    emptySlotL = true;
                }
                else
                    moveL = false;
            }
            else
                moveL = false;
            L++;
        }

        if(moveR) {
            if(mGrid[x+R][y-R]==player) {
                countScoreR++;
                if(!emptySlotR)
                    rightEnd = player;
            }
            else if(mGrid[x+R][y-R]=='.') {
                if(!emptySlotR) {
                    emptyLocR_x = x+R;
                    emptyLocR_y = y-R;
                    emptySlotR = true;
                }
                else
                    moveR = false;
            }
            else
                moveR = false;
            R++;
        }
    }
    //if there's a win
    if(countScoreL + countScoreR + 1 >= mN && leftEnd!=' ' && rightEnd!=' ') {
        setScore(player, false, x, y);
        return true;
    }
    //if there's a potential win setup (score)
    if(emptySlotL || emptySlotR) {
        if(emptySlotL) {
            if(countScoreL + 1 == mN || countScoreL + countScoreR + 1 == mN-1)
                if(leftEnd==' ') {
                    if (rightEnd != ' ' && countScoreR+1 == mN-1)
                        setScore(player, true, emptyLocL_x, emptyLocL_y);
                }
                else
                    setScore(player, true, emptyLocL_x, emptyLocL_y);
        }

        if(emptySlotR) {
            if(countScoreR + 1 == mN - 1 || countScoreL + countScoreR + 1 == mN-1)
                if(rightEnd==' ') {
                    if(leftEnd!=' ' && countScoreL+1 == mN-1)
                        setScore(player, true, emptyLocR_x, emptyLocR_y);
                }
                else
                    setScore(player, true, emptyLocR_x, emptyLocR_y);
        }
    }

    setScore(player, false, x, y);

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
void GameBoard::setScore(char color, bool isScore, int x, int y) {
    char temp = wins[x][y];
    if(temp == '.') {
        if(isScore) {
            if (color == 'B')
                bScore += 1;
            else
                rScore += 1;
            wins[x][y] = color;
            //printWins();    ///TESTING
        }

        return;
    }
    else if(temp == color && !isScore) {
        if(color == 'B')
            bScore += 1000;
        else
            rScore += 1000;

        wins[x][y] = 'X';
        //printWins();    ///TESTING

        return;
    }
    else if(temp!= color && temp != 'X') {
        if(color == 'B')
            rScore -= 1;
        else
            bScore -= 1;
        wins[x][y] = 'X';
        //printWins();    ///TESTING

        return;
    }
    else {
        //printWins();    ///TESTING
        return;
    }
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
    if(color=='B')
        return bScore;
    else if(color == 'R')
        return rScore;

    return 0;
}