#ifndef NODE_H
#define NODE_H

#include <iostream>

struct node
{
    double a;
    node* prev;
    node* next;

    node() :
        a(0),
        prev(nullptr),
        next(nullptr) {}
    node(double a_) :
        a(a_),
        prev(nullptr),
        next(nullptr) {}
};

#endif // NODE_H
