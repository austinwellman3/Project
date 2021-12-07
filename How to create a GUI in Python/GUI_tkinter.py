from tkinter import *


# This method will be called on "Add" button click
def add():
    t3.delete(0, 'end')
    num1 = int(t1.get())
    num2 = int(t2.get())
    result = num1 + num2
    t3.insert(END, str(result))


# This method will be called on "Substract: button click
def sub(event):
    t3.delete(0, 'end')
    num1 = int(t1.get())
    num2 = int(t2.get())
    result = num1 - num2
    t3.insert(END, str(result))


# creating Tk object
gui = Tk()
# setting labels for entries
lbl1 = Label(gui, text='First number')
lbl2 = Label(gui, text='Second number')
lbl3 = Label(gui, text='Result')
# putting input fields
t1 = Entry(bd=3)
t2 = Entry()
t3 = Entry()
# putting buttons
btn1 = Button(gui, text='Add')
btn2 = Button(gui, text='Subtract')
# setting label's locations ( x , y) coordinated
lbl1.place(x=100, y=50)
t1.place(x=200, y=50)
lbl2.place(x=100, y=100)
t2.place(x=200, y=100)
# adding buttons
b1 = Button(gui, text='Add', command=add)
b2 = Button(gui, text='Subtract')
b2.bind('<Button-1>', sub)
# setting button's locations
b1.place(x=100, y=150)
b2.place(x=200, y=150)
lbl3.place(x=100, y=200)
t3.place(x=200, y=200)

# setting title of window
gui.title('Add / Substract ')
gui.geometry("400x300")
gui.mainloop()
