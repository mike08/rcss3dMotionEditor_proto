#include "sequenceeditor.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

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
    entire->addWidget(new QLabel(tr("    ")));
    entire->addLayout(right);

    this->setLayout(entire);
}
