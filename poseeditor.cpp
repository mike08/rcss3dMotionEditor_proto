#include "poseeditor.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDebug>

PoseEditor::PoseEditor(QWidget *parent) :
    QWidget(parent)
{
    ij[0] = new InputJoint(tr("hj1"), -120, 120, this);
    ij[1] = new InputJoint(tr("hj2"), -45, 45, this);
    ij[2] = new InputJoint(tr("laj1"), -120, 120, this);
    ij[3] = new InputJoint(tr("raj1"), -120, 120, this);
    ij[4] = new InputJoint(tr("laj2"), -1, 95, this);
    ij[5] = new InputJoint(tr("raj2"), -95, 1, this);
    ij[6] = new InputJoint(tr("laj3"), -120, 120, this);
    ij[7] = new InputJoint(tr("raj3"), -120, 120, this);
    ij[8] = new InputJoint(tr("laj4"), -90, 1, this);
    ij[9] = new InputJoint(tr("raj4"), -1, 90, this);
    ij[10] = new InputJoint(tr("llj1"), -90, 1, this);
    ij[11] = new InputJoint(tr("rlj1"), -90, 1, this);
    ij[12] = new InputJoint(tr("llj2"), -25, 45, this);
    ij[13] = new InputJoint(tr("rlj2"), -45, 25, this);
    ij[14] = new InputJoint(tr("llj3"), -25, 100, this);
    ij[15] = new InputJoint(tr("rlj3"), -25, 100, this);
    ij[16] = new InputJoint(tr("llj4"), -130, 1, this);
    ij[17] = new InputJoint(tr("rlj4"), -130, 1, this);
    ij[18] = new InputJoint(tr("llj5"), -45, 75, this);
    ij[19] = new InputJoint(tr("rlj5"), -45, 75, this);
    ij[20] = new InputJoint(tr("llj6"), -45, 25, this);
    ij[21]= new InputJoint(tr("rlj6"), -25, 45, this);

    posesList = new QListWidget();
    posesList->addItem(tr("pose0"));
    posesList->addItem(tr("pose1"));
    posesList->addItem(tr("pose2"));
    posesList->addItem(tr("pose3"));
    posesList->addItem(tr("pose4"));
    posesList->addItem(tr("pose5"));
    posesList->addItem(tr("pose6"));
    posesList->addItem(tr("pose7"));
    posesList->addItem(tr("pose8"));
    posesList->addItem(tr("pose9"));
    posesList->setCurrentRow(0);

    QGridLayout *jointLayout = new QGridLayout();
    jointLayout->addWidget(ij[0], 0, 0, 1, 2);
    jointLayout->addWidget(ij[1], 1, 0, 1, 2);
    for(int i=1; i<11; i++){
        jointLayout->addWidget(ij[i*2], i+2, 0);
        jointLayout->addWidget(ij[i*2+1], i+2, 1);
    }

    QHBoxLayout *entireLayout = new QHBoxLayout();
    entireLayout->addWidget(posesList);
    entireLayout->addLayout(jointLayout);

    this->setLayout(entireLayout);
    this->setMinimumSize(300, 350);

    //signal slot connection
    // if value changed, modify shared information
    /*
        "check which joint is modified" is better,
        but "if some joint is modified, reread all data" is easier
    */

    for(int i=0; i<22; i++){
        connect(ij[i], SIGNAL(valueChanged(double)), this, SLOT(makeNewPose()));
    }

    connect(posesList, SIGNAL(currentRowChanged(int)), this, SLOT(loadPose(int)));

}

void PoseEditor::makeNewPose(){
    double inputedValue[22];
    for(int i=0; i<22; i++){
        inputedValue[i] = ij[i]->getValue();
    }
    Pose p(inputedValue);
    poseEditorList[posesList->currentRow()] = p;
    emit newPoseMade(p);
}

void PoseEditor::loadPose(Pose p){
    for(int i=0; i<22; i++){
        ij[i]->setValue(p.getTarget()[i]);
    }
}

void PoseEditor::loadPose(int i){
    loadPose(poseEditorList[i]);
//    qDebug() << "poseEditorList changed to " << i;
}
