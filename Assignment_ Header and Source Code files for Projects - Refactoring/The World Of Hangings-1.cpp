//The World Of Hangings
//Created by: Austin Wellman

// things used in code
#include <iostream>
#include <string>
// include own header file
#include "hangman.h"
using namespace std;


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

