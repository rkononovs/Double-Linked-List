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
    void addFront(G newElement);
    void addBack(G newElement);
    void addAfterCurrent(G newElement);
    void addBeforeCurrent(G newElement);

    void popCurrent();
    void popBack();
    void popFront();

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
        back = tmp;
        current = tmp;
    }

    size++;
}
template<class G>
void DoubleLinkedList<G>::addBack(G newElement)
{   
    shared_ptr<DoubleLinkedListNode<G>> tmp(new DoubleLinkedListNode<G>(newElement));
    if (empty()) {
        front = tmp;
        back = tmp;
        current = tmp;
    }
    else {
        back
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

}

template<class G>
void DoubleLinkedList<G>::popFront()
{
}

template<class G>
bool DoubleLinkedList<G>::empty()
{
    return size == 0;
}
