#-------------------------------------------------
#
# Project created by QtCreator 2012-06-21T14:35:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4):QT += widgets

TARGET = rcss3dMotionEditor
TEMPLATE = app


SOURCES += main.cpp\
        memainwindow.cpp \
    rcss3dsocket.cpp \
    world.cpp \
    merobot.cpp \
    poseeditor.cpp \
    inputjoint.cpp \
    pose.cpp \
    guieditortab.cpp \
    sequence.cpp \
    movementbase.cpp \
    action.cpp \
    sequencemovement.cpp \
    sequenceeditor.cpp

HEADERS  += memainwindow.h \
    rcss3dsocket.h \
    world.h \
    merobot.h \
    poseeditor.h \
    inputjoint.h \
    pose.h \
    guieditortab.h \
    sequence.h \
    movementbase.h \
    util.h \
    action.h \
    sequencemovement.h \
    sequenceeditor.h

unix:!macx:!symbian: LIBS += -L/usr/local/lib/simspark/ -lrcssnet3D

INCLUDEPATH += /usr/local/include/simspark
DEPENDPATH += /usr/local/lib/simspark
