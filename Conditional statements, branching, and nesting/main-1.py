if __name__ == '__main__':
    # printing header
    print('*** Welcome to the Learn Python Because it is Really Cool Tutorial ***\n')

    # menu
    while True:
        print("What do you want to learn today ? ")
        print("1. Print Command ")
        print("2. Sum Command")
        print("3. Exit")
        ch = int(input())
        if ch == 1:

            print('In this lesson, we are going to master the "print" command in Python.')
            print('Are you ready?')

            print('Here is the syntax for the "print" command in Python \nprint("Text to display on the screen") ')
            print('\n----------------------------\n')

            print('print("I am the HAL 9000 Computer")')
            print('The following would display in your application')

            print('I am the HAL 9000 Computer')

            print('\n----------------------------\n')



        elif ch == 2:
            print('In this lesson, we are going to master the "sum" command in Python.')
            print('Are you ready?')

            print('\n----------------------------\n')

            print('Here is the syntax for the "sum" command in Python \nsum((1,2,3,4,5)) ')
            print('\n----------------------------\n')

            print('\nsum( (10,20,30,40) )')
            print('The following would return ')
            print('100')

            print('\n----------------------------\n')

        else:
            break
    print("Please leave us your feedback : ")
    p = ""
    s = ""
    for n in range(2):
        if n == 0:
            p = input("Do you understand how to use 'print' command ? ")
        else:
            s = input("Do you understand how to use 'sum' command ? ")

    print("Your feedback for 'print' : " + p + " and for 'sum' : " + s)
    print('\n----------------------------\n')

    print('Have a nice day!')
