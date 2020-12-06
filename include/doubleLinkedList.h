#pragma once
#include "doubleLinkedListNode.h"

/*! \class Double Linked List
    \brief A double linked list data structure
*/

template <class G>
class DoubleLinkedList
{
private:
    unsigned int size; //!< Number of elements in the dll
    shared_ptr<DoubleLinkedListNode<G>> front;
    shared_ptr<DoubleLinkedListNode<G>> back;
    shared_ptr<DoubleLinkedListNode<G>> current;

public:
    DoubleLinkedList();
    void push(G newElement);
    G pop();
    bool empty();
};

template<class G>
DoubleLinkedList<G>::DoubleLinkedList()
{
    front = nullptr;
    back = nullptr;
    current = nullptr;
    size = 0;
}

template<class G>
void DoubleLinkedList<G>::push(G newElement)
{
    shared_ptr<DoubleLinkedListNode<G>> tmp(new DoubleLinkedListNode<G>(newElement));
    if (empty()) {
        head = tmp;
        tail = tmp;
        current = tmp;
    }
    else() {

    }

    size++;
}

template<class G>
bool DoubleLinkedList<G>::empty()
{
    return size == 0;
}
