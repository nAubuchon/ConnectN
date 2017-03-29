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
    name = "Human Player";
}


//---------------------------------------------------
//  PlayerAI(bool first, char ** b, int w, int h)
//
//  Purpose: Initializing constructor, sets player
//  name and color
//
//  Parameters:
//      string n -- the name of the player
//
//      bool first -- Determines the piece color the
//      Human player will use (Black goes first)
//
//  Returns: PlayerHuman object
//---------------------------------------------------
PlayerHuman::PlayerHuman(string n, bool first) {
    srand((unsigned)time(NULL));
    name = n;

    if(first)
        color = 'B';
    else
        color = 'R';
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
PlayerHuman::~PlayerHuman() {

}


//---------------------------------------------------
//  takeTurn(GameBoard* board)
//
//  Purpose: Requests from the user the column choice
//  to place a piece into.  Returns the chosen column
//
//  Parameters:
//      GameBoard* board -- the actual board to place
//      the piece into
//
//  Returns: int
//---------------------------------------------------
int PlayerHuman::takeTurn(GameBoard* grid) {
    int choice = 0;
    while(true) {
        cout << "(Human) Please Choose a Column: ";
        cin >> choice;
        if( !cin ) {  //user didn't input a number
            cout << "Invalid Input..." << endl << endl;
            cin.clear();
            cin.ignore(100, '\n'); //skip bad input
        }
        else if( grid->placePiece(color, choice) )
            break;
        else    //user selected a full or non-existent column
            cout << "Invalid Selection..." << endl << endl;
    }

    grid->printBoard();

    return choice;
}

/// For Testing Purposes***
//int PlayerHuman::takeTurn(GameBoard* grid) {
//    int x = 0;
//
//    while(true) {
//        x = (rand()%7);
//
//        if (grid->placePiece(color, x))
//            break;
//    }
//
//    grid->printBoard();
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
    return color;
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
    return name;
}