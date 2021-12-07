//The World Of Hangings
//Created by: Austin Wellman

// things used in code
#include <iostream>
#include <string>
using namespace std;

// the wrongs below are displaying the hangman on incorrect guesses and how to display it.
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

int main() {

    // declaring variables
    string player1, player2, word, underscore, guess;
    int wrong = 0;

    // initializing variables
    // intro to the game
    string copy = word;
    cout << "You and your partner are in trouble" << endl;
    cout << "Enemy: Welcome to the world of hangings" << endl;
    // inputting players names
    player1 = takeInput("Please type your name: ");
    player2 = takeInput("Please type your partners name: ");
    // more displayed text
    cout << "Enemy: Nobody can get out from here unless you clear my game\n";
    cout << "You: Oh really, whats the game" << endl;
    cout << "Enemy: I'll ask your partners favorite fruit name and you will have to guess that name\n" << endl;

    // is taking inputted word needed to be guessed and who is guessing it
    word = takeInput(player2 + " input the word you want " + player1 + " to guess: ");
    //system("clear");

    cout << "Enemy: Be careful!!! If you fail to guess, Your partner will die\n";
    //UNDERSCORE
    //initializing blank field to show the user
    while (underscore.size() != word.size()) {
        underscore.push_back('_');
    }

    //MAIN WHILE
    while (wrong < 6) {
        cout << "\n" << underscore << endl;
        guess = takeGuess();

        int correct = checkGuess(guess, word);

        if (correct >= 0)
        {
            underscore = replaceAll(underscore, guess[0], word);
            //system("clear");
        }
        else
        {
            //system("clear");
            cout << "You Guessed Wrong\n";
            wrong++;
        }

        // displayed if won
        if (underscore == word) {
            cout << "You win! You can go" << endl;
            break;
        }
        drawHangman(wrong, word);
    }
}

