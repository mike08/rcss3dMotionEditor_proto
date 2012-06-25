#include "mesharedinformation.h"
#include <QDebug>

meSharedInformation::meSharedInformation(QObject *parent) :
    QObject(parent)
{
}

int meSharedInformation::getUsingEditor(){
    return usingEditor;
}

void meSharedInformation::setUsingEditor(int tabindex){
    usingEditor = tabindex;
    qDebug() << "using Editor = " << usingEditor;
}
