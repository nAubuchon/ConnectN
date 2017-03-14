//
// Created by NICK AUBUCHON on 3/12/17.
//

#include "Tree.h"

using namespace std;

Tree::Tree() {
    depth = -1;
    breadth = -1;
    currDepth = -1;
    currBreadth = -1;
    root = NULL;
    currParent = NULL;
    currNode = NULL;
    currChildren = NULL;
    currData = NULL;
}

Tree::Tree(Node* r) {
    depth = 0;
    breadth = 0;
    currDepth = 0;
    currBreadth = 0;
    root = r;
    currParent = NULL;
    currNode = r;
    currChildren = r->getChildren();
    currData = r->getData();
}

Tree::~Tree() {
    delete root;
}

void Tree::addLeft(Node* c) {
    breadth++;
    if(currNode->addChild(c))
        return;
    else
        cout << "Failed to add to the tree" << endl;
}

void Tree::deleteBranch(){
    Node* node = currNode->getParent();
    int8_t index = currNode->get_cIndex();
    delete currNode;
    currNode = node;
    breadth -= currNode->getWidth();
}

void Tree::stepDown() {
    currDepth++;
    currBreadth = 0;
    currParent = currNode;
    currNode = currNode->getChildren()[0];
    currChildren = r->getChildren();
    currData = r->getData();
}

void Tree::stepRight(){

}

Node* Tree::getRoot() {

}

Node* Tree::getCurrNode(){

}

Node* Tree::getCurrParent() {

}

Node** Tree::getCurrChildren() {

}

bool Tree::isEmpty() {
    return (!depth<0);
}

uint8_t** Tree::getCurrData() {

}

uint8_t** Tree::getRootData() {

}
