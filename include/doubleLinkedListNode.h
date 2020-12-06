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
	DoubleLinkedListNode(G newData);
	G getData();
	void setNext(shared_ptr<DoubleLinkedListNode<G>>& newNext);
	void setPrev(shared_ptr<DoubleLinkedListNode<G>>& newPrev);
};

template<class G>
DoubleLinkedListNode<G>::DoubleLinkedListNode(G newData)
{
	data = newData;
	next = nullptr;
	prev = nullptr;
}

template<class G>
G DoubleLinkedListNode<G>::getData()
{
	return data;
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
