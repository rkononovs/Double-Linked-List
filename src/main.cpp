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


	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
