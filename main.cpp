#include "Game.h"
#include <string>

using namespace std;

int main() {

    //instantiating game
    Game myGame(4, false);
    string garbage;

    myGame.displayBoard();

    //game loop
    while(true) {
        myGame.playGame();
        cout << " " << endl;

        if(myGame.isGameOver()) {
            cout << "Enter \"x\" to exit: ";
            getline(cin, garbage);
            if(garbage.empty())
                myGame.clearBoard();
            else if(garbage=="x")
                break;
            else
                myGame.clearBoard();
        }

    }

    return 0;
}
