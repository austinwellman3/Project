# importing libraries
import sys
from PyQt5.Qt import *
from PyQt5.QtWebEngineWidgets import *
from PyQt5.QtWidgets import QApplication

# creating pyqt5 object
web_browser = QApplication(sys.argv)
# creating web browser object
webbrow = QWebEngineView()
# loading initial URL
webbrow.load(QUrl("https://www.google.com"))
# allowing window to display
webbrow.show()
sys.exit(web_browser.exec_())