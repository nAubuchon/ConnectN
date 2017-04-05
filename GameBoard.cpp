//
// Created by NICK AUBUCHON on 3/28/17.
//

#include "GameBoard.h"


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
    scores = createGrid(width, height);

    mRows.reserve((unsigned)width);

    for(int i=0; i<width; ++i)
        mRows.push_back(0);

    slots = width*height;
    full = false;
    totalScore = 0;
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
    scores = copyGrid(mWidth, mHeight, board->getGrid());

    mRows.reserve((unsigned)mWidth);
    for(int i=0; i<mWidth; ++i)
        mRows.push_back(board->getRow(i));

    slots = board->getSlots();
    full = board->isFull();
    totalScore = board->getScore();
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
        delete[] scores[j];
    }
    delete[] mGrid;
    delete[] scores;
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
    for(int j=(mHeight-1); j>=0; --j) {
        for(int i=0; i<mWidth; ++i)
            cout << mGrid[i][j] << " ";
        cout << endl;
    }
    for(int i=0; i<mWidth; ++i)
        cout << i+1 << " ";
    cout << endl;
//    cout << "Score: " << totalScore << endl;
}


void GameBoard::printScores() {
//    cout << "Scores:" << endl;
//    for (int j=(mHeight-1); j>=0; --j) {
//        for(int i=0; i<mWidth; ++i)
//            cout << scores[i][j] << " ";
//        cout << endl;
//    }
    cout << "Score: " << totalScore << endl;
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
    if((column >= 0) && !full && (column < mWidth) && (mRows[column] < mHeight) ) {
        mGrid[column][mRows[column]] = color;
        mRows[column]++;
        slots--;

        if(slots<1)
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
bool GameBoard::checkWin(char player, bool isAI, int x, int y) {
    ///TESTING***********
//    bool poop = checkVert(player, isAI, x,y) || checkHorz(player, isAI, x, y)
//                || checkDiag1(player, isAI, x, y) || checkDiag2(player, isAI, x, y);
//
//    printScores();
//
//    return poop;
    ///TESTING***********
    return checkVert(player, isAI, x,y) || checkHorz(player, isAI, x, y)
           || checkDiag1(player, isAI, x, y) || checkDiag2(player, isAI, x, y);
}


bool GameBoard::checkVert(char player, bool isAI, int x, int y) {
    //------------Note--------------
    //  + : Up
    //  - : Down
    //------------------------------

    int score = 0;
    int i = 1;

    //begin moving down (0,-1)
    while (y-i >= 0 && i < mN) {
        if(mGrid[x][y-i]!=player)
            break;
        else
            score++;
        i++;
    }
    //if count1 is at least N, it's a win
    if(score + 1 >= mN) {
        setScore(1000, player, isAI, x, y);
        return true;
    }
        //if there's now a setup for a win
    else if(score + 1 == mN-1 && y < mHeight-1)
        setScore(100, player, isAI, x, y+1);

    if(score > 0)
        score = 1;

    //if there's a block or just a piece with nothing around it
    setScore(score, player, isAI, x, y);

    return false;
}


bool GameBoard::checkHorz(char player, bool isAI, int x, int y) {
    //------------Note--------------
    //  + : Right
    //  - : Left
    //------------------------------

    int L = 1;
    int R = 1;
    int inLineL = 0;
    int inLineR = 0;
    int scoreL = 0;
    int scoreR = 0;
    bool emptySlotL = false;
    bool emptySlotR = false;
    int emptyLocL = x;
    int emptyLocR = x;
    bool moveL = true;
    bool moveR = true;

    while(moveL || moveR) {
        if(x-L<0 || L>3)
            moveL = false;
        if(x+R>mWidth-1 || R>3)
            moveR = false;

        if(moveL) {
            if(mGrid[x-L][y]==player) {
                scoreL++;
                if(!emptySlotL)
                    inLineL++;
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
                scoreR++;
                if(!emptySlotR)
                    inLineR++;
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

    int score = inLineL + inLineR;

    //if there's a win
    if(inLineL + inLineR + 1 >= mN) {
        setScore(1000, player, isAI, x, y);
        return true;
    }//if there's two win setups (score)
    else if(emptySlotL && emptySlotR && score + 1 == mN-1) {
        setScore(100, player, isAI, emptyLocL, y);
        setScore(100, player, isAI, emptyLocR, y);
    }//if there's just one score
    else {
        //if there's just a score to the left
        if(scoreL + inLineR + 1 >= mN-1) {
            if(emptySlotL)
                setScore(100, player, isAI, emptyLocL, y);

        }//if there's just a score to the right
        if(scoreR + inLineL + 1 >= mN-1) {
            if(emptySlotR)
                setScore(100, player, isAI, emptyLocR, y);
        }
    }

    if(inLineL + inLineR > 0)
        score = 1;

    //if there's a block or just a piece with nothing around it
    setScore(score, player, isAI, x, y);

    return false;
}


bool GameBoard::checkDiag1(char player, bool isAI, int x, int y) {
    //------------Note--------------
    //  MoveL(-, -) : Left, Down
    //  MoveR(+, +) : Right, Up
    //------------------------------

    int L = 1;
    int R = 1;
    int inLineL = 0;
    int inLineR = 0;
    int scoreL = 0;
    int scoreR = 0;
    bool emptySlotL = false;
    bool emptySlotR = false;
    int emptyLocL_x = x;
    int emptyLocL_y = y;
    int emptyLocR_x = x;
    int emptyLocR_y = y;
    bool moveL = true;
    bool moveR = true;

    while(moveL || moveR) {
        if (x - L < 0 || y - L < 0 || L > 3)
            moveL = false;
        if (x + R > mWidth - 1 || y + R > mHeight - 1 || R > 3)
            moveR = false;

        if (moveL) {
            if (mGrid[x - L][y - L] == player) {
                scoreL++;
                if (!emptySlotL)
                    inLineL++;
            } else if (mGrid[x - L][y - L] == '.') {
                if (!emptySlotL) {
                    emptyLocL_x = x - L;
                    emptyLocL_y = y - L;
                    emptySlotL = true;
                } else
                    moveL = false;
            } else
                moveL = false;
            L++;
        }

        if (moveR) {
            if (mGrid[x + R][y + R] == player) {
                scoreR++;
                if (!emptySlotR)
                    inLineR++;
            } else if (mGrid[x + R][y + R] == '.') {
                if (!emptySlotR) {
                    emptyLocR_x = x + R;
                    emptyLocR_y = y + R;
                    emptySlotR = true;
                } else
                    moveR = false;
            } else
                moveR = false;
            R++;
        }
    }

    int score = inLineL + inLineR;

    //if there's a win
    if(score + 1 >= mN) {
        setScore(1000, player, isAI, x, y);
        return true;
    }//if there's two win setups (score)
    else if(emptySlotL && emptySlotR && score + 1 == mN-1) {
        setScore(100, player, isAI, emptyLocL_x, emptyLocL_y);
        setScore(100, player, isAI, emptyLocR_x, emptyLocR_y);
    }//if there's just one score
    else {
        //if there's just a score to the left
        if(scoreL + inLineR + 1 >= mN-1) {
            if(emptySlotL)
                setScore(100, player, isAI, emptyLocL_x, emptyLocL_y);

        }//if there's just a score to the right
        if(scoreR + inLineL + 1 >= mN-1) {
            if(emptySlotR)
                setScore(100, player, isAI, emptyLocR_x, emptyLocR_y);
        }
    }

    if(inLineL + inLineR > 0)
        score = 1;

    //if there's a block or just a piece with nothing around it
    setScore(score, player, isAI, x, y);

    return false;
}


bool GameBoard::checkDiag2(char player, bool isAI, int x, int y) {
    //------------Note--------------
    //  MoveL(-, +) : Left, Up
    //  MoveR(+, -) : Right, Down
    //------------------------------

    int L = 1;
    int R = 1;
    int inLineL = 0;
    int inLineR = 0;
    int scoreL = 0;
    int scoreR = 0;
    bool emptySlotL = false;
    bool emptySlotR = false;
    int emptyLocL_x = x;
    int emptyLocL_y = y;
    int emptyLocR_x = x;
    int emptyLocR_y = y;
    bool moveL = true;
    bool moveR = true;

    while(moveL || moveR) {
        if(x-L<0 || y+L>mHeight-1 || L>3)
            moveL = false;
        if(x+R>mWidth-1 || y-R<0 || R>3)
            moveR = false;

        if(moveL) {
            if(mGrid[x-L][y+L]==player) {
                scoreL++;
                if(!emptySlotL)
                    inLineL++;
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
                scoreR++;
                if(!emptySlotR)
                    inLineR++;
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

    int score = inLineL + inLineR;

    //if there's a win
    if(score + 1 >= mN) {
        setScore(1000, player, isAI, x, y);
        return true;
    }//if there's two win setups (score)
    else if(emptySlotL && emptySlotR && score + 1 == mN-1) {
        setScore(100, player, isAI, emptyLocL_x, emptyLocL_y);
        setScore(100, player, isAI, emptyLocR_x, emptyLocR_y);
    }//if there's just one score
    else {
        //if there's just a score to the left
        if(scoreL + inLineR + 1 >= mN-1) {
            if(emptySlotL)
                setScore(100, player, isAI, emptyLocL_x, emptyLocL_y);

        }//if there's just a score to the right
        if(scoreR + inLineL + 1 >= mN-1) {
            if(emptySlotR)
                setScore(100, player, isAI, emptyLocR_x, emptyLocR_y);
        }
    }

    if(inLineL + inLineR > 0)
        score = 1;

    //if there's a block or just a piece with nothing around it
    setScore(score, player, isAI, x, y);

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
void GameBoard::setScore(int score, char color, bool isAI, int x, int y) {
    char temp = scores[x][y];
    int val = score;
    if(!isAI)
        val = -score;

    if(score == 1000 || score < 100) {
        if(temp != 'X' && temp != '.' && temp != color) {
            if (isAI)
                totalScore += 100;
            else
                totalScore -= 100;
        }
        else
            totalScore += val;

        scores[x][y] = 'X';
        return;
    }
    else {
        if(temp == color || temp == 'X')
            return;
        else {
            totalScore += val;
            if(temp == '.')
                scores[x][y] = color;
            else
                scores[x][y] = '#';

            return;
        }
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
//  getSlots()
//
//  Purpose: Accessor, returns the number of open
//  left on the board
//
//  Parameters: (none)
//
//  Returns: int
//---------------------------------------------------
int GameBoard::getSlots() {
    return slots;
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
int GameBoard::getScore() {
    return totalScore;
}