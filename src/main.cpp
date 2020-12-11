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
	DoubleLinkedList<int> myListInt;
	DoubleLinkedList<std::string> myListString;


	myListInt.pushBack(10);
	myListInt.pushBack(100);
	myListInt.pushBack(15125);
	myListInt.pushBack(1255110);
	myListInt.pushBack(10743);
	myListInt.pushBack(11240);
	myListInt.pushBack(1120);
	myListInt.pushFront(1);
	myListInt.pushFront(3);

	cout << "Befor sorting: " << endl;
	myListInt.printList();
	
	myListInt.sortList();
	
	cout << "After sorting: " << endl;
	myListInt.printList();

	while (!myListInt.empty()) {
		cout << "This is front: ";
		myListInt.getFront();
		cout << "This is current: ";
		myListInt.getCurrent();
		cout << "This is back: ";
		myListInt.getBack();

		myListInt.popFront();
	}

	myListInt.popFront();

	/*
	myListString.pushBack("Hello");
	myListString.pushFront("World");
	myListString.pushFront("!");

	cout << "This is current: ";
	myListString.getCurrent();

	myListString.pushAfterCurrent("my");

	myListString.printList();

	for (int i = 0; 3 > i; i++) {
		myListString.traverseForward();
		cout << "This is current: ";
		myListString.getCurrent();
	}

	myListString.pushAfterCurrent("No");
	myListString.printList();
	myListString.pushBeforeCurrent("Yes");
	myListString.printList();

	myListString.traverseBackward();
	myListString.pushAfterCurrent("or");
	myListString.printList();

	myListString.traverseForward();
	myListString.traverseForward();
	myListString.popCurrent();

	myListString.printList();
	while (!myListString.empty()) {
		myListString.popBack();
		myListString.popFront();
	}
	*/
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
