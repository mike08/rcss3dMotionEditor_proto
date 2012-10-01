#include "guieditortab.h"
#include <QDebug>

GuiEditorTab::GuiEditorTab(QWidget *parent) :
    QTabWidget(parent)
{
    pe = new PoseEditor(this);
    this->addTab(pe, tr("pose edit"));

    connect(pe, SIGNAL(newPoseMade(Pose)), this, SLOT(poseEditorReceiver(Pose)));

    //connect(seceditor, SIGNAL(newSeq), this, SIGNAL(newSeqMade))


    //some connect when change editor type (ex. poseEditor->seqEditor)
    //connect(this, SIGNAL(currentChanged(int)), this, SLOT(editorChanged(int))) // ?

}

void GuiEditorTab::poseEditorReceiver(Pose p){
    Sequence tempSeq;
    qDebug() << "GuiEditorTab::poseEditorReceiver before add : " << tempSeq.getNum();

    tempSeq.addPose(p);

    qDebug() << "GuiEditorTab::poseEditorReceiver after  add : " << tempSeq.getNum();

    emit newSequenceMade(tempSeq);
}
