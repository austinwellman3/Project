#include "ExceptionHandler.h"
#include <iostream>
#include <exception> // Standard library for exceptions
using namespace std;

void ExceptionHandler::RuntimeException() // This function is used to cause Runtime Exception 
{
	try
	{
		int y = 0; // Suppose user entered a 0 when taking input
		if (y == 0)
			throw y;	//Input was a 0 that caused the exception
		int x = 2/y; // Input was a non zero number
	}
	catch (int number)
	{
		cout << "Exception caught: " << "Division by zero" << endl;//Display the error exception message
	}

}

void ExceptionHandler::StandardRuntimeException() // This function is use to cause Runtime Exception using Standard built in exception
{
	try
	{
		int y = 0; // Suppose user entered a 0 when taking input
		if (y == 0)
			throw runtime_error("Runtime Exception caught"); //Input was a 0 that caused the exception
		int x = 2 / y; // Input was a non zero number
	}
	catch (runtime_error e)
	{
		cout << "Exception caught: " << e.what() << endl;//Display the error exception message
	}

}

void ExceptionHandler::OutofRangeException() // This function is use to cause Range Exception using Standard built in exception
{
	try
	{
		int arr[5];
		int index;
		index = 6; // Suppose user enters an index of value 6
		if (index < 0 || index > 4)	//Checking if the input is out of range or not
			throw out_of_range("Index out of range.");	//Throwing exception
		cout << "Value assigned successfully." << endl;
	}
	catch (out_of_range e)
	{
		cout <<"Exception caught: "<< e.what() << endl;//Display the error exception message
	}

}

void ExceptionHandler::BadAllocationException() // This function is use to cause Bad Allocation Exception
{
	try
	{
		int size;
		size = 999999999999999999; // Taking a size that an array cannot handle
		int* pBigDataArray = new int[size]; // Assigning that size to the user
	}
	catch (bad_alloc e)
	{
		cout << "Exception caught: " << e.what() << endl; //Display the error exception message
	}

}

void ExceptionHandler::ExceptionGenericCatch() // This function is use to catch any exception that may occur
{
	try
	{
		throw "Throwing Exception"; //Throwing a random exception
	}
	catch (...)
	{
		cout << "Exception caught by any catch method"<< endl;//Display the error exception message
	}

}


