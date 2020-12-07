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
	
	/*
	myList.pushFront("you!");
	myList.pushFront("Thank");
	myList.pushFront("code.");
	myList.pushFront("the");
	myList.pushFront("testing");
	myList.pushFront("am");
	myList.pushFront("I");
	*/
	//myList.pushBack("Please");
	myList.pushBack("I");
	myList.pushBack("am");
	myList.pushBack("testing");
	myList.pushBack("the");
	myList.pushBack("code");
	myList.pushBack("Thank");
	myList.pushBack("you!");
	

	//std::cout << myList.popBack() << std::endl;

	std::cout << myList.popFront() << std::endl; 
	std::cout << myList.popFront() << std::endl;
	//std::cout << myList.popCurrent() << std::endl;
	std::cout << myList.popBack() << std::endl;
	std::cout << myList.popFront() << std::endl;
	std::cout << myList.popFront() << std::endl;
	std::cout << myList.popFront() << std::endl;
	std::cout << myList.popFront() << std::endl;


	std::cout << myList.getSize() << std::endl;

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
