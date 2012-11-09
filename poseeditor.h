#ifndef POSEEDITOR_H
#define POSEEDITOR_H

#include <QWidget>
#include <QListWidget>
#include "inputjoint.h"
#include "pose.h"
#include <QComboBox>

// provide gui to pose edit
// added as tab0 in main window

class PoseEditor : public QWidget
{
    Q_OBJECT
public:
    explicit PoseEditor(QWidget *parent = 0);

signals:
    void newPoseMade(Pose);
    void poseList(QListWidget*);

public slots:
    void makeNewPose();
    void changePoseListRow(int i);
    void loadPose(Pose p); // set slider and spinbox by loaded pose
    void loadPose(int i);
    void saveProject();
    void loadProject();
    void copyPose();
    void renameComboBox();

    void getPoseList(); // emit poseList(posesList)

    void addPoseItem(QString txt, Pose p);
    void removeSelectedItem();

private:
    InputJoint* ij[22];

    QListWidget* posesList;
//    Pose poseEditorList[10]; // nameing is not good...

    QComboBox* fromComboBox;
    QComboBox* toComboBox;

};

#endif // POSEEDITOR_H
