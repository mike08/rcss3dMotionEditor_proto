#ifndef MESHAREDINFORMATION_H
#define MESHAREDINFORMATION_H

#include <QObject>
#include "pose.h"

/*
    This class hold inputed information on gui
    main window modify this class.
    robot has pointer and check it in getNextAngle()
 */
class meSharedInformation : public QObject
{
    Q_OBJECT
public:
    explicit meSharedInformation(QObject *parent = 0);

    int getUsingEditor();
    void setPose(Pose newpose);
    Pose getPose();
    bool getBeaming();

signals:

public slots:
    void setUsingEditor(int);
    void setBeaming(bool);

private:
    int usingEditor; // save tab index to ckeck which editor is used
    bool beaming; // beam or not
    Pose p; // pose editor information
    // sequence_editor_information sei;
    // ...
};

#endif // MESHAREDINFORMATION_H
