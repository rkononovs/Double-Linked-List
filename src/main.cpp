/**
@file main.cpp
*/


/*! \mainpage Lab Book 3
 *
 * Implementation of a Double Linked List
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "doubleLinkedList.h"

void main() /** Entry point for the application */
{
	DoubleLinkedList<int> myList;

	myList.pushBack(1);
	myList.pushFront(10);
	myList.pushFront(3);

	myList.printList();
	
	while (!myList.empty()) {
		cout << "This is front: ";
		myList.getFront();
		cout << "This is current: ";
		myList.getCurrent();
		cout << "This is back: ";
		myList.getBack();

		myList.popFront();
	}

	myList.popFront();

	std::cout << myList.getSize() << std::endl;

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
