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
    shared_ptr<doubleLinkedListNode<G>>  head;
    shared_ptr<doubleLinkedListNode<G>> tail;

public:
    DoubleLinkedList();
    void push(G newElement);
    G pop();
    bool empy();
};

