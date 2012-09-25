#ifndef POSEEDITOR_H
#define POSEEDITOR_H

#include <QWidget>
#include <QListWidget>
#include "inputjoint.h"
#include "pose.h"

// provide gui to pose edit
// added as tab0 in main window

class PoseEditor : public QWidget
{
    Q_OBJECT
public:
    explicit PoseEditor(QWidget *parent = 0);

signals:
    void newPoseMade(Pose);

public slots:
    void makeNewPose();
    void loadPose(Pose p); // set slider and spinbox by loaded pose
    void loadPose(int i);

private:
    InputJoint* ij[22];

    QListWidget* posesList;
    Pose poseEditorList[10];
};

#endif // POSEEDITOR_H
