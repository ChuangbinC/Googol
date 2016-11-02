#-------------------------------------------------
#
# Project created by QtCreator 2016-11-02T19:04:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Googol
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    state_show_dialog.cpp

HEADERS  += mainwindow.h \
    state_show_dialog.h \
    command.h

FORMS    += mainwindow.ui \
    state_show_dialog.ui

DISTFILES += \
    README.txt

win32:LIBS += -L$$PWD/lib/ -lgts
INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

RC_ICONS = "app_ico.ico"
