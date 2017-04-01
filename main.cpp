#include "Game.h"
//#include "GameBoard.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

char** createGrid(int width, int height) {
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

int main() {
//    GameBoard *game1 = new GameBoard(createGrid(4,4), 4, 4);
//    GameBoard *game2 = new GameBoard(game1);
//
//    game1->placePiece('X', 0);
//
//    cout << "game1:\n";
//    game1->printGrid();
//    cout << "\ngame2:\n";
//    game2->printGrid();

    //instantiating game
    Game myGame(4, true);
    char garbage;

    myGame.displayBoard();

    //game loop
    while(true) {
        myGame.playGame();
        cout << " " << endl;

        if(myGame.isGameOver()) {
            cout << "Enter \"x\" to exit: ";
            cin >> garbage;
            if(garbage=='x') {
                break;
            }

            myGame.clearBoard();
        }

    }

    return 0;
}
