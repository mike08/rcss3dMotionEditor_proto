#-------------------------------------------------
#
# Project created by QtCreator 2012-06-21T14:35:00
#
#-------------------------------------------------

QT       += core gui

TARGET = rcss3dMotionEditor
TEMPLATE = app


SOURCES += main.cpp\
        memainwindow.cpp \
    rcss3dsocket.cpp \
    world.cpp \
    merobot.cpp \
    poseeditor.cpp

HEADERS  += memainwindow.h \
    rcss3dsocket.h \
    world.h \
    merobot.h \
    poseeditor.h

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/local/lib/simspark/ -lrcssnet3D

INCLUDEPATH += /usr/local/include/simspark
DEPENDPATH += /usr/local/lib/simspark
