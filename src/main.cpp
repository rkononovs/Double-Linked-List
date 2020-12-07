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
	myList.traverseForward();
	cout << myList.popCurrent() << endl;


	std::cout << myList.getSize() << std::endl;

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
