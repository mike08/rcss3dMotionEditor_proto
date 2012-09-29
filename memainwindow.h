#ifndef MEMAINWINDOW_H
#define MEMAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTimer>
#include <iostream>
#include "rcss3dsocket.h"
#include "merobot.h"
#include "poseeditor.h"
#include "pose.h"
#include <QAction>
#include "guieditortab.h"


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
    void connectRobot();
    void onTimer();
    void changeBeaming(bool);
    void setSequenceToRobot(Sequence);
protected:
    void createMenus();

    rcss3dSocket soc;
    meRobot* robo;
    bool beaming;

    QTimer* timer;

    GuiEditorTab* gui;

    QTabWidget* qtab;
    PoseEditor* pe;


    QAction *connectRobotAct;
    QAction *beamingAct;
    // QAction *displayJointPictureAct;
};

#endif // MEMAINWINDOW_H
