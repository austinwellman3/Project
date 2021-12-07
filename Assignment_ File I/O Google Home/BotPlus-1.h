#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class BotPlus
{
	private:
		int row_number = 0;
		ifstream ifile;
	public:
		void CreateFile(); //creates a new file
		void SearchFile(string item_name); // searches the data in a file
		void WriteFile(string item_name,string location); //writing the contents from a display to the file.
		void DisplayAllContent(); //read the contents of a text file and writes the contents from a file to the display.
};

