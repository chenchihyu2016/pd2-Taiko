#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T12:55:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taikoGAME
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    startmain.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    startmain.h

FORMS    += mainwindow.ui \
    dialog.ui \
    startmain.ui

RESOURCES += \
    pics.qrc
