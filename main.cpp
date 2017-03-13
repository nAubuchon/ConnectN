#include "Node.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

u_int8_t** createGrid(unsigned height, unsigned width) {
    srand((unsigned int)time(NULL));    //seeding rand()

    u_int8_t** array = 0;
    array = new u_int8_t*[height];

    for (u_int8_t i = 0; i < height; i++)
    {
        array[i] = new u_int8_t[width];

        for (u_int8_t j = 0; j < width; j++)
            array[i][j] = (uint8_t)(rand()%10);
    }

    return array;
}

u_int8_t** copyGrid(unsigned height, unsigned width, u_int8_t **grid) {
    u_int8_t** array = 0;
    array = new u_int8_t*[height];

    for (u_int8_t i = 0; i < height; i++)
    {
        array[i] = new u_int8_t[width];

        for (u_int8_t j = 0; j < width; j++)
            array[i][j] = grid[i][j];
    }

    return array;
}

void test(uint8_t w, uint8_t h) {
    //create grid
    u_int8_t **x = createGrid(w,h);

    //create root node
    Node *parentNode = new Node(x, w, h);

    //fill its children for 1 layer
    for(int i=0; i<w; i++) {
        parentNode->addChild(new Node(copyGrid(w, h, x), w, h));
        u_int8_t r = (u_int8_t)(rand() % 10);
        parentNode->getChildren()[i]->getData()[3][i] = r;
    }

    //test that pointers are working
    u_int8_t **a = parentNode->getData();
    u_int8_t **b = parentNode->getChildren()[0]->getData();
    u_int8_t **c = parentNode->getChildren()[1]->getData();
    u_int8_t **d = parentNode->getChildren()[2]->getData();
    u_int8_t **e = parentNode->getChildren()[3]->getData();

//    cout << "Parent: " << (int)a[0][0] << endl;
//    cout << "Child1: " << (int)b[0][0] << endl;
//    cout << "Child2: " << (int)c[0][0] << endl;
//    cout << "Child3: " << (int)d[0][0] << endl;
//    cout << "Child4: " << (int)e[0][0] << endl;

    //print all of them out
    cout << "Parent:" << endl;
    for(int i=0; i<w; i++) {
        for (int j=0; j<h; j++)
            cout << (int)a[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Child1: " << endl;
    for(int i=0; i<w; i++) {
        for (int j=0; j<h; j++)
            cout << (int)b[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Child2: " << endl;
    for(int i=0; i<w; i++) {
        for (int j=0; j<h; j++)
            cout << (int)c[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Child3: " << endl;
    for(int i=0; i<w; i++) {
        for (int j=0; j<h; j++)
            cout << (int)d[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Child4: " << endl;
    for(int i=0; i<w; i++) {
        for (int j=0; j<h; j++)
            cout << (int)e[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    //test destructor
    delete parentNode;

    return;
}

int main() {
    const int width = 4;
    const int height = 4;
    test(width, height);

    return 0;
}
