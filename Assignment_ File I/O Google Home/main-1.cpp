// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BotPlus.h"
int main()
{
    int choice;
    BotPlus bot;
    bot.CreateFile();
    cout << "Hi i am your BotPlus. What did you forget..?" << endl;
	while (true)
	{
		//display a cool intro to the game
		cout << "Press 1 to Display All Content.\nPress 2 to Enter for a new Item.\nPress 3 to Search for an Item.\nPress 4 to exit.\n";
		cin >> choice;
		if (choice == 1) //Display All Content
		{
			bot.DisplayAllContent();
		}
		else if (choice == 2) //Enter an Item
		{
			cin.clear(); //Clearing the cin buffer to take input again in the loop
			cin.ignore();// discard 'bad' character(s)
			string item_name,location;
			cout << "Enter the name of Item: ";
			getline(cin, item_name);
			cout << "Enter the location: ";
			getline(cin, location);
			bot.WriteFile(item_name, location);
		}
		else if (choice == 3)//Search an Item
		{
			cin.clear(); //Clearing the cin buffer to take input again in the loop
			cin.ignore();// discard 'bad' character(s)
			string item_name;
			cout << "Enter the name of Item: ";
			getline(cin, item_name);
			bot.SearchFile(item_name);
		}
		else if (choice == 4)//Exit
		{
			cout << "Thank you.I know we'll meet again you'll forget something soon again.Pun Intended..!"<<endl;
			break;
		}
		else
		{
			cout << "Please select a valid choice." << endl;
			cin.clear(); //Clearing the cin buffer to take input again in the loop
			cin.ignore();// discard 'bad' character(s)
			continue;//Entering the loop again
		}

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
