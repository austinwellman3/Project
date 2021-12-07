"""
Project Description :

Made by: Austin Wellman

"""

# Importing libraries
from tkinter import *  # for GUI
import pickle  # for storing records


# This class will have GUI components like Buttons , labels , Entry etc
class ATM(Frame):

    def __init__(slf, bnk):
        # cosntructor
        Frame.__init__(slf)
        # setting title of frame
        slf.master.title("ATM MACHINE")
        # slf.master.geometry("250x110")
        slf.grid()
        slf._bnk = bnk
        slf.acnt = None
        # creating variables here for dynamic text values
        slf.varNam = StringVar()
        slf.varpin = StringVar()
        slf.varammount = DoubleVar()
        slf.varStatus = StringVar()

        # creating labels here
        slf.labelName = Label(slf, text="Name")
        slf.labelName.grid(row=0, column=0)
        slf.labelpin = Label(slf, text="PIN")
        slf.labelpin.grid(row=1, column=0)
        slf.labelammount = Label(slf, text="Amount")
        slf.labelammount.grid(row=2, column=0)
        slf.labelstatus = Label(slf, text="Status", fg="red")
        slf.labelstatus.grid(row=3, column=0)

        # input field for name
        slf.entrynam = Entry(slf, textvariable=slf.varNam, justify=CENTER)
        slf.entrynam.grid(row=0, column=1)

        # input field for pin
        slf.entrypin = Entry(slf, textvariable=slf.varpin, justify=CENTER)
        slf.entrypin.grid(row=1, column=1)

        # input field for amount
        slf.entryamount = Entry(slf, textvariable=slf.varammount, justify=CENTER)
        slf.entryamount.grid(row=2, column=1)

        # input field for status
        slf.entrystatus = Entry(slf, textvariable=slf.varStatus, justify=CENTER, bg="yellow", fg="red")
        slf.entrystatus.grid(row=3, column=1)

        # creating buttons for checking balance
        slf.button_for_balance = Button(slf, text="Balance", command=slf.get_user_balance)
        # setting state to disable so that user can't add something there
        slf.button_for_balance["state"] = DISABLED
        slf.button_for_balance.grid(row=0, column=2)

        # creating buttons for depositing amount
        slf.button_for_deposit = Button(slf, text="Deposit", command=slf.deposit_amount_in_bank)
        slf.button_for_deposit["state"] = DISABLED
        slf.button_for_deposit.grid(row=1, column=2)

        # creating buttons for withdrawl
        slf.button_for_withdraw = Button(slf, text="Withdraw", command=slf.withdraw_amount_from)
        slf.button_for_withdraw["state"] = DISABLED
        slf.button_for_withdraw.grid(row=2, column=2)

        # creating buttons for Login
        slf.button_for_login = Button(slf, text="Login", command=slf.login_to_account)
        slf.button_for_login.grid(row=3, column=2)

    def get_user_balance(slf):
        # getting user's current balance and putting on status bar
        slf.varStatus.set("Your balance is $%0.2f" % (slf.acnt.getBalance()))

    def deposit_amount_in_bank(slf):
        # first we will read amount user has entered
        amnt = slf.varammount.get()
        print(amnt)
        # now we will pass that value to
        slf.acnt.deposit(amnt)
        slf.varStatus.set("Deposited!")

    def withdraw_amount_from(slf):
        # passing inputted value of user to withdraw method
        amnt = slf.varammount.get()

        msg = slf.acnt.withdraw(amnt)
        # checking if there was any error we will set it in status bar
        if msg:
            slf.varStatus.set(msg)
        else:
            slf.varStatus.set("Withdrawal Completed!")

    def login_to_account(slf):
        PINCODE = slf.varpin.get()
        NAME = slf.varNam.get()
        slf.acnt = slf._bnk.get_data_for_specific_pin(PINCODE)
        print(slf.acnt)
        if slf.acnt:
            if NAME == slf.acnt.getName():
                slf.varStatus.set("Welcome to the bank!")
                slf.button_for_deposit["state"] = NORMAL
                slf.button_for_withdraw["state"] = NORMAL
                slf.button_for_login["text"] = "Logout"
                slf.button_for_login["command"] = slf.logout_from_atm
                slf.button_for_balance["state"] = NORMAL

            else:
                slf.varStatus.set("Unrecognized User Name")
                slf.acnt = None
        else:
            slf.varStatus.set("Unrecognized Account's PIN")

    def logout_from_atm(slf):
        # Logging out means we need to set everything to their initial state
        slf.button_for_balance["state"] = DISABLED
        slf.button_for_deposit["state"] = DISABLED
        slf.button_for_withdraw["state"] = DISABLED
        slf.acnt = None
        slf.varNam.set("")
        slf.varammount.set(0.0)
        slf.varpin.set("")
        slf.button_for_login["command"] = slf.login_to_account
        slf.varStatus.set("Have a nice day!")
        slf.button_for_login["text"] = "Login"


