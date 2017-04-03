//
// Created by nick on 3/13/17.
//

#include "PlayerHuman.h"


//---------------------------------------------------
//  PlayerHuman()
//
//  Purpose: Default Constructor
//
//  Parameters: (none)
//
//  Returns: PlayerHuman object
//---------------------------------------------------
PlayerHuman::PlayerHuman() {
    mName = "Human Player";
}


//---------------------------------------------------
//  PlayerHuman(bool isFirst, string name)
//
//  Purpose: Initializing constructor, sets player
//  name and color
//
//  Parameters:
//      bool isFirst -- Determines the piece color
//      the Human player will use (Black goes first)
//
//      string name -- the name of the player
//
//  Returns: PlayerHuman object
//---------------------------------------------------
PlayerHuman::PlayerHuman(bool isFirst, string name) {
    srand((unsigned)time(NULL));
    mName = name;

    if(isFirst)
        mColor = 'B';
    else
        mColor = 'R';
}


//---------------------------------------------------
//  ~PlayerHuman()
//
//  Purpose: Destructor
//
//  Parameters: (none)
//
//  Returns: (none)
//---------------------------------------------------
PlayerHuman::~PlayerHuman() {

}


//---------------------------------------------------
//  takeTurn(GameBoard* board)
//
//  Purpose: Requests from the user the column choice
//  to place a piece into.  Returns the chosen column
//
//  Parameters:
//      GameBoard* board -- GameBoard object to place
//      the piece into
//
//  Returns: int

//---------------------------------------------------
int PlayerHuman::takeTurn(GameBoard* board) {
    int choice = 0;
    while(true) {
        cout << "(Human) Please Choose a Column: ";
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
    }

    return choice;
}

/// For Testing Purposes***
//int PlayerHuman::takeTurn(GameBoard* board) {
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
//  assigned piece color of the Human player
//
//  Parameters: (none)
//
//  Returns: char
//---------------------------------------------------
char PlayerHuman::getColor() {
    return mColor;
}


//---------------------------------------------------
//  getName()
//
//  Purpose: Accessor for the name data member, the
//  chosen name of the Human player
//
//  Parameters: (none)
//
//  Returns: string
//---------------------------------------------------
string PlayerHuman::getName() {
    return mName;
}