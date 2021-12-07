import PySimpleGUI as app

# setting theme of app
app.theme('DarkAmber')

# setting widgets like text , buttons , inputtexts
widgets = [[app.Text('Print in Console App')],
           [app.Text('Enter something '), app.InputText()],
           [app.Button('Print in console '), app.Button('Close')]]

# setting title of app
win = app.Window('Sample application', widgets)

while True:
    # Checking if user clicked " Print in console  " or " cancel "
    event_ok_or_cancel, Value_of_event = win.read()
    if event_ok_or_cancel == app.WIN_CLOSED or event_ok_or_cancel == 'Close':
        break
    print('You entered ', Value_of_event[0])

win.close()