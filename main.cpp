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
            array[i][j] = num;
    }

    return array;
}

int main() {
    const int n = 4;

    //**** TESTING ****//
    int **x = createGrid(n,n,0);

    Node *parentNode = new Node(x, n);

    for(int i=0; i<n; i++) {
        parentNode->addChild(new Node(createGrid(n, n, i+1), n));
    }

    int **a = parentNode->getData();
    int **b = parentNode->getChildren()[0]->getData();
    int **c = parentNode->getChildren()[1]->getData();
    int **d = parentNode->getChildren()[2]->getData();
    int **e = parentNode->getChildren()[3]->getData();

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

    cout << endl << "Child3: " << endl;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Child4: " << endl;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++)
            cout << e[i][j] << " ";
        cout << endl;
    }

    delete parentNode;

    //**** END TESTING ****//
    return 0;
}