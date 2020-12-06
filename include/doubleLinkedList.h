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

    void addFront(G newElement);
    void addBack(G newElement);
    void addAfterCurrent(G newElement);
    void addBeforeCurrent(G newElement);

    void popCurrent();
    void popBack();
    G popFront();

    void traverseForward();
    void traverseBackward();

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
void DoubleLinkedList<G>::addFront(G newElement)
{
    shared_ptr<DoubleLinkedListNode<G>> tmp(new DoubleLinkedListNode<G>(newElement, front, nullptr));
    if (empty()) {
        front = tmp;
        back = tmp;
        current = tmp;
    }
    else {
        front->setNext(tmp);
        front = tmp;
        back = tmp; // Do I need this?
        current = tmp;
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
        back->setPrev(tmp);
        front = tmp; // Do I need this?
        back = tmp;
        current = tmp;
    }
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
void DoubleLinkedList<G>::popBack()
{

    size--;
}

template<class G>
G DoubleLinkedList<G>::popFront()
{
    if (size == 0) {
        cout << "Sorry there is nothing to remove" << endl;
    }
    else {
        G result = front->getData();
        shared_ptr<DoubleLinkedListNode<G>> tmp = front;
        front = front->getPrev();
        current = tmp->getPrev();
        size--;
        return result;
    }
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
bool DoubleLinkedList<G>::empty()
{
    return size == 0;
}
