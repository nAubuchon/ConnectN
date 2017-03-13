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
    Node(u_int8_t**, u_int8_t, u_int8_t);
    //Destructor
    ~Node();

    //member functions
    u_int8_t** getData();
    Node* getParent();
    void addChild(Node*);
    Node** getChildren();

private:
    //data members
    u_int8_t width;
    u_int8_t height;
    u_int8_t** data;
    Node* parent;
    Node** children;
};

#endif //CONNECTN_NODE_H
