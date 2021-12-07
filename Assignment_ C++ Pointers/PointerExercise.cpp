//Pointer Assignment
//Created By: Austin Wellman

#include <iostream>

using namespace std;

// This function is used to change the number well using the pointer
void change_number(int* val)
{
	// Change value to 15
	*val = 15;
}

// This function is used to change the character well using pointer
void change_character(char* val)
{
	// Change value to 'H'
	*val = 'H';
}

int main()
{
	// Store integer value 10 initially
	int number = 10;
	// Store integer variable (number) address (use pointer)
	int* number_ptr = &number;
	// Store character value 'A' initially
	char character = 'A';
	// Store character variable (character) address (use pointer)
	char* character_ptr=&character;

	// Print initial number value
	cout << "Initial number value: " << number << endl;
	// Print initial character value
	cout << "Initial character value: " << character << endl;
	
	// Change number using function
	change_number(number_ptr);
	// Change character using function
	change_character(character_ptr);
	cout << "\nAfter change" << endl;
	// Print number value after change
    cout << "new number value: "<<number<<endl;
	// Print character value after change
	cout << "new character value: " << character<<endl;
}
