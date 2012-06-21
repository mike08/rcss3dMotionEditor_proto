#include <QtGui/QApplication>
#include "memainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    meMainWindow w;
    w.show();
    
    return a.exec();
}
