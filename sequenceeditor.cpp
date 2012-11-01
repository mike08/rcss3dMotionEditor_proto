#include "sequenceeditor.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

SequenceEditor::SequenceEditor(QWidget *parent) :
    QWidget(parent)
{
    QLabel* label1 = new QLabel(tr("your pose list"));
    QPushButton* loadPoseListButton = new QPushButton(tr("load list from pose edtior"));
    poseListFromEditor = new QListWidget();
    QPushButton* addButton = new QPushButton(tr("add ->"));

    poseListToSend = new QListWidget();
    QPushButton* testButton = new QPushButton(tr("test"));
    QPushButton* outputButton = new QPushButton(tr("output as file"));
        outputButton->setEnabled(false);
    QPushButton* removeButton = new QPushButton(tr("<- remove"));

    QVBoxLayout* left = new QVBoxLayout();
    QVBoxLayout* right = new QVBoxLayout();

    QHBoxLayout* entire = new QHBoxLayout();

    left->addWidget(label1);
    left->addWidget(loadPoseListButton);
    left->addWidget(poseListFromEditor);
    left->addWidget(addButton);

    right->addWidget(poseListToSend);
    right->addWidget(testButton);
    right->addWidget(outputButton);
    right->addWidget(removeButton);

    entire->addLayout(left);
    entire->addWidget(new QLabel(tr("    "))); // spacer is better
    entire->addLayout(right);

    this->setLayout(entire);

    connect(loadPoseListButton, SIGNAL(clicked()), this, SIGNAL(requestPoseList()));

    connect(addButton, SIGNAL(clicked()), this, SLOT(moveItemToSendList()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeItemFromSendList()));
    connect(testButton, SIGNAL(clicked()), this, SLOT(testSequence()));
}

Q_DECLARE_METATYPE(Pose)

void SequenceEditor::copyPoseList(QListWidget *list){
//    poseListFromEditor = list;
//    qDebug() << "seqedit::copyPoseList";

    poseListFromEditor->clear();

    for(int i=0; i<list->count(); i++){
        poseListFromEditor->addItem(list->item(i)->text());
        poseListFromEditor->item(i)->setData(Qt::UserRole, list->item(i)->data(Qt::UserRole));
    }
}

void SequenceEditor::moveItemToSendList(){
//    qDebug() << poseListFromEditor->currentRow();
    if(poseListFromEditor->currentRow() == -1){
        //not selected any item
        return;
    }
//    Pose temp = poseListFromEditor->currentItem()->data(Qt::UserRole).value<Pose>();
//    double tempD = temp.getTarget(3);
//    qDebug() << tempD;
    QListWidgetItem* added = new QListWidgetItem(poseListFromEditor->currentItem()->text());
    added->setData(Qt::UserRole, poseListFromEditor->currentItem()->data(Qt::UserRole));
    poseListToSend->addItem(added);

    Pose temp = poseListToSend->item(poseListToSend->count()-1)->data(Qt::UserRole).value<Pose>();
    qDebug() << temp.getTarget(1);
}

void SequenceEditor::removeItemFromSendList(){
    if(poseListToSend->currentRow() == -1){
        return;
    }
    poseListToSend->takeItem(poseListToSend->currentRow());
}

void SequenceEditor::testSequence(){
    Sequence tempSeq;

    for(int i=0; i<poseListToSend->count(); i++){
        tempSeq.addPose(poseListToSend->item(i)->data(Qt::UserRole).value<Pose>());
    }
    emit newSequenceMade(tempSeq);
}
