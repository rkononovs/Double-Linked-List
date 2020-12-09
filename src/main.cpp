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
	DoubleLinkedList<std::string> myList;
	
	myList.pushBack("I");
	myList.pushFront("am");
	myList.pushFront("testing");
	myList.pushBack("the");
	myList.pushBack("code");
	myList.pushBack("Thank");
	myList.pushBack("you!");
	
	myList.traverseForward();
	myList.traverseForward();
	//myList.pushAfterCurrent("Hope");
	myList.traverseForward();
	myList.pushAfterCurrent("me");
	
	
	myList.traverseBackward();
	myList.traverseBackward();
	myList.traverseBackward();
	myList.pushAfterCurrent("that");
	myList.traverseBackward();
	myList.traverseBackward();
	myList.traverseBackward();
	myList.traverseBackward();
	myList.pushAfterCurrent("will");
	
	
	//cout << myList.getBack() << endl;
	/*
	cout << "This is front" << myList.getFront() << endl;
	cout << "This is front" << myList.getCurrent() << endl;
	cout << "This is fron" << myList.getBack() << endl;

	cout << myList.popCurrent() << endl;
	cout << myList.popCurrent() << endl;
	cout << myList.popCurrent() << endl;
	cout << myList.popCurrent() << endl;
	cout << myList.popCurrent() << endl;
	cout << myList.popCurrent() << endl;
	//cout << myList.getFront() << endl;
	cout << myList.popCurrent() << endl;
	cout << myList.popCurrent() << endl;

	*/
	while (!myList.empty()) {
		cout << "This is front: " << myList.getFront() << endl;
		cout << "This is current: " << myList.getCurrent() << endl;
		cout << "This is back: " << myList.getBack() << endl;

		cout << myList.popFront() << endl;
	}


	std::cout << myList.getSize() << std::endl;

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
