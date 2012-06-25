#ifndef MEMAINWINDOW_H
#define MEMAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTimer>
#include <iostream>
#include "rcss3dsocket.h"
#include "merobot.h"
#include "mesharedinformation.h"
#include "poseeditor.h"
#include "pose.h"

/*
    main window of program.
    This class manage all gui classes and robot(server connection and joint angle manager).
    Each gui class changes some parameter. Main window notice changing and the value to robot.
*/

class meMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    meMainWindow(QWidget *parent = 0);
    ~meMainWindow();

public slots:
    void onTimer();
    void setNewPose(Pose);
private:
    rcss3dSocket* soc;
    meRobot* robo;

    meSharedInformation* mesi;

    QTimer* timer;
    QTabWidget* qtab;
    PoseEditor* pe;
};

#endif // MEMAINWINDOW_H
