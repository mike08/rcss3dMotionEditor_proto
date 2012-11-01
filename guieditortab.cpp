#include "guieditortab.h"
#include <QDebug>

GuiEditorTab::GuiEditorTab(QWidget *parent) :
    QTabWidget(parent)
{
    poseEdit = new PoseEditor(this);
    seqEdit = new SequenceEditor(this);

    this->addTab(poseEdit, tr("pose edit"));
    this->addTab(seqEdit, tr("sequence Edit"));

    connect(poseEdit, SIGNAL(newPoseMade(Pose)), this, SLOT(poseEditorReceiver(Pose)));
    connect(seqEdit, SIGNAL(newSequenceMade(Sequence)), this, SIGNAL(newSequenceMade(Sequence)));


    //some connect when change editor type (ex. poseEditor->seqEditor)
    //connect(this, SIGNAL(currentChanged(int)), this, SLOT(editorChanged(int))) // ?

    connect(seqEdit, SIGNAL(requestPoseList()), poseEdit, SLOT(getPoseList()));
    connect(poseEdit, SIGNAL(poseList(QListWidget*)), seqEdit, SLOT(copyPoseList(QListWidget*)));
}

void GuiEditorTab::poseEditorReceiver(Pose p){
    Sequence tempSeq;
//    qDebug() << "GuiEditorTab::poseEditorReceiver before add : " << tempSeq.getNum();

    tempSeq.addPose(p);

//    qDebug() << "GuiEditorTab::poseEditorReceiver after  add : " << tempSeq.getNum();

    emit newSequenceMade(tempSeq);
}
