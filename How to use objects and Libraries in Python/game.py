Created by: Austin Wellman

import random

# asking for user to enter name
name = input("Hello ! What is your name ? ")

# initilizing dictionary
summary = {"computer": 0, name: 0}

# looping until user wants to exit
flag = True
while flag:
    # initilizing scores with 0
    scores = 0

    print("\n__________________________________\n")
    # generating a random number between 1 and 20
    computer_guessed = random.randint(1, 20)
    player_guessed = 0

    print('Well, ' + name + ', I am thinking of a number between 1 and 20.')

    print("Your have 5 chances to guess it ! ")
    print("\n__________________________________\n")

    # It will loop for 5 times
    while scores < 5:
        # player will input a number
        player_guessed = int(input("Take a guess (" + str(scores + 1) + ") : "))
        # incrementing scores
        scores = scores + 1
        # checking if user entered less value than computerGuessed
        if player_guessed < computer_guessed:
            print('Your guess is too low!')
        # checking if user entered high value than computerGuessed
        if player_guessed > computer_guessed:
            print('Your guess is too high!')
        # checking if user entered same value
        if computer_guessed == player_guessed:
            break

    print("\n__________________________________\n")

    # checking if loop was break because of correct guess
    if computer_guessed == player_guessed:
        # incrementing in summary for player name
        summary[name] = summary[name] + 1
        print("Good Job " + name + " ! you guessed my number in  " + str(scores) + " guesses ! ")
    else:
        # or loop was break because user was not able to guess in 5 lives.
        print("Nah! The number I was thinking of was : " + str(computer_guessed))
        # incrementing in summary for computer
        summary["computer"] = summary["computer"] + 1

    print("\n__________________________________\n")
    # giving user an option to play again
    ch = input("Do you want to try again (y or n) : ")
    if ch.lower() == "n":
        flag = False

# Printing summary of all games here
print("\n__________________________________\n")
print("Summary : ")
for key in summary:
    print(key, " :  ", summary[key])
