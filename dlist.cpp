#include "dlist.h"
DList::DList() : first(nullptr), last(nullptr) {}

DList::~DList() {
    while (first != nullptr) {
        node* temp = first;
        first = first->next;
        delete temp;
    }
}

void DList::push_back(node* one) {
    if (one == nullptr)
        return;

    for (node* current = first; current != nullptr; current = current->next) {
        if (one->a == current->a)
            return;
    }

    if (last == nullptr) {
        first = one;
        last = one;
    } else {
        last->next = one;
        one->prev = last;
        last = one;
    }
}

void DList::push_front(node* one) {
    if (one == nullptr)
        return;

    for (node* current = first; current != nullptr; current = current->next) {
        if (one->a == current->a)
            return;
    }

    if (first == nullptr) {
        first = one;
        last = one;
    } else {
        first->prev = one;
        one->next = first;
        first = one;
    }
}

void DList::insert(int index, node *one) {
    if (one == nullptr || index < 0)
        return;

    if (first == nullptr) {
        first = one;
        last = one;
        return;
    }

    if (index == 0) {
        push_front(one);
    } else {
        for (node* current = first; current != nullptr; current = current->next) {
            if (one->a == current->a)
                return;
        }

        node* current = first;
        int i = 0;

        while (current != nullptr && i < index - 1) {
            current = current->next;
            i++;
        }

        if (current != nullptr) {
            one->prev = current;
            one->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = one;
            } else {
                last = one;
            }
            current->next = one;
        } else {
            last->next = one;
            one->prev = last;
            last = one;
        }
    }
}

node* DList::pop_back() {
    if (last == nullptr)
        return nullptr;

    node* removedNode = last;
    last = last->prev;
    if (last != nullptr) {
        last->next = nullptr;
    } else {
        first = nullptr;
    }

    return removedNode;
}

node* DList::pop_front() {
    if (first == nullptr)
        return nullptr;

    node* removedNode = first;
    first = first->next;
    if (first != nullptr) {
        first->prev = nullptr;
    } else {
        last = nullptr;
    }

    return removedNode;
}

node* DList::extract(int index) {
    if (index < 0 || index >= this->size())
        return nullptr;

    node* removedNode = nullptr;

    if (index == 0) {
        removedNode = first;
        first = first->next;
        if (first != nullptr) {
            first->prev = nullptr;
        } else {
            last = nullptr;
        }
    } else {
        node* current = first;
        int i = 0;

        while (current != nullptr && i < index) {
            current = current->next;
            i++;
        }

        if (current != nullptr) {
            removedNode = current;
            current->prev->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                last = current->prev;
            }
        }
    }

    return removedNode;
}

node* DList::get_node_front(int index) {
    if (index < 0 || index >= this->size())
        return nullptr;

    node* current = first;
    int i = 0;

    while (current != nullptr && i < index) {
        current = current->next;
        i++;
    }

    return current;
}

node* DList::get_node_back(int index) {
    if (index < 0 || index >= this->size())
        return nullptr;

    node* current = last;
    int i = 0;

    while (current != nullptr && i != index && i < size()) {
        current = current->prev;
        i++;
    }

    return current;
}

int DList::size() {
    int count = 0;
    node* current = first;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

node* DList::max_elem() {
    if (first == nullptr)
        return nullptr;

    node* maxNode = first;
    node* current = first;

    while (current != nullptr) {
        if (current->a > maxNode->a)
            maxNode = current;
        current = current->next;
    }

    return maxNode;
}

node* DList::min_elem() {
    if (first == nullptr)
        return nullptr;

    node* minNode = first;
    node* current = first;

    while (current != nullptr) {
        if (current->a < minNode->a)
            minNode = current;
        current = current->next;
    }

    return minNode;
}

int DList::get_index(node* one) {
    int index = 0;
    node* current = first;

    while (current != nullptr) {
        if (current->a == one->a)
            return index;

        index++;
        current = current->next;
    }

    return -1;
}

DList& DList::combine(const DList& two) {
    DList* combinedList = new DList();
    node* currentOne = this->first;
    node* currentTwo = two.first;

    while (currentOne != nullptr) {
        combinedList->push_back(new node(currentOne->a));
        currentOne = currentOne->next;
    }

    while (currentTwo != nullptr) {
        combinedList->push_back(new node(currentTwo->a));
        currentTwo = currentTwo->next;
    }

    return *combinedList;
}

node* DList::operator[](int index) {
    if (index < 0 || index >= this->size())
        return nullptr;

    node* current = first;
    int i = 0;

    while (current != nullptr && i < index) {
        current = current->next;
        i++;
    }

    return current;
}

DList &DList::operator=(const DList &other) {
    if (this == &other) {
        return *this;
    }

    while (first != nullptr) {
        node* temp = first;
        first = first->next;
        delete temp;
    }

    first = nullptr;
    last = nullptr;

    node* current = other.first;
    while (current != nullptr) {
        push_back(new node(current->a));
        current = current->next;
    }

    return *this;
}
