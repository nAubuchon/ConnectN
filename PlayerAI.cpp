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
	branches = 0;
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
	branches = 0;
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
//  takeTurn(GameBoard* board, int playerChoice)
//
//  Purpose: Sets up a calls the functions for the
//  PlayerAI to begin the minimax algorithm.  Returns
//  the chosen column
//
//  Parameters:
//      GameBoard* board -- the actual board to place
//      the piece into
//		int playerChoice -- the most recent column
//		that the player put a piece into
//
//  Returns: int
//---------------------------------------------------
int PlayerAI::takeTurn(GameBoard* board, int playerChoice) {
	// Begin minimax algorithm
	int score = 0;
	int alpha = -10000;
	int beta = 10000;
	int bestMove = playerChoice;
	int col = bestMove;
	int bestScore = -10000;
	int columnsVisited = 1;
	int toggle = -1;
	int mod = 0;

	if(playerChoice < 0)
		col = board->getWidth() / 2;

	branches = 0;

	// searches through each of the possible moves
	while(columnsVisited < mBoardCopy->getWidth()) {
		if (board->getRow(col) < board->getHeight()) { // Place piece in board.
			GameBoard *boardCopy = new GameBoard(board);
			int row = board->getRow(col);

			boardCopy->placePiece(mColor, col);
			boardCopy->checkWin(mColor, true, col, row);
			score = minimax(boardCopy, alpha, beta, 1, false, col);

			delete boardCopy;
		}

		//bestScore = max(bestScore, score)
		if(bestScore < score)
			bestScore = score;
		//alpha = max(alpha, bestScore)
		if(alpha < bestScore) {
			alpha = bestScore;
			bestMove = col;
		}

		if(beta <= alpha)
			break;

		columnsVisited++;
		mod = (playerChoice + (toggle*(columnsVisited/2)) ) + 7;
		col = mod % (mBoardCopy->getWidth());
		toggle = -toggle;
	}

	board->placePiece(mColor, bestMove);
	cout << "Number of Branches visited: " << branches << endl;
	return bestMove;
}



/// ************ For Testing Purposes ************

///Choosing For AI
//int PlayerAI::takeTurn(GameBoard* board, int playerChoice) {
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

///Random Moves
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

/// **********************************************


//--------------------------------------------------
// Purpose: Runs the minimax algorithm with
// Alpha Beta pruning.
//
// Returns: The score that results when reaching
// the bottom of the tree
//
// Obviously, this doesn't work yet.
//--------------------------------------------------
int PlayerAI::minimax(GameBoard *board, int alpha, int beta, int currentDepth, bool isMax, int lastChoice) {
	int score = 0;
	int bestScore = 0;
	int bestMove = lastChoice;
	int col = bestMove;
	int columnsVisited = 1;
	int toggle = -1;
	int mod = 0;

	if(lastChoice < 0)
		col = board->getWidth() / 2;

	// If at the max branch, Check score
	if (currentDepth == MAX_DEPTH) {
		branches++;
		return board->getScore();
	}

	if(isMax) { // Go down child nodes
		bestScore = -10000;
		while(columnsVisited < mBoardCopy->getWidth()) {
			if (board->getRow(col) < board->getHeight()) {
				GameBoard *boardCopy = new GameBoard(board);
				int row = board->getRow(col);

				boardCopy->placePiece(mColor, col);
				boardCopy->checkWin(mColor, true, col, row);
				score = minimax(boardCopy, alpha, beta, currentDepth+1, false, col);

				delete boardCopy;
			}

			//bestScore = max(bestScore, score)
			if(bestScore < score)
				bestScore = score;
			//alpha = max(alpha, bestScore)
			if(alpha < bestScore)
				alpha = bestScore;

			if(beta <= alpha)
				break;

			columnsVisited++;
			mod = (lastChoice + (toggle*(columnsVisited/2)) ) + 7;
			col = mod % (mBoardCopy->getWidth());
			toggle = -toggle;
		}
	}
	else {
		bestScore = 10000;
		while(columnsVisited < mBoardCopy->getWidth()) {
			if (board->getRow(col) < board->getHeight()) {
				GameBoard *boardCopy = new GameBoard(board);
				int row = board->getRow(col);

				boardCopy->placePiece(mPlayerColor, col);
				boardCopy->checkWin(mPlayerColor, false, col, row);
				score = minimax(boardCopy, alpha, beta, currentDepth+1, true, col);

				delete boardCopy;
			}

			//bestScore = min(bestScore, score)
			if(bestScore > score)
				bestScore = score;
			//alpha = min(alpha, bestScore)
			if(alpha > bestScore)
				alpha = bestScore;

			if(beta <= alpha)
				break;

			columnsVisited++;
			mod = (lastChoice + (toggle*(columnsVisited/2)) ) + 7;
			col = mod % (mBoardCopy->getWidth());
			toggle = -toggle;
		}
	}

	return bestScore;
}
