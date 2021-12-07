// Work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "ExceptionHandler.h" // Including the header file of ExceptionHandler class

int main()
{
    ExceptionHandler e1;
	e1.RuntimeException();
	e1.StandardRuntimeException();
	e1.OutofRangeException();
	e1.BadAllocationException();
	e1.ExceptionGenericCatch();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

