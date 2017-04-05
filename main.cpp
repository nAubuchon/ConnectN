#include "Game.h"
#include <string>

using namespace std;

int main() {
    int N;
    while(true) {
        cout << "Select a number for N: (No More than 4 atm, sorry): ";
        cin >> N;

        if(cin.good() && N < 5 && N > 1)
            break;
        else {
            cout << "Invalid Input..." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    bool playerFirst;
    char choice;
    while(true) {
        cout << "Would you like to go first? (Y/N)";
        cin >> choice;

        if(cin.good() && (choice=='Y' || choice=='y' || choice=='N' || choice=='n') ) {
            if(choice=='Y' || choice=='y')
                playerFirst = true;
            else
                playerFirst = false;
            break;
        }
        else {
            cout << "Invalid Input..." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    int D;
    while(true) {
        cout << "Select difficulty (1-10): ";
        cin >> D;

        if(cin.good() && D<11)
            break;
        else {
            cout << "Invalid Input..." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    //instantiating game
    Game myGame(N, playerFirst, D);
    string garbage;

    myGame.displayBoard();

    //game loop
    while(true) {
        myGame.playGame();
        cout << " " << endl;

        if(myGame.isGameOver()) {
            cin.ignore();
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
