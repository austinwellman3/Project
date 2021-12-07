//Hacked bank balance
//Created By: Austin Wellman

#include <iostream>

using namespace std;

void normal_balance_check(int a, int b);
void hacked_balance_check(int& a, int& b);
void swap(int& a, int& b);

int main()
{
	// Store initial terrorist balance (10000)
	int terrorist_balance = 10000;
	// Store initial joe's shop balance (20000)
	int joe_balance = 20000;

	
    cout << "Bank Balance"<<endl;
	// Call normal balance
	normal_balance_check(terrorist_balance, joe_balance);
	cout << "\nHacked Bank Balance" << endl;
	// Call hacked balance
	hacked_balance_check(terrorist_balance, joe_balance);
}

// This method is used for normal bank balance
void normal_balance_check(int a, int b)
{
	// Print terrorist account balance
	cout << "Terrorist account balance: " << a << endl;
	// Print Joe's coffee shop account balance
	cout << "Joe's Coffee Shop balance: " << b << endl;
}

// This method is used for hacked transaction balance
void hacked_balance_check(int& a, int& b)
{
	// switch the funds in the terrorist account with the funds of Joe's Coffee Shop 
	swap(a, b);
	// Print terrorist account balance
	cout << "Terrorist account balance: " << a << endl;
	// Print Joe's coffee shop account balance
	cout << "Joe's Coffee Shop balance: " << b << endl;
}

// This method is used for swap the number
void swap(int& a, int& b)
{
	// Store 'a' reference temporary 
	int t = a;
	// Assign 'b' to 'a'
	a = b;
	// Assign 'temporary' to 'b'
	b = t;
}



