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
	mPlayerColor = ' ';
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
	if (isFirst) {
		mColor = 'B';
		mPlayerColor = 'R';
	}
	else {
		mColor = 'R';
		mPlayerColor = 'B';
	}

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
//int PlayerAI::takeTurn(GameBoard* board) {
//    int choice = 0;
//
//    ///*****************FOR TESTING******************
//    while(true) {
//        cout << "(AI) Please Choose a Column: ";
//        cin >> choice;
//        if( !cin ) {  //user didn't input a number
//            cout << "Invalid Input..." << endl << endl;
//            cin.clear();
//            cin.ignore(100, '\n'); //skip bad input
//        }
//        else if( board->placePiece(mColor, choice) )
//            break;
//        else    //user selected a full or non-existent column
//            cout << "Invalid Selection..." << endl << endl;
//    }///*****************FOR TESTING******************
//
//    return choice;
//}

int PlayerAI::takeTurn(GameBoard* board) {
// For Testing Purposes***
//    int x = 0;
//    while(true) {
//        x = (rand()%7);
//        if (board->placePiece(mColor, x))
//            break;
//    }
//  return x;

	// Begin minimax algorithm
	GameBoard boardCopy = new GameBoard(board);
	int score = 0;
	int alpha = -1000;
	int beta = 1000;
	int bestMove = 0;

	// searches through each of the possible moves
	for (int col = 0; col < board->getWidth(); col++) {
		if (boardCopy.placePiece(mColor, col)) { // Place piece in board.
			score = minimax(new GameBoard(boardCopy), col, alpha, beta, 1, false);
			if (score > alpha) { // Check for MAX
				alpha = score;
				bestMove = col;
			}
			if (alpha >= beta) { // Check if branch needs to be PRUNED
				break;
			}
		}
	}

	// Uncomment for debugging
	// cout << "---> Best move " << bestMove << endl;

	board->placePiece(mColor, bestMove);
	return bestMove;
}
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
    return mColor;
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

//--------------------------------------------------
// Purpose: Runs the minimax algorithm with
// Alpha Beta pruning.
//
// Returns: The score that results when reaching
// the bottom of the tree
//
// Obviously, this doesn't work yet.
//--------------------------------------------------
int PlayerAI::minimax(GameBoard board,
	int col, int alpha, int beta, int currentDepth,
	bool isMax) {

	//For debugging
	//cout << "------------------------------------" << endl
	//	<< "Depth: " << currentDepth << (isMax ? " Max" : " Min") << " --- Column: " << col << endl
	//	<< "Alpha: " << alpha << beta << endl;

	// If at the max branch
	if (currentDepth == MAX_DEPTH) {
		return board.getScore(isMax ? mColor : mPlayerColor);;
	}

	currentDepth++;
	int score = 0;

	// Go down child nodes
	for (int col = 0; col < board.getWidth(); col++) {
		if (board.placePiece(isMax ? mColor : mPlayerColor, col)) {
			score = minimax(new GameBoard(board), col, alpha, beta, currentDepth, !isMax);

			// Pruning checks
			if (isMax && score > alpha) { // If on MAX NODE
				alpha = score;
			}
			else if (score < beta) { // If on MIN NODE
				beta = score;
			}
			if (alpha >= beta) { // Check if branch needs to be PRUNED
				return score;
			}
		}
	}
	//cout << (isMax ? "Max" : "Min") << " --- Column: " << col << endl
	//	<< "Score: "  << score << endl;
}
