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
	
	myList.addFront("Help");
	myList.addFront("Tasukete");
	myList.addFront("Me");

	std::cout << myList.popFront() << std::endl;
	std::cout << myList.popFront() << std::endl;
	std::cout << myList.popFront() << std::endl;
	std::cout << myList.getSize() << std::endl;
	std::cout << myList.popFront() << std::endl;

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
