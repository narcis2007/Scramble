#-------------------------------------------------
#
# Project created by QtCreator 2015-05-28T11:05:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = practic
TEMPLATE = app


SOURCES += main.cpp\
        simulator.cpp \
    graph.cpp \
    game.cpp \
    word.cpp \
    errorwindow.cpp \
    tablemodel.cpp \
    repository.cpp

HEADERS  += simulator.h \
    graph.h \
    game.h \
    word.h \
    errorwindow.h \
    tablemodel.h \
    repository.h

DISTFILES += \
    ../build-practic-Desktop_Qt_5_4_1_MSVC2013_64bit-Debug/data.txt \
    ../build-practic-Desktop_Qt_5_4_1_MSVC2013_64bit-Debug/saved_data.txt
