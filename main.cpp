#include "Game.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    //instantiating game singleton
    Game myGame(4, true);
    char garbage;

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
