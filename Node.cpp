//
// Created by NICK AUBUCHON on 3/11/17.
//

#include "Node.h"

using namespace std;

Node::Node() {
    width = 0;
    height = 0;
    data = NULL;
    parent = NULL;
    children = NULL;
}

Node::Node(u_int8_t **d, u_int8_t w, u_int8_t h) {
    width = w;
    height = h;
    data = d;
    parent = NULL;
    children = new Node*[width];
    for(u_int8_t i=0; i<width; i++)
        children[i] = NULL;
}

Node::~Node() { // this may need some work
    cout << "NODE DESTRUCTOR STARTING" << endl; //testing
    for(u_int8_t i=0;i<width;++i) {
        //delete the children if they exist
        if(children[i] != NULL) {
            cout << "Deleting child[" << (int)i << "]..." << endl;
            delete children[i];
        }
    }
    //then delete the data
    for(u_int8_t j=0; j<width; ++j) {
        cout << "Deleting data[" << (int)j << "]..." << endl;
        delete[] data[j];
    }
    delete[] data;
    delete[] children;
    cout << "NODE DESTRUCTOR COMPLETE" << endl; //testing
}

u_int8_t** Node::getData() {
    return data;
}

Node* Node::getParent() {
    return parent;
}

void Node::addChild(Node *c) {
    u_int8_t i = 0;
    while(i<width) {
        if(children[i]==NULL) {
            children[i] = c;
            c->parent = this;
            return;
        }
        i++;
    }

    cout << "No more room for children" << endl;
}

Node** Node::getChildren() {
    return children;
}