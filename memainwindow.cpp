#include "memainwindow.h"

meMainWindow::meMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    int port = 3100;
    std::string host = "127.0.0.1";
    std::string teamname = "MotionEditor";

    //make socket and robot
    soc = new rcss3dSocket(port, host);
    robo = new meRobot(teamname);

    //robot initializing
    soc->PutMessage(robo->Init());
    {
        std::string msg;
        soc->GetMessage(msg);
    }
    soc->PutMessage(robo->Init2());

}

meMainWindow::~meMainWindow()
{
    delete soc;
    delete robo;
}
