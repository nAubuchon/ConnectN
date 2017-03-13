//
// Created by NICK AUBUCHON on 3/12/17.
//

#ifndef CONNECTN_TREE_H
#define CONNECTN_TREE_H

#include "Node.h"

class Tree {
public:
    Tree();
    ~Tree();

    void addLeft(Node*);
    void deleteBranch(Node*);
private:
    Node root;
};


#endif //CONNECTN_TREE_H
