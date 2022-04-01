# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'DialogAddClient.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets
import library
import libgui
from PyQt5.QtWidgets import QMessageBox


class Ui_DialogAddClient(object):
    def setupUi(self, DialogAddClient, mainwindow):

        DialogAddClient.setObjectName("DialogAddClient")
        DialogAddClient.resize(586, 171)
        self.parent = mainwindow
        self.ConfirmClientButton = QtWidgets.QPushButton(DialogAddClient)
        self.ConfirmClientButton.setGeometry(QtCore.QRect(0, 110, 581, 25))
        self.ConfirmClientButton.setObjectName("ConfirmClientButton")
        self.CloseClientButton = QtWidgets.QPushButton(DialogAddClient)
        self.CloseClientButton.setGeometry(QtCore.QRect(0, 140, 581, 25))
        self.CloseClientButton.setObjectName("CloseClientButton")
        self.label = QtWidgets.QLabel(DialogAddClient)
        self.label.setGeometry(QtCore.QRect(270, 10, 101, 17))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(DialogAddClient)
        self.label_2.setGeometry(QtCore.QRect(10, 40, 91, 21))
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(DialogAddClient)
        self.label_3.setGeometry(QtCore.QRect(10, 80, 91, 21))
        self.label_3.setObjectName("label_3")
        self.NameField = QtWidgets.QLineEdit(DialogAddClient)
        self.NameField.setGeometry(QtCore.QRect(90, 30, 491, 31))
        self.NameField.setObjectName("NameField")
        self.EmailField = QtWidgets.QLineEdit(DialogAddClient)
        self.EmailField.setGeometry(QtCore.QRect(90, 70, 491, 31))
        self.EmailField.setObjectName("EmailField")

        self.retranslateUi(DialogAddClient)
        QtCore.QMetaObject.connectSlotsByName(DialogAddClient)

        # functionality
        self.CloseClientButton.clicked.connect(DialogAddClient.close)
        self.ConfirmClientButton.clicked.connect(self.AddClient)

    def AddClient(self):
        name = self.NameField.text()
        email = self.EmailField.text()
        s = library.openSession()
        library.addPerson(s, name, email)
        s.close
        self.parent.refreshTables()
        QMessageBox.about(self.parent.centralwidget,
                          "Success", "Client added!")
        self.CloseClientButton.click()

    def retranslateUi(self, DialogAddClient):
        _translate = QtCore.QCoreApplication.translate
        DialogAddClient.setWindowTitle(_translate("DialogAddClient", "Dialog"))
        self.ConfirmClientButton.setText(
            _translate("DialogAddClient", "Confirm"))
        self.CloseClientButton.setText(_translate("DialogAddClient", "Cancel"))
        self.label.setText(_translate("DialogAddClient", "Client Details"))
        self.label_2.setText(_translate("DialogAddClient", "Name:"))
        self.label_3.setText(_translate("DialogAddClient", "email:"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    DialogAddClient = QtWidgets.QDialog()
    ui = Ui_DialogAddClient()
    ui.setupUi(DialogAddClient)
    DialogAddClient.show()
    sys.exit(app.exec_())
