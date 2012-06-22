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
    robot.cpp \
    world.cpp \
    merobot.cpp

HEADERS  += memainwindow.h \
    rcss3dsocket.h \
    robot.h \
    world.h \
    merobot.h

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/local/lib/simspark/ -lrcssnet3D

INCLUDEPATH += /usr/local/include/simspark
DEPENDPATH += /usr/local/lib/simspark
