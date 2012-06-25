#include "poseeditor.h"
#include <QVBoxLayout>
#include <QGridLayout>

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

    QVBoxLayout *hjlayout = new QVBoxLayout();
    hjlayout->addStretch();
    hjlayout->addWidget(ij[0]);
    hjlayout->addWidget(ij[1]);

    QGridLayout *allayout = new QGridLayout();
    for(int i=1; i<11; i++){
        allayout->addWidget(ij[i*2], i, 0);
        allayout->addWidget(ij[i*2+1], i, 1);
    }

    QVBoxLayout *entirelayout = new QVBoxLayout();
    entirelayout->addLayout(hjlayout);
    entirelayout->addLayout(allayout);

    this->setLayout(entirelayout);

}
