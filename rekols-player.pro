QT += core
QT += widgets
QT += gui
QT += avwidgets

TEMPLATE = app
TARGET = rekols-player

CONFIG += link_pkgconfig
CONFIG += c++11
PKGCONFIG += dtkwidget

HEADERS +=  titlebar.h \
    mainwindow.h \
    dbutton.h

SOURCES +=  main.cpp titlebar.cpp \
    mainwindow.cpp \
    dbutton.cpp

RESOURCES += resources.qrc
