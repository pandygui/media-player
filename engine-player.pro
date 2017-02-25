QT += core
QT += widgets
QT += gui
QT += avwidgets

TEMPLATE = app
TARGET = engine-player

CONFIG += link_pkgconfig
CONFIG += c++11
PKGCONFIG += dtkwidget dtkbase

HEADERS +=  mainwidget.h

SOURCES +=  main.cpp mainwidget.cpp
