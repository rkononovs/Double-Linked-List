#pragma once
#include "doubleLinkedListNode.h"
#include <iostream>

/*! \class Double Linked List
    \brief A double linked list data structure
*/
using std::cout;
using std::endl;
using std::cin;

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
    ~DoubleLinkedList();

    void addFront(G newElement);
    void addBack(G newElement);
    void addAfterCurrent(G newElement);
    void addBeforeCurrent(G newElement);

    void popCurrent();
    G popBack();
    G popFront();

    void traverseForward();
    void traverseBackward();
    
    unsigned int getSize();
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
DoubleLinkedList<G>::~DoubleLinkedList()
{
}
template<class G>
void DoubleLinkedList<G>::addFront(G newElement)
{
    shared_ptr<DoubleLinkedListNode<G>> tmp(new DoubleLinkedListNode<G>(newElement, front, nullptr));
    if (empty()) {
        front = tmp;
        back = tmp;
        current = tmp;
    }
    else {
        front = tmp;
    }

    size++;
}
template<class G>
void DoubleLinkedList<G>::addBack(G newElement)
{   
    shared_ptr<DoubleLinkedListNode<G>> tmp(new DoubleLinkedListNode<G>(newElement, nullptr, back));
    if (empty()) {
        front = tmp;
        back = tmp;
        current = tmp;
    }
    else {
        back = tmp;
    }

    size++;
}
template<class G>
void DoubleLinkedList<G>::addAfterCurrent(G newElement)
{
}
template<class G>
void DoubleLinkedList<G>::addBeforeCurrent(G newElement)
{
}

template<class G>
void DoubleLinkedList<G>::popCurrent()
{

    size--;
}

template<class G>
G DoubleLinkedList<G>::popBack()
{
    G result;
    if (size == 0) {
        result = "Sorry there is nothing to remove";
    }
    else if (size == 1) {
        result = back->getData();  //!< Get result from back node

        front = nullptr;
        back = nullptr;
        current = nullptr;

        size--; //!< Decrement list size
    }
    else {
        result = back->getData(); //!< Get result from back node
        back = back->getNext(); //!< Set back node next node as new back node
        size--; //!< Decrement list size
    }

    return result;
}

template<class G>
G DoubleLinkedList<G>::popFront()
{
    G result;
    if (size == 0) {
        result = "Sorry there is nothing to remove";
    }
    else if(size == 1){
        result = front->getData(); //!< Get result from front node

        front = nullptr;
        back = nullptr;
        current = nullptr;

        size--; //!< Decrement list size
    }
    else {
        result = front->getData(); //!< Get result from front node
        front = front->getPrev(); //!< Set fronts node previous node as new front node
        size--; //!< Decrement list size
    }
    return result;
}

template<class G>
void DoubleLinkedList<G>::traverseForward()
{
}

template<class G>
void DoubleLinkedList<G>::traverseBackward()
{
}

template<class G>
unsigned int DoubleLinkedList<G>::getSize()
{
    return size;
}

template<class G>
bool DoubleLinkedList<G>::empty()
{
    return size == 0;
}
