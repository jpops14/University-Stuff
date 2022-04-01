# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'libGUI.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from http import client
from PyQt5 import QtCore, QtGui, QtWidgets
import library
import BookDialog
import ClientDialog
from PyQt5.QtWidgets import QMessageBox


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setWindowTitle("Library Manager")
        MainWindow.resize(1198, 879)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setTabletTracking(False)
        self.centralwidget.setObjectName("centralwidget")
        self.tabWidget = QtWidgets.QTabWidget(self.centralwidget)
        self.tabWidget.setGeometry(QtCore.QRect(10, 10, 931, 831))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.tabWidget.setFont(font)
        self.tabWidget.setTabletTracking(True)
        self.tabWidget.setTabShape(QtWidgets.QTabWidget.Rounded)
        self.tabWidget.setObjectName("tabWidget")
        self.Books = QtWidgets.QWidget()
        self.Books.setObjectName("Books")
        self.BookDetailsButton = QtWidgets.QPushButton(self.Books)
        self.BookDetailsButton.setGeometry(QtCore.QRect(220, 740, 491, 51))
        self.BookDetailsButton.setObjectName("BookDetailsButton")
        self.BookTable = QtWidgets.QTableWidget(self.Books)
        self.BookTable.setEnabled(True)
        self.BookTable.setGeometry(QtCore.QRect(0, 170, 941, 561))
        self.BookTable.setEditTriggers(
            QtWidgets.QAbstractItemView.NoEditTriggers)
        self.BookTable.setSelectionMode(
            QtWidgets.QAbstractItemView.SingleSelection)
        self.BookTable.setSelectionBehavior(
            QtWidgets.QAbstractItemView.SelectRows)
        self.BookTable.setObjectName("BookTable")
        self.BookTable.setColumnCount(3)
        self.BookTable.setRowCount(200)
        self.label_4 = QtWidgets.QLabel(self.Books)
        self.label_4.setGeometry(QtCore.QRect(10, 10, 151, 20))
        self.label_4.setObjectName("label_4")
        self.lineEdit = QtWidgets.QLineEdit(self.Books)
        self.lineEdit.setGeometry(QtCore.QRect(170, 50, 751, 25))
        self.lineEdit.setObjectName("lineEdit")
        self.comboBox = QtWidgets.QComboBox(self.Books)
        self.comboBox.setGeometry(QtCore.QRect(170, 110, 751, 25))
        self.comboBox.setObjectName("comboBox")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.Books)
        self.lineEdit_2.setGeometry(QtCore.QRect(170, 80, 751, 25))
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.Books)
        self.lineEdit_3.setGeometry(QtCore.QRect(170, 140, 751, 25))
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.label_5 = QtWidgets.QLabel(self.Books)
        self.label_5.setGeometry(QtCore.QRect(20, 60, 67, 17))
        self.label_5.setObjectName("label_5")
        self.label_6 = QtWidgets.QLabel(self.Books)
        self.label_6.setGeometry(QtCore.QRect(20, 90, 67, 17))
        self.label_6.setObjectName("label_6")
        self.label_7 = QtWidgets.QLabel(self.Books)
        self.label_7.setGeometry(QtCore.QRect(20, 110, 67, 17))
        self.label_7.setObjectName("label_7")
        self.label_8 = QtWidgets.QLabel(self.Books)
        self.label_8.setGeometry(QtCore.QRect(20, 140, 67, 17))
        self.label_8.setObjectName("label_8")
        self.tabWidget.addTab(self.Books, "")
        self.Friends = QtWidgets.QWidget()
        self.Friends.setObjectName("Friends")
        self.PersonTable = QtWidgets.QTableWidget(self.Friends)
        self.PersonTable.setEnabled(True)
        self.PersonTable.setGeometry(QtCore.QRect(0, 0, 941, 731))
        self.PersonTable.setEditTriggers(
            QtWidgets.QAbstractItemView.NoEditTriggers)
        self.PersonTable.setSelectionMode(
            QtWidgets.QAbstractItemView.SingleSelection)
        self.PersonTable.setSelectionBehavior(
            QtWidgets.QAbstractItemView.SelectRows)
        self.PersonTable.setObjectName("PersonTable")
        self.PersonTable.setColumnCount(3)
        self.PersonTable.setRowCount(200)
        self.ClientDetailsButton = QtWidgets.QPushButton(self.Friends)
        self.ClientDetailsButton.setGeometry(QtCore.QRect(220, 740, 491, 51))
        self.ClientDetailsButton.setObjectName("ClientDetailsButton")
        self.tabWidget.addTab(self.Friends, "")
        self.AddBookButton = QtWidgets.QPushButton(self.centralwidget)
        self.AddBookButton.setGeometry(QtCore.QRect(950, 100, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.AddBookButton.setFont(font)
        self.AddBookButton.setObjectName("AddBookButton")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(950, 40, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label.setFont(font)
        self.label.setTextFormat(QtCore.Qt.PlainText)
        self.label.setScaledContents(False)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(950, 220, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_2.setFont(font)
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.AddClientButton = QtWidgets.QPushButton(self.centralwidget)
        self.AddClientButton.setGeometry(QtCore.QRect(950, 280, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.AddClientButton.setFont(font)
        self.AddClientButton.setObjectName("AddClientButton")
        self.RemoveClientButton = QtWidgets.QPushButton(self.centralwidget)
        self.RemoveClientButton.setGeometry(QtCore.QRect(950, 340, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.RemoveClientButton.setFont(font)
        self.RemoveClientButton.setObjectName("RemoveClientButton")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(950, 570, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_3.setFont(font)
        self.label_3.setAlignment(QtCore.Qt.AlignCenter)
        self.label_3.setObjectName("label_3")
        self.BorrowBookButton = QtWidgets.QPushButton(self.centralwidget)
        self.BorrowBookButton.setGeometry(QtCore.QRect(950, 640, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.BorrowBookButton.setFont(font)
        self.BorrowBookButton.setObjectName("BorrowBookButton")
        self.ReturnBookButton = QtWidgets.QPushButton(self.centralwidget)
        self.ReturnBookButton.setGeometry(QtCore.QRect(950, 710, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.ReturnBookButton.setFont(font)
        self.ReturnBookButton.setObjectName("ReturnBookButton")
        self.RemoveBookButton = QtWidgets.QPushButton(self.centralwidget)
        self.RemoveBookButton.setGeometry(QtCore.QRect(950, 160, 231, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.RemoveBookButton.setFont(font)
        self.RemoveBookButton.setObjectName("RemoveBookButton")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        # functionality
        genres = ["", "Other", "Adventure", "Romance", "Horror",
                  "Classic", "History", "Comic book/Graphic novel",
                  "Crime/Mystery", "Fantasy", "Science Fiction",
                  "Horror", "Lifestyle", "Journalistic", "Self-Help",
                  "Theology", "Education", "Guides", "Crime"]
        self.comboBox.addItems(genres)
        self.comboBox.currentTextChanged.connect(self.refreshTables)
        self.refreshTables()
        self.AddClientButton.clicked.connect(self.AddClientClicked)
        self.AddBookButton.clicked.connect(self.AddBookClicked)
        self.RemoveBookButton.clicked.connect(self.removeBook)
        self.RemoveClientButton.clicked.connect(self.removePerson)
        self.BorrowBookButton.clicked.connect(self.borrow_Book)
        self.ReturnBookButton.clicked.connect(self.return_Book)
        self.BookDetailsButton.clicked.connect(self.bookDetails)
        self.ClientDetailsButton.clicked.connect(self.clientDetails)
        self.lineEdit.textChanged[str].connect(self.refreshTables)
        self.lineEdit_2.textChanged[str].connect(self.refreshTables)
        self.lineEdit_3.textChanged[str].connect(self.refreshTables)

        # visual adjustments

        hbid = QtWidgets.QTableWidgetItem()
        hbid.setText("Book ID")
        hpid = QtWidgets.QTableWidgetItem()
        hpid.setText("Client ID")
        hTitle = QtWidgets.QTableWidgetItem()
        hTitle.setText("Title")
        hPossession = QtWidgets.QTableWidgetItem()
        hPossession.setText("Possession")
        hName = QtWidgets.QTableWidgetItem()
        hName.setText("Name")
        hEmail = QtWidgets.QTableWidgetItem()
        hEmail.setText("email")

        self.PersonTable.setHorizontalHeaderItem(0, hpid)
        self.PersonTable.setHorizontalHeaderItem(1, hName)
        self.PersonTable.setHorizontalHeaderItem(2, hEmail)
        self.PersonTable.verticalHeader().setVisible(False)
        self.BookTable.setHorizontalHeaderItem(1, hbid)
        self.BookTable.setHorizontalHeaderItem(1, hTitle)
        self.BookTable.setHorizontalHeaderItem(2, hPossession)
        self.BookTable.verticalHeader().setVisible(False)

        pheader = self.PersonTable.horizontalHeader()
        pheader.setSectionResizeMode(0, QtWidgets.QHeaderView.ResizeToContents)
        pheader.setSectionResizeMode(1, QtWidgets.QHeaderView.Stretch)
        pheader.setSectionResizeMode(2, QtWidgets.QHeaderView.Stretch)

        bheader = self.BookTable.horizontalHeader()
        bheader.setSectionResizeMode(0, QtWidgets.QHeaderView.ResizeToContents)
        bheader.setSectionResizeMode(1, QtWidgets.QHeaderView.Stretch)
        bheader.setSectionResizeMode(2, QtWidgets.QHeaderView.Stretch)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.BookDetailsButton.setText(
            _translate("MainWindow", "Book Details"))
        self.label_4.setText(_translate("MainWindow", "Filtering parameters"))
        self.label_5.setText(_translate("MainWindow", "Title:"))
        self.label_6.setText(_translate("MainWindow", "Author:"))
        self.label_7.setText(_translate("MainWindow", "Genre:"))
        self.label_8.setText(_translate("MainWindow", "Tags:"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(
            self.Books), _translate("MainWindow", "Books"))
        self.ClientDetailsButton.setText(
            _translate("MainWindow", "Client Details"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(
            self.Friends), _translate("MainWindow", "Clients"))
        self.AddBookButton.setText(_translate("MainWindow", "Add Book"))
        self.label.setText(_translate("MainWindow", "Managing books"))
        self.label_2.setText(_translate("MainWindow", "Managing clients"))
        self.AddClientButton.setText(_translate("MainWindow", "Add Client"))
        self.RemoveClientButton.setText(
            _translate("MainWindow", "Remove Client"))
        self.label_3.setText(_translate("MainWindow", "Transactions"))
        self.BorrowBookButton.setText(_translate("MainWindow", "Borrow Book"))
        self.ReturnBookButton.setText(_translate("MainWindow", "Return Book"))
        self.RemoveBookButton.setText(_translate("MainWindow", "Remove Book"))
        self.lineEdit_3.setPlaceholderText("Input tags divided by\"#\"")

    def bookDetails(self):
        selbook = self.BookTable.selectionModel()
        if selbook.hasSelection():
            x = selbook.currentIndex().row()
            id = self.BookTable.item(x, 0)
            s = library.openSession()
            details = library.getBook(s, int(id.text()))
            QMessageBox.about(self.centralwidget,
                              "Selected Book Details", details)
            s.close()
        else:
            QMessageBox.about(self.centralwidget,
                              "Fail", "You have to select a book!")

    def clientDetails(self):
        selclient = self.PersonTable.selectionModel()
        if selclient.hasSelection():
            x = selclient.currentIndex().row()
            id = self.PersonTable.item(x, 0)
            s = library.openSession()
            details = library.getPerson(s, int(id.text()))
            QMessageBox.about(self.centralwidget,
                              "Selected Person Details", details)
            s.close()
        else:
            QMessageBox.about(self.centralwidget,
                              "Fail", "You have to select a client!")

    def return_Book(self):
        selbook = self.BookTable.selectionModel()
        if selbook.hasSelection():
            x = selbook.currentIndex().row()
            id = self.BookTable.item(x, 0)
            s = library.openSession()
            library.returnBook(s, int(id.text()))
            s.close()
            self.refreshTables()
            QMessageBox.about(self.centralwidget,
                              "Success", "Book returned succesfully!")
        else:
            QMessageBox.about(self.centralwidget,
                              "Error", "You have to select a book!")

    def removeBook(self):
        selbook = self.BookTable.selectionModel()
        if selbook.hasSelection():
            x = selbook.currentIndex().row()
            id = self.BookTable.item(x, 0)
            s = library.openSession()
            library.removeBook(s, int(id.text()))
            s.close()
            self.refreshTables()
        else:
            QMessageBox.about(self.centralwidget,
                              "Error", "You have to select a book!")

    def removePerson(self):
        selclient = self.PersonTable.selectionModel()
        if selclient.hasSelection():
            x = selclient.currentIndex().row()
            id = self.PersonTable.item(x, 0)
            s = library.openSession()
            library.removePerson(s, int(id.text()))
            s.close()
            self.refreshTables()
        else:
            QMessageBox.about(self.centralwidget,
                              "Fail", "You have to select a client!")

    def borrow_Book(self):
        selbook = self.BookTable.selectionModel()
        selclient = self.PersonTable.selectionModel()

        if selbook.hasSelection() and selclient.hasSelection():
            x = selbook.currentIndex().row()
            book = self.BookTable.item(x, 0)

            x = selclient.currentIndex().row()
            client = self.PersonTable.item(x, 0)

            s = library.openSession()
            res = library.borrowBook(s, int(client.text()), int(book.text()))
            if res is True:
                QMessageBox.about(self.centralwidget,
                                  "Success", "Book borrowed succesfully!")
            else:
                QMessageBox.about(self.centralwidget,
                                  "Fail", "Selected book is not availaible!")
            s.close()
            self.refreshTables()
        else:
            QMessageBox.about(self.centralwidget,
                              "Fail",
                              "You have to select a book and a client!")

    def AddBookClicked(self):
        dialog = QtWidgets.QDialog()
        ui = BookDialog.Ui_DialogBook()
        ui.setupUi(dialog, self)
        dialog.show()
        dialog.exec_()
        self.refreshTables

    def AddClientClicked(self):
        dialog = QtWidgets.QDialog()
        ui = ClientDialog.Ui_DialogAddClient()
        ui.setupUi(dialog, self)
        dialog.show()
        dialog.exec_()
        self.refreshTables

    def refreshTables(self):
        self.BookTable.setRowCount(0)
        self.BookTable.setRowCount(200)
        self.PersonTable.setRowCount(0)
        self.PersonTable.setRowCount(200)
        s = library.openSession()
        clients = s.query(library.Person).all()
        cap = 200
        i = 0
        for client in clients:
            if i >= cap:
                break
            self.PersonTable.setItem(
                i, 0, QtWidgets.QTableWidgetItem(str(client.person_id)))
            self.PersonTable.setItem(
                i, 1, QtWidgets.QTableWidgetItem(client.name))
            self.PersonTable.setItem(
                i, 2, QtWidgets.QTableWidgetItem(client.email))
            i += 1

        books = s.query(library.Book)
        if(self.comboBox.currentText() != ""):
            books = books.filter(library.Book.genre ==
                                 self.comboBox.currentText())
        if(self.lineEdit.text() != ""):
            books = books.filter(library.Book.title.ilike(
                '%' + self.lineEdit.text() + '%'))
        if(self.lineEdit_2.text() != ""):
            books = books.filter(library.Book.author.ilike(
                '%' + self.lineEdit_2.text() + '%'))
        if(self.lineEdit_3.text() != ""):
            for x in self.lineEdit_3.text().split("#"):
                books = books.filter(library.Book.book_tags.any(tag=x))
        i = 0
        for book in books.all():
            if i >= cap:
                break
            self.BookTable.setItem(
                i, 0, QtWidgets.QTableWidgetItem(str(book.book_id)))
            self.BookTable.setItem(
                i, 1, QtWidgets.QTableWidgetItem(book.title))
            self.BookTable.setItem(
                i, 2, QtWidgets.QTableWidgetItem(book.posession))
            i += 1
        s.close()


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
