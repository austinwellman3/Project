// JUMANJI
// The insane adventure

#include <iostream>
#include <string>
//This is just showing what will be used and enabled in this code.... cout,cin,endl,string
using std::cout;
using std::cin;
using std::endl;
using std::string;
// The main section below is just giving a gold count for the loots and basically how the end of the story breaks down.
int main()
{
	const int GOLD_PIECES = 900;
	int adventurers, killed, survivors;
	string leader;

	//get the information
	//displaying first sign on
	cout << "Welcome to JUMANJI\n\n";
	cout << "Please enter the following for your personalized adventure\n";

	cout << "Enter a number: ";
	cin >> adventurers;

	cout << "Enter a number, smaller than the first: ";
	// cin is used to accept the input from the standard input device like keyboard etc...
	cin >> killed;
	// This line is creating variables and organizing the characters
	survivors = adventurers - killed;
	// cout is displaying
	cout << "Enter your last name: ";
	cin >> leader;

	//tell the story
	// The cout is displaying text and creating breaks
	cout << "\nA brave group of " << adventurers << " set out on a world of adventure ";
	cout << "-- in search of there Minds within the game they are so lost in. ";
	cout << "The group was led by a muscular bald man, " << leader << ".\n";

	cout << "\nAlong the way, a swarm of killer hornets the size of elephants ambushed the party. ";
	cout << "All fought bravely under the command of " << leader;
	cout << ", and the hornets were defeated, but at a cost. ";
	cout << "Of the adventurers, " << killed << " were vanquished, ";
	cout << "leaving just " << survivors << " in the group.\n";

	cout << "\nThe party was about to give up all hope. ";
	cout << "But while laying the deceased to rest, ";
	cout << "they stumbled upon the buried fortune. ";
	cout << "So the adventurers split " << GOLD_PIECES << " gold pieces.";
	cout << leader << " held on to the extra " << (GOLD_PIECES % survivors);
	cout << " pieces to keep things fair of course.\n";
	// code 0 is what ends the code
	return 0;
}
