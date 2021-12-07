// the wrongs below are displaying the hangman on incorrect guesses and how to display it.
#include <iostream>
#include <string>

using namespace std;

void drawHangman(int wrong, string word) {
    // prints on wrong guess
    if (wrong == 1) {
        cout << "I" << endl;
        cout << "I" << endl;
        cout << "I" << endl;
    }
    else if (wrong == 2) {
        cout << "I==" << endl;
        cout << "I" << endl;
        cout << "I" << endl;
        cout << "I" << endl;
        cout << "I" << endl;
    }
    else if (wrong == 3) {
        cout << "I===" << endl;
        cout << "I  O" << endl;
        cout << "I" << endl;
        cout << "I" << endl;
        cout << "I" << endl;
    }
    else if (wrong == 4) {
        cout << "I===" << endl;
        cout << "I  O" << endl;
        cout << "I -|-" << endl;
        cout << "I" << endl;
        cout << "I" << endl;
    }
    else if (wrong == 5) {
        cout << "I===" << endl;
        cout << "I  O" << endl;
        cout << "I -|-" << endl;
        cout << "I /" << endl;
        cout << "I" << endl;
    }
    // this is the last guess you can get wrong. if you get wrong it also displays a message.
    else if (wrong == 6) {
        cout << "I===" << endl;
        cout << "I  O" << endl;
        cout << "I -|-" << endl;
        cout << "I / \\" << endl;
        cout << "I YOUR Partner is DEAD" << endl;
        cout << "Game Failed. The word was: " << word << endl;
    }
}

string takeInput(string msg) {
    // takes input by showing user a message
    string in;
    cout << msg;
    cin >> in;
    return in;
}

string takeGuess() {
    //takes guess from user and ensures it is a single character
    string in;
    in = takeInput("Enter your guess: ");

    //If the guess isnt a letter
    while (in.size() != 1) {
        in = takeInput("You Enter wrong data, string must be of length 1 Try Again: ");
    }
    return in;
}

int checkGuess(string letter, string word) {
    // find the first occrance of guess in word
    return word.find(letter);
}

string replaceAll(string underscore, char guess, string word) {
    // replace all occurance of guessed word
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == guess)
            underscore[i] = guess;
    }
    return underscore;
}