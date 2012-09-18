#include "guieditortab.h"

GuiEditorTab::GuiEditorTab(QWidget *parent) :
    QTabWidget(parent)
{
    pe = new PoseEditor(this);
    this->addTab(pe, tr("pose edit"));

    connect(pe, SIGNAL(newPoseMade(Pose)), this, SLOT(poseEditorReceiver(Pose)));

    //connect(seceditor, SIGNAL(newSeq), this, SIGNAL(newSeqMade))
}

void GuiEditorTab::poseEditorReceiver(Pose p){
    Sequence tempSeq;
    tempSeq.addPose(p);

    emit newSequenceMade(tempSeq);
}
