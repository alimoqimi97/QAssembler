#-------------------------------------------------
#
# Project created by QtCreator 2019-03-17T10:10:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QAssembler
TEMPLATE = app


CONFIG  += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    assembler.cpp \
    assemblycode.cpp \
    i_type.cpp \
    j_type.cpp \
    machinecode.cpp \
    r_type.cpp

HEADERS  += mainwindow.h \
    assembler.h \
    assemblycode.h \
    i_type.h \
    j_type.h \
    machinecode.h \
    r_type.h

FORMS    += mainwindow.ui
