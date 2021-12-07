Created by: Austin Wellman

if __name__ == '__main__':
    # printing header
    all_work = {}
    all_work['sum'] = []
    all_work['print'] = []
    print('*** Welcome to the Learn Python Because it is Really Cool Tutorial ***\n')

    # menu
    while (True):
        print("What do you want to learn today ? ")
        print("1. Print Command ")
        print("2. Sum Command")
        print("3. Exit")
        ch = int(input())

        # If user will chose "1"
        if ch == 1:

            # print out the "print" tutorial

            print('In this lesson, we are going to master the "print" command in Python.')
            print('Are you ready?')

            print('Here is the syntax for the "print" command in Python \nprint("Text to display on the screen") ')
            print('\n----------------------------\n')

            print('print("I am the HAL 9000 Computer")')
            print('The following would display in your application')

            print('I am the HAL 9000 Computer')

            print('\n----------------------------\n')

            print("Let's try 'print' command :  ")
            while True:
                # will ask for user to input a string which he wants to print
                to_print = input("Please Enter a string which you want to print (To stop press : q ): ")

                # if user will enter q we will break this loop
                if to_print == "q":
                    break
                print("print('" + to_print + "')")
                print("Output : " + to_print)
                all_work['print'].append("print('" + to_print + "')")

                # if user will choose 2
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
            print("Let's try 'sum' command :  ")

            while True:
                to_find_sum = []
                # will ask user to enter length of list which he wants to add
                a = input("Please Enter length of list(To stop press q) : ")

                # if user will enter q , we will break this loop
                if a == "q":
                    break

                # this loop will run for "length" which user have entered to populate list
                for i in range(int(a)):
                    e = input("Pleae Enter Int  " + str(i) + ": ")
                    to_find_sum.append(e)
                #     printing sum(LIST) here
                print("sum([" + " , ".join(x for x in to_find_sum) + "])")

                new_int_list = []
                # convert str_list to int_list
                for item in to_find_sum:
                    new_int_list.append(int(item))

                # actually doing sum for that list here
                print(sum(new_int_list))
                all_work["sum"].append("sum([" + " , ".join(x for x in to_find_sum) + "])")

        else:
            break

    # summary
    print('\n----------------------------\n')

    print("Summary : ")
    i = 1
    for key in all_work:
        for value in all_work[key]:
            print(i, " . ", value)
            i = i + 1
    print('\n----------------------------\n')


    # asking user to enter his feedback

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
