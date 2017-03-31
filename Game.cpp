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
    N = 0;
    connectN = NULL;
    aemula = NULL;
    vos = NULL;
    gameOver = false;
}


//---------------------------------------------------
//  Game(int n, bool playerFirst)
//
//  Purpose: Initializing constructor, sets GameBoard
//  and Player objects
//
//  Parameters:
//      int n -- to specify the number of in-line
//      pieces achieves a win
//
//      bool playerFirst -- to specify whether the
//      human player goes first or not
//
//  Returns: Game object
//---------------------------------------------------
Game::Game(int n, bool playerFirst) {
    int width = (2*n) - 1;
    int height = (2*n) - 2;
    N = n;
    connectN = new GameBoard(createGrid(width, height), width, height);
    aemula = new PlayerAI(!playerFirst, connectN->getGrid(), width, height);
    vos = new PlayerHuman("Nick", playerFirst);
    gameOver = false;
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
    connectN->~GameBoard();
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

    // Human First
    if(vos->getColor()=='B') {
        //initiate Human's turn
        col = vos->takeTurn(connectN);

        //displayColumn
        displayBoard();

        //get the row where the piece "fell"
        row = connectN->getRow(col) - 1;

        // If placed piece won the game, exit function
        if (checkWin('B', col, row)) {
            cout << "Black Wins!" << endl;
            gameOver = true;
            return;
        }

        //initiate AI's turn
        col = aemula->takeTurn(connectN);

        //displayColumn
        displayBoard();

        //get the row where the piece "fell"
        row = connectN->getRow(col) - 1;

        // If placed piece won the game, exit function
        if (checkWin('R', col, row)) {
            cout << "Red Wins!" << endl;
            gameOver = true;
            return;
        }
    }
    // Same process, but with AI First
    else {
        col = aemula->takeTurn(connectN);
        displayBoard();
        row = connectN->getRow(col) - 1;

        if( checkWin('B', col, row)) {
            cout << "Black Wins!";
            gameOver = true;
            return;
        }

        col = vos->takeTurn(connectN);
        displayBoard();
        row = connectN->getRow(col) - 1;

        if( checkWin('R', col, row)) {
            cout << "Red Wins!";
            gameOver = true;
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
char** Game::createGrid(int width, int height) {
    ///srand((unsigned)time(NULL));    //seeding rand() for testing

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
            array[i][j] = '.';  ///(char)(rand()%25 + 65);   //for testing
    }

    //return pointer to memory location of new array
    return array;
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
bool Game::checkWin(char color, int x, int y) {
    // temporary local variables
    char **grid = connectN->getGrid();
    int width = connectN->getWidth();
    int height = connectN->getHeight();

    int count = 0;
    int i = 0;

    //------------Note--------------
    //  + : Up for y, Right for x
    //  - : Down for y, Left for x
    //------------------------------

    //check vertical down
    if (y >= N-1) {
        //begin moving down (0,-1)
        for (i=1; i<N; ++i) {
            if(y-i < 0)
                break;
            //break if no match on the piece below
            if (grid[x][y-i] != color)
                break;
            //increment the number of pieces in line
            count++;
        }
        // if the count is at least N-1, it is a win
        // (because we're not counting the placed piece)
        if(count >= N-1)
            return true;
    }

    //if no completed counts, then reset
    count = 0;

    //check horizontal left, similar process
    if (x > 0) {
        //begin moving left (-1,0)
        for (i=1; i<N; ++i) {
            if (x-i < 0)
                break;
            if (grid[x-i][y] != color)
                break;
            count++;
        }
        if (count >= N-1)
            return true;
    }
    //check horizontal right, keeping value of count so far
    if(x < connectN->getWidth() -1) {
        //begin moving right (+1,0)
        for (i=1; i<N; ++i) {
            if (x+i > width-1)
                break;
            if (grid[x+i][y] != color)
                break;
            count++;
        }
        if (count >= N-1)
            return true;
    }

    //reset count
    count = 0;

    //check diagonal low left to high right
    if(y < height-1 && x < width-1) {
        //begin moving right and up (+1,+1)
        for (i=1; i<N; ++i) {
            if (x+i>width-1 || y+i>height-1)
                break;
            if (grid[x+i][y+i] != color)
                break;
            count++;
        }
        if (count >= N-1)
            return true;
    }
    //check diagonal high right to low left, keep count
    if(y>0 && x>0) {
        //begin moving left and down (-1,-1)
        for (i=1; i<N; ++i) {
            if (x-i<0 || y-i<0)
                break;
            if (grid[x-i][y-i] != color)
                break;
            count++;
        }
        if (count >= N-1)
            return true;
    }

    //reset count
    count = 0;

    //check diagonal high left to low right
    if( y>0 && x<(width-1) ) {
        //begin moving right and down (+1,-1)
        for (i=1; i<N; ++i) {
            if( (x+i)>width-1 || (y-i)<0 )
                break;
            if (grid[x+i][y-i] != color)
                break;
            count++;
        }
        if (count >= N-1)
            return true;
    }
    //check diagonal low right to high left
    if( y<(height-1) && x>0 ) {
        //begin moving left and up (-1,+1)
        for (i=1; i<N; ++i) {
            if(x-i<0 || y+i>height-1)
                break;
            if (grid[x-i][y+i] != color)
                break;
            count++;
        }
        if (count >= N-1)
            return true;
    }

    //if all the above failed, there was no win
    //returns false
    return false;
}


//---------------------------------------------------
//  isGameOver()
//
//  Purpose: Return the gameOver boolean value for
//  checking if game is over by a win or by a tie.
//  Returns 'true' if game is over, 'false' if not
//
//  Parameters: (none)
//
//  Returns: bool
//---------------------------------------------------
bool Game::isGameOver() {
    return gameOver;
}


//---------------------------------------------------
//  clearBoard()
//
//  Purpose: Calls the GameBoard destructor and
//  allocates new GameBoard object for the connectN
//  member
//
//  Parameters: (none)
//
//  Returns: void
//---------------------------------------------------
void Game::clearBoard() {
    int height = connectN->getHeight();
    int width = connectN->getWidth();
    connectN->~GameBoard();

    connectN = new GameBoard(createGrid(width, height), width, height);
    gameOver = false;
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
    connectN->printGrid();
}