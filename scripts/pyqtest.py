#!/usr/bin/env python

from PyQt4 import QtCore, QtGui
import sys

class Display(QtGui.QWidget):
  
  def __init__(self):
    QtGui.QWidget.__init__(self)
    self.btn = QtGui.QPushButton("PRESS ME!")
    self.label = QtGui.QLabel("NO PRESS")
    self.h_layout = QtGui.QHBoxLayout()
    self.h_layout.addWidget(self.btn)
    self.h_layout.addWidget(self.label)
    self.setLayout(self.h_layout)
    self.btn.clicked.connect(self.changeLabel)
  
  def  changeLabel(self):
    self.label.setText("PRESSED")

if __name__ == '__main__':
  app = QtGui.QApplication(sys.argv)
  d = Display()
  d.show()
  sys.exit(app.exec_())
