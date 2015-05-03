#-------------------------------------------------
#
# Project created by QtCreator 2015-04-28T16:36:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tarea2Analisis1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tile.cpp \
    board.cpp \
    Pieces/chesspiece.cpp \
    Pieces/rook.cpp \
    Pieces/king.cpp \
    Pieces/queen.cpp \
    Pieces/bishop.cpp \
    Pieces/knight.cpp \
    Pieces/pawn.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    tile.h \
    board.h \
    Pieces/chesspiece.h \
    Pieces/rook.h \
    Pieces/king.h \
    Pieces/queen.h \
    Pieces/bishop.h \
    Pieces/knight.h \
    Pieces/pawn.h \
    player.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
