#pragma once
#include <memory>

/*! \class Double Linked List Node
	\brief A double linked list data structures node
*/
using std::shared_ptr;

template <class G>
class doubleLinkedListNode
{
private:
	G data; //!< The element held in the node
	shared_ptr<doubleLinkedListNode<G>> next; //!< Next element in the dll
	shared_ptr<doubleLinkedListNode<G>> prev; //!< Previous element in the dll
public:
	doubleLinkedListNode();
	G getData();
};