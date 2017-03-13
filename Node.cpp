//
// Created by NICK AUBUCHON on 3/11/17.
//

#include "Node.h"

Node::Node() {
    width = 0;
    data = NULL;
    parent = NULL;
    children = NULL;
}

Node::Node(int **d, int c) {
    width = c;
    data = d;
    parent = NULL;
    children = new Node*[c];
    for(int i=0; i<width; i++)
        children[i] = NULL;
}

Node::~Node() { // this may need some work
    std::cout << std::endl << "NODE DESTRUCTOR STARTING" << std::endl; //testing
    for(int i=0;i<width;i++) {
        if(children[i] != NULL) {
            delete children[i];
            if(data[i] != NULL)
                delete[] data[i];
        }
    }
    std::cout << std::endl << "NODE DESTRUCTOR COMPLETE" << std::endl; //testing
}

int** Node::getData() {
    return data;
}

Node* Node::getParent() {
    return parent;
}

void Node::addChild(Node *c) {
    int i = 0;
    while(i<width) {
        if(children[i]==NULL) {
            children[i] = c;
            c->parent = this;
            return;
        }
        i++;
    }

    std::cout << "No more room for children" << std::endl;
}

Node** Node::getChildren() {
    return children;
}