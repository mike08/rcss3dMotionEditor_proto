#include "memainwindow.h"
//#include <QPushButton>

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

    mesi = new meSharedInformation();
    robo->saveMeSIpointer(mesi);

    // gui part
    qtab = new QTabWidget();
    this->setCentralWidget(qtab);

//    qtab->addTab(new QPushButton("hoge"), "piyo");
//    qtab->addTab(new QPushButton("foo"), "bar");

    pe = new PoseEditor();
    qtab->addTab(pe, tr("pose edit"));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(5); // less 50 fps.
}

meMainWindow::~meMainWindow()
{
    delete soc;
    delete robo;
}

void meMainWindow::onTimer(){

    // check tab index

    // change send string maker by tab index

    /* proto

    soc.get(msg);

    if(tab_index == 0){
        poseEditor->getPose();
        sendStr = robo->getNextAngle(msg, pose);
    }

        // or robo->getNextAngle(msg, pose, bool& isEndPose) is might bettr
        // not good style, but player robot don't need to inform main program
        // if getNextAngle returns bool flag, that is far from player robot.

    */

    // soc.get & soc.put

}

