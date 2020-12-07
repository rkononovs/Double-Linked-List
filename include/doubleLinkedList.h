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

    void pushFront(G newElement);
    void pushBack(G newElement);
    void pushAfterCurrent(G newElement);
    void pushBeforeCurrent(G newElement);

    G popCurrent();
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
void DoubleLinkedList<G>::pushFront(G newElement)
{
    shared_ptr<DoubleLinkedListNode<G>> tmp(new DoubleLinkedListNode<G>(newElement, front, nullptr));
    if (empty()) {
        front = tmp;
        back = tmp;
        current = tmp;
    }
    else {
       // front->setNext(tmp);
        front->setNext(tmp); //!< Set the previous fronts node's next node to new front node
        front = tmp;

    }

    size++;
}
template<class G>
void DoubleLinkedList<G>::pushBack(G newElement)
{   
    shared_ptr<DoubleLinkedListNode<G>> tmp(new DoubleLinkedListNode<G>(newElement, nullptr, back));
    if (empty()) {
        front = tmp;
        back = tmp;
        current = tmp;
    }
    else {
        back->setPrev(tmp); //!< Set the previous back node's previous node to new back node
        back = tmp;
    }

    size++;
}
template<class G>
void DoubleLinkedList<G>::pushAfterCurrent(G newElement)
{
    shared_ptr<DoubleLinkedListNode<G>> tmp(new DoubleLinkedListNode<G>(newElement, front, back));
    if (empty()) { //!< Sanity check
        cout << "Cannot add after nothing." << endl;
    }
    else {

    }
}
template<class G>
void DoubleLinkedList<G>::pushBeforeCurrent(G newElement)
{
}

template<class G>
G DoubleLinkedList<G>::popCurrent()
{
    G result;
    if (size == 0) {
        result = "Sorry there is nothing to remove";
    }
    else if (size == 1) {
        result = current->getData();

        front = nullptr;
        back = nullptr;
        current = nullptr;

        size--;
    }
    else {
        result = current->getData();

        
        shared_ptr<DoubleLinkedListNode<G>> tmpPrev = current->getPrev();
        shared_ptr<DoubleLinkedListNode<G>> tmpNext = current->getNext();

        if (tmpPrev != nullptr) {
            tmpPrev->setNext(current->getNext());
        }
        else {
            back = tmpNext;
        }

        if (tmpNext != nullptr) {
            tmpNext->setPrev(current->getPrev());
        }
        else {
            front = tmpNext;
        }
        
        

        size--;
    }


    return result;
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
    if (empty()) {
        cout << "Cannot traverse nothing." << endl;
    }
    else {
        if (current != front) {
            current = current->getNext();
        }
        else {
            cout << "Cannot traverse further at the front." << endl;
        }
    }
}

template<class G>
void DoubleLinkedList<G>::traverseBackward()
{
    if (empty()) {
        cout << "Cannot traverse nothing." << endl;
    }
    else {
        if (current != back) {
            current = current->getPrev();
        }
        else {
            cout << "Cannot traverse further at the back." << endl;
        }
    }
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
