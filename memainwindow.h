#ifndef MEMAINWINDOW_H
#define MEMAINWINDOW_H

#include <QtGui/QMainWindow>
#include <iostream>
#include "rcss3dsocket.h"
#include "merobot.h"

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

private:
    rcss3dSocket* soc;
    meRobot* robo;
};

#endif // MEMAINWINDOW_H
