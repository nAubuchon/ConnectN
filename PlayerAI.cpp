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
    mColor = ' ';
    mBoardCopy = NULL;
}


//---------------------------------------------------
//  PlayerAI(bool isFirst, GameBoard* board)
//
//  Purpose: Initializing constructor, sets color,
//  width, height and boardCopy (2D char array)
//
//  Parameters:
//      bool isFirst -- Determines the piece color the
//      AI player will use (Black goes first)
//
//      GameBoard* board -- pointer to the GameBoard
//      object to be copied into PlayerAI's member
//
//  Returns: PlayerAI object
//---------------------------------------------------
PlayerAI::PlayerAI(bool isFirst, GameBoard* board) {
    if(isFirst)
        mColor = 'B';
    else
        mColor = 'R';

    //call the copy constructor
    mBoardCopy = new GameBoard(board);
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
    delete mBoardCopy;
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
        else if( board->placePiece(mColor, choice) )
            break;
        else    //user selected a full or non-existent column
            cout << "Invalid Selection..." << endl << endl;
    }///*****************FOR TESTING******************

    return choice;
}

/// For Testing Purposes***
//int PlayerAI::takeTurn(GameBoard* board) {
//    int x = 0;
//
//    while(true) {
//        x = (rand()%7);
//
//        if (board->placePiece(mColor, x))
//            break;
//    }
//
//    return x;
//}
/// ***********************


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
    return mColor;
}

