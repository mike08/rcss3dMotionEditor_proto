#ifndef POSEEDITOR_H
#define POSEEDITOR_H

#include <QWidget>
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
private:
    InputJoint* ij[22];
};

#endif // POSEEDITOR_H
