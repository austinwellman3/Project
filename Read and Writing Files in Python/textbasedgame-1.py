Created by: Austin Wellman

# This is a text based quiz app based on methods
import time


# We are allowing user to enter "T", "t","True" or "F","f","False"
def setTrueAndFalse():
    true = ["T", "t", "True"]
    false = ["F", "f", "False"]
    # now we are returning them to main
    return true, false


# Asking user to enter his name so that and we will return this name to main for future use
def inputName():
    name = input("What's your name?")
    return name  # returning name here


# printing first question
def First():
    # printing question here
    print("\nParis is the captial of France.")
    choice = input(">>> ")
    # if user will choose true , we will return true in main
    if choice in true:
        return True
    else:
        # otherweise we will return false
        return False


# printing second question
def Second():
    print("\nThe Great Wall of China is visible from space.")
    choice = input(">>> ")
    # if user will choose true , we will return false ( As it's a wrong  options )  in main
    if choice in true:
        return False
    else:
        # otherwise we will return true ( for correct option)
        return True


# printing third  question
def Third():
    print("\nA woman has walked on the moon.")
    choice = input(">>> ")
    # if user will choose true , we will return false ( As it's a wrong  options )  in main
    if choice in true:
        return False
    else:
        # otherwise we will return true ( for correct option)

        return True


# printing fourth question
def Fourth():
    print("\nThe currency of France is the Franc")
    choice = input(">>> ")
    if choice in true:
        # if user will choose true , we will return false ( As it's a wrong  options )  in main
        return False
    else:
        # otherwise we will return true ( for correct option)

        return True


# this method will be used to print out the intro of program
def printIntro(name):
    print(
        "\nOK, " + name + ", let's get started. Remember, the following answers are only True or False.")


# we will compute scores here , if results will be "True " we will increment "correct" by 1

def computeScores(correct, results):
    if results:
        # incrementing by 1
        correct += 1
    return correct


# This method will be used to print out results of the whole quiz. we will pass name and correct scores as argument
# to this method
def printResults(name, correct):
    print(
        "\nYou're finished, " + name + ". You got", correct, "out of 4 correct.\n\n")
    # Saving results in txt file
    file = open("results.txt", "a+")
    # writing result in notepad file
    file.write("You got " + str(correct) + " out of 4 correct. \n")
    # closing files
    file.close()


# reading file and printing results
def print_all_results():
    # reading results.txt file's lines
    lines = open("results.txt", "r").readlines()
    i = 1
    print("\n\n")
    # looping through lines
    for line in lines:
        # printing line
        print(i, ".", line)
        i = i + 1
    print("\n\n")


if __name__ == '__main__':
    while True:
        ch = int(input("1. Play \n2. Check All Results \n3. Exit \nPlease Enter : "))

        if ch == 1:
            # initilizing true and false
            true, false = setTrueAndFalse()
            # initilizing correct scores by 0
            correct = 0
            # asking user to enter his name
            name = inputName()
            # printing intro
            printIntro(name)
            # asking question 1 and computing scores
            correct = computeScores(correct, First())
            # asking question 2 and computing scores
            correct = computeScores(correct, Second())
            # asking question 3 and computing scores
            correct = computeScores(correct, Third())
            # asking question 4 and computing scores
            correct = computeScores(correct, Fourth())
            # adding a sleep for 2 seconds
            time.sleep(2)
            # printing resuts
            printResults(name, correct)
        elif ch == 2:
            # if user chooses 2 then print results
            print_all_results()
        elif ch == 3:
            # if user chooses 3 then break
            break
        else:
            # if user have not selected 1 , 2 or 3
            print("Please enter correct option.")
