// Keywords
// assigned at the CIA to code a simple Code Breaker Training Simulation Program for CIA Recruits
// Created by: Austin Wellman

//things used in code
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
//main source code section
int main()
{
    //amount of words to be used and the fields
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 10;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        //the 10 words I pick
        {"apple", "what is a teachers favorite fruit?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."},
        {"hammer", "You are going to nail this."},
        {"pneumonoultramicroscopicsilicovolcanoconiosis", "You might wanna stay away from the volcano."},
        {"inhale", "take a breather."},
        {"agua", "it helps plants grow."},
        {"headache", "to much time on the computer screen?"}
    };
    //displaying the intro
    cout << "\t\t\tWelcome to Keywords!\n\n";
    cout << "This is a program for new recruits within the CIA to practice code breaking skills.\n";
    int i = 0;
    while (i < 3)
    {
        //setting the hints and making sure its random words generated
        srand(static_cast<unsigned int>(time(0)));
        int choice = (rand() % NUM_WORDS);
        string theWord = WORDS[choice][WORD];  // word to guess
        string theHint = WORDS[choice][HINT];  // hint for word

        string Keyword = theWord;  // mixed up version of word
        int length = Keyword.size();
        for (int i = 0; i < length; ++i)
        {
            int index1 = (rand() % length);
            int index2 = (rand() % length);
            char temp = Keyword[index1];
            Keyword[index1] = Keyword[index2];
            Keyword[index2] = temp;
        }
        //more visuals
        cout << "\n\nEnter 'hint' for a hint.\n";
        cout << "Enter 'quit' to quit the game.\n\n";
        cout << "The Keyword is: " << Keyword;

        string guess;
        cout << "\n\nYour guess: ";
        cin >> guess;
        //quits game
        while ((guess != theWord) && (guess != "quit"))
        {
            if (guess == "hint")
            {
                cout << theHint;
            }
            else
            {
                cout << "Sorry, that's not it.";
            }

            cout << "\n\nYour guess: ";
            cin >> guess;
        }

        if (guess == theWord)
        {
            cout << "\nThat's it!  You guessed it!\n";
        }
        else if (guess == "quit")
            break;
        i++;
    }
    cout << "\nTraining Complete.\n";

    return 0;
}
