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

    //Destructor
    ~Tree();

    //member functions
    void addLeft(Node*);
    void deleteBranch(Node*);

private:
    //data members
    Node root;
};


#endif //CONNECTN_TREE_H
