//
// Created by NICK AUBUCHON on 3/12/17.
//

#ifndef CONNECTN_TREE_H
#define CONNECTN_TREE_H

#include "Node.h"

class Tree {
public:
    //Constructors
    Tree();
    Tree(Node*);
    //Destructor
    ~Tree();

    //member functions
    void addLeft(Node*);
    void deleteBranch();
    void stepDown();
    void stepRight();

    Node* getRoot();
    Node* getCurrNode();
    Node* getCurrParent();
    Node** getCurrChildren();

    bool isEmpty();

    uint8_t** getCurrData();
    uint8_t** getRootData();

private:
    //data members
    int depth;
    int breadth;
    int currDepth;
    int currBreadth;
    Node* root;
    Node* currParent;
    Node* currNode;
    Node** currChildren;
    uint8_t** currData;
};


#endif //CONNECTN_TREE_H
