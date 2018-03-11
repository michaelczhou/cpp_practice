#-------------------------------------------------
#
# Project created by QtCreator 2018-03-11T10:12:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    keyboard/keyboard.cpp

HEADERS  += mainwindow.h \
    keyboard/keyboard.h \
    keyboard/ui_keyboard.h

FORMS    += mainwindow.ui \
    keyboard/keyboard.ui
