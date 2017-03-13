//
// Created by NICK AUBUCHON on 3/11/17.
//

#ifndef CONNECTN_NODE_H
#define CONNECTN_NODE_H

#include <iostream>

class Node {
public:
    //Constructors
    Node();
    Node(int**, int);
    //Destructor
    ~Node();

    //member functions
    int** getData();
    Node* getParent();
    void addChild(Node*);
    Node** getChildren();

private:
    //data members
    int width;
    int** data;
    Node* parent;
    Node** children;
};

#endif //CONNECTN_NODE_H