# class for saving account
class SavingsAccount(object):
    # setting interest rate
    at_rate = 0.02

    # constructor
    def __init__(slf, n, p, blnc=0.0):
        slf.NAME = n
        slf.PIN = p
        slf.BLNC = blnc

    # returning all attributes in  string format
    def __str__(slf):
        return 'Name:    ' + slf.NAME + '\n' + 'PIN:     ' + slf.PIN + '\n' + 'Balance: ' + str(slf.BLNC)

    # getter method for Balance
    def getBalance(slf):
        return slf.BLNC

    # getter method for Name
    def getName(slf):
        return slf.NAME

    # getter method for PIN
    def getPin(slf):
        return slf.PIN

    # setter method for deposit
    def deposit(slf, amnt):
        # incrementing
        slf.BLNC = slf.BLNC + amnt
        return slf.BLNC

    # Withdraw method to withdraw ( deduct) amount from total amount
    def withdraw(slf, amnt):
        returning = ""
        # checking if amount is less than 0
        if amnt < 0:
            returning = 'Amount must be >= 0'
        # or if it is greater than total amount
        elif slf.BLNC < amnt:
            returning = 'Insufficient funds'
        else:
            # otherwise we will deduct from total amount
            slf.BLNC -= amnt
            returning = None
        return returning

    # This method will be used to compute Interests
    def computeInterest(slf):

        # calculating interest here
        interest_rate = slf.BLNC * SavingsAccount.at_rate
        slf.deposit(interest_rate)
        return interest_rate


# This is a class that will handle Bank
# Bank will have multiple accounts and all of that infomration is stored in pickle file
class Bank(object):
    def __init__(slf, fN=None):

        # dictionary to store list of all accounts
        slf.acnt = {}
        slf.fN = fN
        if fN is not None:
            fileObj = open(fN, 'rb')
            while True:
                try:
                    # reading pickle here
                    accont = pickle.load(fileObj)
                    slf.add_to(accont)
                except EOFError:
                    fileObj.close()
                    break
        # printing here
        for ac in slf.acnt:
            print(slf.acnt[ac])

    def __str__(slf):
        # this will make a string of information
        x = '\n'.join(map(str, slf.acnt.values()))
        return x

    # this will add PIN to that specific account
    def add_to(slf, acnt):
        slf.acnt[acnt.getPin()] = acnt

    # this will remove account
    def rem_account(slf, account_pin):
        return slf.acnt.pop(account_pin, None)

    # this will return the data for specific account with resepect to specific PIN
    def get_data_for_specific_pin(slf, account_pin):
        return slf.acnt.get(account_pin, None)

    # This method will be used to compute interests
    def computeInterest(slf):
        t_interest = 0.0
        for acnt in slf.acnt.values():
            t_interest = t_interest + acnt.computeInterest()
        return t_interest

    # at the end we will again save data to pickle
    def save_to_dat(slf, fileName=None):
        if fileName is not None:
            slf.fN = fileName
        elif slf.fN is None:
            return
        fobj = open(slf.fN, 'wb')
        for acnt in slf.acnt.values():
            pickle.dump(acnt, fobj)
        fobj.close()

# main method that will initiate whole process
def main():
    bnk = Bank('bank1.dat')

    atm_machine = ATM(bnk)
    atm_machine.mainloop()

    bnk.save_to_dat()


def create_a_bank(number=0):
    bnk = Bank()
    for i in range(number):
        bnk.add_to(SavingsAccount('Name' + str(i + 1), str(1000 + i), 100.00))
    bnk.save_to_dat("bank1.dat")


main()
