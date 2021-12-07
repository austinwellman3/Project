//CodeHunter
// This library includes the code which allows us to do input and output to the console.
#include <iostream>
// This library includes the code to allow us to work with strings
#include <string>
// This keeps us from having to type std in front of the many C++ commands we are using
using namespace std;

// The first functions ran when C++ Starts, the entry point to your program.
int main()
{
	// This variable holds the text we will type in for analysis.
	string textToAnalyze;
	// unNeeded code
	// int foo = 0;    ***
	// Tracks the number of the specified things in text.
	int vowels = 0;
	int consonants = 0;
	int digits = 0;
	int spaces = 0;
	int lengthOfStringSubmittedForAnalysis = 0;
	int unknownCharacters = 0;
	int checkSum = 0;
	int bar = 0;

	cout << "Welcome to the CIA code Hunter Program!" << endl;
	cout << "Please type in text to analyze: " << endl;
	// Get's the line of text from the user and stuff's it into the variable textToAnalyze
	getline(cin, textToAnalyze);
	// This loop goes one character at a time and figures out what type of character it is.
	for (int i = 0; i < textToAnalyze.length(); ++i)
	{
		// This will add one to the vowel count if the current character being evaluated is a vowel.
		if (textToAnalyze[i] == 'a' || textToAnalyze[i] == 'e' || textToAnalyze[i] == 'i' ||
			textToAnalyze[i] == 'o' || textToAnalyze[i] == 'u' || textToAnalyze[i] == 'A' ||
			textToAnalyze[i] == 'E' || textToAnalyze[i] == 'I' || textToAnalyze[i] == 'O' ||
			textToAnalyze[i] == 'U')
		{
			// BUG: add++ and delete the -- for vowels.. This make it not be negative values.
			++vowels;
		}
		else if ((textToAnalyze[i] >= 'a' && textToAnalyze[i] <= 'z') || (textToAnalyze[i] >= 'A' && textToAnalyze[i] <= 'Z'))
		{
			// BUG: consonants was commented out. Program could not read.
			++consonants;
		}
		else if (textToAnalyze[i] >= '0' && textToAnalyze[i] <= '9')
		{
			++digits;
		}
		else if (textToAnalyze[i] == ' ')
		{
			++spaces;
		}
		else
		{
			++unknownCharacters;
		}
		
	}

	lengthOfStringSubmittedForAnalysis = textToAnalyze.length();
	checkSum = unknownCharacters + vowels + consonants + digits + spaces;

	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "White spaces: " << spaces << endl;
	cout << "Length of string submitted for analysis: " << lengthOfStringSubmittedForAnalysis << endl;
	cout << "Number of characters CodeHunter could not identify: " << unknownCharacters << endl;
	cout << "Checksum: " << checkSum << endl;

	if (checkSum == lengthOfStringSubmittedForAnalysis)
	{
		cout << "This program self checking has found this Analysis to be valid." << endl;
	}
	else
	{
		cout << "WARNING! *** This program self checking has found this Analysis to be invalid! Do not use this data!" << endl;
	}

	system("pause");

	return 0;
}