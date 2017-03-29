//
// Created by nick on 3/13/17.
//

#include "PlayerAI.h"


//---------------------------------------------------
//  PlayerAI()
//
//  Purpose: Default Constructor
//
//  Parameters: (none)
//
//  Returns: PlayerAI object
//---------------------------------------------------
PlayerAI::PlayerAI() {
    color = ' ';
    boardCopy = NULL;
}


//---------------------------------------------------
//  PlayerAI(bool first, char ** b, int w, int h)
//
//  Purpose: Initializing constructor, sets color,
//  width, height and boardCopy (2D char array)
//
//  Parameters:
//      bool first -- Determines the piece color the
//      AI player will use (Black goes first)
//
//      char **b -- The current board to be copied
//      for the playerAI to perform it's look-ahead
//
//      int w -- The width of the board
//
//      int h -- The height of the board
//
//  Returns: PlayerAI object
//---------------------------------------------------
PlayerAI::PlayerAI(bool first, char** b, int w, int h) {
    if(first)
        color = 'B';
    else
        color = 'R';

    boardCopy = new GameBoard(copyGrid(w, h, b), w, h);
}


//---------------------------------------------------
//  ~PlayerAI()
//
//  Purpose: Destructor
//
//  Parameters: (none)
//
//  Returns: (none)
//---------------------------------------------------
PlayerAI::~PlayerAI() {

}


//---------------------------------------------------
//  takeTurn(GameBoard* board)
//
//  Purpose: Sets up a calls the functions for the
//  PlayerAI to begin the minimax algorithm.  Returns
//  the chosen column
//
//  Parameters:
//      GameBoard* board -- the actual board to place
//      the piece into
//
//  Returns: int
//---------------------------------------------------
int PlayerAI::takeTurn(GameBoard* board) {
    int choice = 0;

    ///*****************FOR TESTING******************
    while(true) {
        cout << "(AI) Please Choose a Column: ";
        cin >> choice;
        if( !cin ) {  //user didn't input a number
            cout << "Invalid Input..." << endl << endl;
            cin.clear();
            cin.ignore(100, '\n'); //skip bad input
        }
        else if( board->placePiece(color, choice) )
            break;
        else    //user selected a full or non-existent column
            cout << "Invalid Selection..." << endl << endl;
    }///*****************FOR TESTING******************

    board->printBoard();

    return choice;
}

///// For Testing Purposes***
//int PlayerAI::takeTurn(GameBoard* board) {
//    int x = 0;
//
//    while(true) {
//        x = (rand()%7);
//
//        if (board->placePiece(color, x))
//            break;
//    }
//
//    board->printBoard();
//
//    return x;
//}
///// ***********************


//---------------------------------------------------
//  getColor()
//
//  Purpose: Accessor for the color data member, the
//  assigned piece color of the AI player
//
//  Parameters: (none)
//
//  Returns: char
//---------------------------------------------------
char PlayerAI::getColor() {
    return color;
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
char** PlayerAI::copyGrid(int width, int height, char** grid) {
    char** array = 0;

    array = new char*[height];

    for (int i=0; i<height; ++i) {
        array[i] = new char[width];

        for (int j=0; j<width; ++j)
            array[i][j] = grid[i][j];
    }

    return array;
}