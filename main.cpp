#include "Node.h"

using namespace std;

int** createGrid(unsigned height, unsigned width, int num)
{
    int** array = 0;
    array = new int*[height];

    for (int i = 0; i < height; i++)
    {
        array[i] = new int[width];

        for (int j = 0; j < width; j++)
        {
            // fill in some initial values
            // (filling in zeros would be more logic, but this is just for the example)
            array[i][j] = num;
        }
    }

    return array;
}

int main() {
    const int n = 4;

    int **x = createGrid(n,n,0);
    int size = sizeof(x);

    Node *parentNode = new Node(x, n);

    int **y = createGrid(n,n,0);
    memcpy(y,x,size);
    y[3][2] = 1;
    Node *child1 = new Node(y, n);

    int **z = createGrid(n,n,0);;
    memcpy(z,x,size);
    z[3][0] = 2;
    Node *child2 = new Node(z, n);

    parentNode->addChild(child1);
    parentNode->addChild(child2);

    int **a = parentNode->getData();
    int **b = parentNode->getChildren()[0]->getData();
    int **c = parentNode->getChildren()[1]->getData();

    cout << "Parent:" << endl;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Child1: " << endl;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Child2: " << endl;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    delete parentNode;

    return 0;
}