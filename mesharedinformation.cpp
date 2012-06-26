#include "mesharedinformation.h"
#include <QDebug>

meSharedInformation::meSharedInformation(QObject *parent) :
    QObject(parent)
{
    usingEditor = 0;
    beaming = true;
}

int meSharedInformation::getUsingEditor(){
    return usingEditor;
}

void meSharedInformation::setUsingEditor(int tabindex){
    usingEditor = tabindex;
//    qDebug() << "using Editor = " << usingEditor;
}

void meSharedInformation::setPose(Pose newpose){
    p = newpose;
//    qDebug() << "update pose";
}

Pose meSharedInformation::getPose(){
    return p;
}

void meSharedInformation::setBeaming(bool beam_arg){
    beaming = beam_arg;
}

bool meSharedInformation::getBeaming(){
    return beaming;
}
