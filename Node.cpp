//
// Created by NICK AUBUCHON on 3/11/17.
//

#include "Node.h"

using namespace std;

Node::Node() {
    width = 0;
    height = 0;
    c_index = -1;
    data = NULL;
    parent = NULL;
    children = NULL;
}

Node::Node(uint8_t **d, uint8_t w, uint8_t h) {
    width = w;
    height = h;
    c_index = -1;
    data = d;
    parent = NULL;
    children = new Node*[width];
    for(uint8_t i=0; i<width; i++)
        children[i] = NULL;
}

Node::~Node() { // this may need some work
    cout << "NODE DESTRUCTOR STARTING" << endl; //testing
    for(int i=0;i<width;++i) {
        //delete the children if they exist
        if(children[i] != NULL) {
            cout << "Deleting child[" << i << "]..." << endl;
            delete children[i];
        }
    }
    //then delete the data
    for(int j=0; j<width; ++j) {
        cout << "Deleting data[" << j << "]..." << endl;
        delete[] data[j];
    }
    delete[] data;
    delete[] children;
    cout << "NODE DESTRUCTOR COMPLETE" << endl; //testing
}

uint8_t** Node::getData() {
    return data;
}

Node* Node::getParent() {
    return parent;
}

bool Node::addChild(Node *c) {
    int i = 0;
    while(i<width) {
        if(children[i]==NULL) {
            children[i] = c;
            c->parent = this;
            c->set_cIndex((int8_t)i);
            return true;
        }
        i++;
    }
    cout << "No more room for children" << endl;
    return false;
}

Node** Node::getChildren() {
    return children;
}

uint8_t Node::getWidth() {
    return width;
}

uint8_t Node::getHeight() {
    return height;
}

int8_t Node::get_cIndex() {
    return c_index;
}

void Node::set_cIndex(int8_t i) {
    c_index = i;
}

void Node::shiftChildren(int8_t index) {
    int8_t i = 0;
    if(index==(int8_t)(width-1))
        return;
    if (children[index + 1] == NULL)
        return;
    for (i=index; i<(int8_t)(width-1); i++)
        children[i] = children[i + 1];
    children[i] = NULL;
}