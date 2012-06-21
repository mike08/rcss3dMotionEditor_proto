#ifndef MEMAINWINDOW_H
#define MEMAINWINDOW_H

#include <QtGui/QMainWindow>

class meMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    meMainWindow(QWidget *parent = 0);
    ~meMainWindow();
};

#endif // MEMAINWINDOW_H
