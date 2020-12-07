#pragma once
#include <memory>

/*! \class Double Linked List Node
	\brief A double linked list data structures node
*/
using std::shared_ptr;

template <class G>
class DoubleLinkedListNode
{
private:
	G data; //!< The element held in the node
	shared_ptr<DoubleLinkedListNode<G>> next; //!< Next element in the dll
	shared_ptr<DoubleLinkedListNode<G>> prev; //!< Previous element in the dll
public:
	DoubleLinkedListNode(G newData, shared_ptr<DoubleLinkedListNode<G>> prev, shared_ptr<DoubleLinkedListNode<G>> next);
	~DoubleLinkedListNode();

	G getData();

	shared_ptr<DoubleLinkedListNode<G>> getNext();
	shared_ptr<DoubleLinkedListNode<G>> getPrev();

	void setNext(shared_ptr<DoubleLinkedListNode<G>>& newNext);
	void setPrev(shared_ptr<DoubleLinkedListNode<G>>& newPrev);
};

template<class G>
DoubleLinkedListNode<G>::DoubleLinkedListNode(G newData, shared_ptr<DoubleLinkedListNode<G>> newPrev, shared_ptr<DoubleLinkedListNode<G>> newNext)
{
	data = newData;
	next = newNext;
	prev = newPrev;
}

template<class G>
DoubleLinkedListNode<G>::~DoubleLinkedListNode()
{
}

template<class G>
G DoubleLinkedListNode<G>::getData()
{
	return data;
}

template<class G>
shared_ptr<DoubleLinkedListNode<G>> DoubleLinkedListNode<G>::getNext()
{
	return next;
}

template<class G>
shared_ptr<DoubleLinkedListNode<G>> DoubleLinkedListNode<G>::getPrev()
{
	return prev;
}

template<class G>
void DoubleLinkedListNode<G>::setNext(shared_ptr<DoubleLinkedListNode<G>>& newNext)
{
	next = newNext;
}

template<class G>
void DoubleLinkedListNode<G>::setPrev(shared_ptr<DoubleLinkedListNode<G>>& newPrev)
{
	prev = newPrev;
}
