#ifndef DLIST_H
#define DLIST_H

#include "node.h"

class DList
{
public:
    DList();
    ~DList();

    void push_back(node* one);

    void push_front(node* one);

    void insert(int index, node* one);

    node* pop_back();

    node* pop_front();

    node* extract(int index);

    node* get_node_front(int index);

    node* get_node_back(int index);

    int size();

    node* max_elem();

    node* min_elem();

    int get_index(node* one);

    DList& combine(const DList& two);

    node* operator[](int index);

    DList& operator=(const DList& other);

private:
    node* first;
    node* last;
};

#endif // DLIST_H
