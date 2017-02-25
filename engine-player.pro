QT += core
QT += widgets
QT += gui
QT += avwidgets

TEMPLATE = app
TARGET = engine-player

CONFIG += link_pkgconfig
CONFIG += c++11
PKGCONFIG += dtkwidget dtkbase

HEADERS +=  titlebar.h \
    mainwindow.h

SOURCES +=  main.cpp titlebar.cpp \
    mainwindow.cpp

RESOURCES += resources.qrc
