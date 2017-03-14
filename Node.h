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
    Node(uint8_t**, uint8_t, uint8_t);
    //Destructor
    ~Node();

    //member functions
    uint8_t** getData();
    Node* getParent();
    bool addChild(Node*);
    Node** getChildren();
    uint8_t getWidth();
    uint8_t getHeight();    // remove?
    int8_t get_cIndex();
    void set_cIndex(int8_t);
    void shiftChildren(int8_t);

private:
    //data members
    uint8_t width;
    uint8_t height;     // remove?
    int8_t c_index;
    uint8_t** data;
    Node* parent;
    Node** children;
};

#endif //CONNECTN_NODE_H
