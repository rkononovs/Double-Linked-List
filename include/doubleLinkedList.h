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
    shared_ptr<DoubleLinkedListNode<G>> front; //!< Shared pointer to the front node in the dll.
    shared_ptr<DoubleLinkedListNode<G>> back; //!< Shared pointer to the back node in the dll.
    shared_ptr<DoubleLinkedListNode<G>> current; //!< Shared pointer to the current node in the dll.

public:
    DoubleLinkedList(); //!< Default constructor
    ~DoubleLinkedList(); //!< Default destructor

    //! Node pushing methods
    void pushFront(G newElement);
    void pushBack(G newElement);
    void pushAfterCurrent(G newElement);
    void pushBeforeCurrent(G newElement);

    //! Node popping methods
    G popCurrent();
    G popBack();
    G popFront();

    //! Node traversal methods
    void traverseForward();
    void traverseBackward();
    
    //! Node getters
    G getFront();
    G getCurrent();
    G getBack();

    unsigned int getSize(); //!< Size getter
    bool empty();
};

template<class G>
DoubleLinkedList<G>::DoubleLinkedList() 
{
    //! Initialize everything as null
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
void DoubleLinkedList<G>::pushFront(G newElement) //!< Adds a node to the front/head of the list
{
    shared_ptr<DoubleLinkedListNode<G>> tmpFront(new DoubleLinkedListNode<G>(newElement, front, nullptr)); //!< Initialize new node
    if (empty()) { //!< If list is empty set everything as new node
        front = tmpFront;
        back = tmpFront;
        current = tmpFront;
    }
    else {
       front->setNext(tmpFront); //!< Set the previous fronts node's next node to new front node
       front = tmpFront; //!< Set new node as new front
    }

    size++; //!< Increment size of the list
}
template<class G>
void DoubleLinkedList<G>::pushBack(G newElement) //!< Adds a node to the back/tail of the list
{   
    shared_ptr<DoubleLinkedListNode<G>> tmpBack(new DoubleLinkedListNode<G>(newElement, nullptr, back)); //!< Initialize new node
    if (empty()) { //!< If list is empty set everything as new node
        front = tmpBack;
        back = tmpBack;
        current = tmpBack;
    }
    else {
        back->setPrev(tmpBack); //!< Set the previous back's node's previous node to new back node
        back = tmpBack; //!< Set new node as new back
    }

    size++; //!< Increment size of the list
}
template<class G>
void DoubleLinkedList<G>::pushAfterCurrent(G newElement) // FIX FUNCTION
{
    if (empty()) { //!< Sanity check
        cout << "Cannot add after nothing." << endl;
    }
    else {
        shared_ptr<DoubleLinkedListNode<G>> tmpPrev = current->getPrev(); //!< Make a pointer to current's node's previous node
        shared_ptr<DoubleLinkedListNode<G>> tmpNext = current->getNext(); //!< Make a pointer to current's node's next node

        if (tmpNext != nullptr) { //!< Check if node that will be pushed is in the middle or near the back
            shared_ptr<DoubleLinkedListNode<G>> tmpMid(new DoubleLinkedListNode<G>(newElement, current, tmpNext)); //!< Initialize new node in the middle
            tmpNext->setPrev(tmpMid); //!< Set previous next nodes previous to new node
            current->setNext(tmpMid); //!< Set currents next node to new node
        }
        else { //!< Check if the node that will be pushed is at the front
            shared_ptr<DoubleLinkedListNode<G>> tmpFront(new DoubleLinkedListNode<G>(newElement, current, nullptr)); //!< Initialize new node at the front
            front->setNext(tmpFront); //!< Set the previous fronts node's next node to new front node
            front = tmpFront; //!< Set new node as new front
        }

        size++; //!< Increment size of the list
    }
}
template<class G>
void DoubleLinkedList<G>::pushBeforeCurrent(G newElement)
{
    shared_ptr<DoubleLinkedListNode<G>> tmpPrev = current->getPrev(); //!< Make a pointer to current's node's previous node
    shared_ptr<DoubleLinkedListNode<G>> tmpNext = current->getNext(); //!< Make a pointer to current's node's next node

    if (tmpPrev != nullptr) { //!< Check if node that will be pushed is in the middle or near the front
        shared_ptr<DoubleLinkedListNode<G>> tmpMid(new DoubleLinkedListNode<G>(newElement, tmpPrev, current)); //!< Initialize new node in the middle
        tmpPrev->setNext(tmpMid); //!< Set previous previous nodes next to new node
        current->setPrev(tmpMid); //!< Set currents previous node to new node
    }
    else { //!< Check if the node that will be pushed is at the front
        shared_ptr<DoubleLinkedListNode<G>> tmpBack(new DoubleLinkedListNode<G>(newElement, nullptr, current)); //!< Initialize new node at the front
        back->setPrev(tmpBack); //!< Set the previous back's node's previous node to new back node
        back = tmpBack; //!< Set new node as new back
    }

    size++; //!< Increment size of the list
}

template<class G>
G DoubleLinkedList<G>::popCurrent() //!< Removes current node
{
    G result;
    if (empty()) { //!< If list empty print generic message
        result = "Sorry there is nothing to remove";
    }
    else if (size == 1) { //!< If only one element is in the list assign everything to nullptr
        result = current->getData(); //!< Get current's node's data

        front = nullptr;
        back = nullptr;
        current = nullptr;

        size--; //!< Decrement lists size
    }
    else {
        result = current->getData(); //!< Get current's node's data

        
        shared_ptr<DoubleLinkedListNode<G>> tmpPrev = current->getPrev(); //!< Make a pointer to current's node's previous node
        shared_ptr<DoubleLinkedListNode<G>> tmpNext = current->getNext(); //!< Make a pointer to current's node's next node

        if ((tmpPrev != nullptr) && (tmpNext != nullptr)) { //!< Check if node that will be pop'd is in the middle
            tmpPrev->setNext(tmpNext); //< Make current's node's previous node point to current's node's next node
            current = tmpPrev;
        }
        else if (tmpPrev != nullptr) { //!< Check if the node that will be pop'd is at the front
            tmpPrev->setNext(tmpNext); //!< Make current's node's previous node point to current's node's next node
            current = tmpPrev; //!< Set it as new current
            front = tmpPrev; //!< Set it as new front
        }
        else { //!< Check if the node that will be pop'd is at the back
            tmpNext->setPrev(tmpPrev); //< Make current's node's next node point to current's node's previous node
            current = tmpNext; //!< Set it as new current
            back = tmpNext; //!< Set it as new back
            
        }
        size--; //!< Decrement lists size
    }


    return result; //!< Return result data
}

template<class G>
G DoubleLinkedList<G>::popBack() //!< Removes back node
{
    G result;
    if (empty()) { //!< If list empty print generic message
        result = "Sorry there is nothing to remove";
    }
    else if (size == 1) { //!< If only one element is in the list assign everything to nullptr
        result = back->getData();  //!< Get result from back node

        front = nullptr;
        back = nullptr;
        current = nullptr;

        size--; //!< Decrement list size
    }
    else {
        result = back->getData(); //!< Get result from back node

        shared_ptr<DoubleLinkedListNode<G>> tmpNext = back->getNext(); //!< Make a pointer to back's node's next node
        shared_ptr<DoubleLinkedListNode<G>> tmpPrev = back->getPrev(); //!< Make a pointer to back's node's previous node

        if (current == back) { //!< If current is the same as back move current to next node
            current = tmpNext;
        }

        tmpNext->setPrev(tmpPrev); //< Make back's node's next node point to back's node's previous node
        back = tmpNext; //!< Set back's node's next node as new back node
        
        size--; //!< Decrement list size
    }
    return result;
}

template<class G>
G DoubleLinkedList<G>::popFront() //!< Removes front node
{
    G result;
    if (empty()) { //!< If list empty print generic message
        result = "Sorry there is nothing to remove";
    }
    else if(size == 1){ //!< If only one element is in the list assign everything to nullptr
        result = front->getData(); //!< Get result from front node

        front = nullptr;
        back = nullptr;
        current = nullptr;

        size--; //!< Decrement list size
    }
    else {
        result = front->getData(); //!< Get result from front node

        shared_ptr<DoubleLinkedListNode<G>> tmpNext = front->getNext(); //!< Make a pointer to fronts's node's next node
        shared_ptr<DoubleLinkedListNode<G>> tmpPrev = front->getPrev(); //!< Make a pointer to fronts's node's previous node

        if (current == front) { //!< If current is the same as front move current to next node
            current = tmpPrev;
        }

        tmpPrev->setNext(tmpNext); //!< Make front's node's previous node point to front's node's next node
        front = tmpPrev; //!< Set front's node's previous node as new front node

        size--; //!< Decrement list size
    }
    return result;
}

template<class G>
void DoubleLinkedList<G>::traverseForward() //!< Function that moves to the next node in the list
{
    if (empty()) { //!< If list empty print generic message
        cout << "Cannot traverse nothing." << endl;
    }
    else {
        if (current != front) { //!< Changes current node if it's not at the front
            current = current->getNext();
        }
        else { //!< If cannot travel further print generic message
            cout << "Cannot traverse further at the front." << endl;
        }
    }
}

template<class G>
void DoubleLinkedList<G>::traverseBackward() //!< Function that moves to the previous node in the list
{
    if (empty()) { //!< If list empty print generic message
        cout << "Cannot traverse nothing." << endl;
    }
    else {
        if (current != back) { //!< Changes current node if it's not at the back
            current = current->getPrev();
        }
        else { //!< If cannot travel further print generic message
            cout << "Cannot traverse further at the back." << endl;
        }
    }
}

template<class G>
G DoubleLinkedList<G>::getFront() //!< Function that returns front's/head's node's data
{
    G result;
    if (empty()) { //!< If list empty print generic message
        result = "There is nothing.";
    }
    else {
        result = front->getData();
    }

    return result;
}

template<class G>
G DoubleLinkedList<G>::getCurrent() //!< Function that returns current's node's data
{
    G result;
    if (empty()) { //!< If list empty print generic message
        result = "There is nothing.";
    }
    else {
        result = current->getData();
    }

    return result;
}

template<class G>
G DoubleLinkedList<G>::getBack() //!< Function that returns back's/tail's node's data
{
    G result;
    if (empty()) { //!< If list empty print generic message
        result = "There is nothing.";
    }
    else {
        result = back->getData();
    }

    return result;
}

template<class G>
unsigned int DoubleLinkedList<G>::getSize() //!< Function that returns how many items are in the list
{
    return size;
}

template<class G>
bool DoubleLinkedList<G>::empty() //!< Function that checks if list is empty
{
    return size == 0;
}
