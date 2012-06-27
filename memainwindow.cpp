#include "memainwindow.h"
//#include <QPushButton>
#include <QMenuBar>
#include <QToolBar>

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

    createMenus();


    // gui part
    qtab = new QTabWidget(this);
    this->setCentralWidget(qtab);

//    qtab->addTab(new QPushButton("hoge"), "piyo");
//    qtab->addTab(new QPushButton("foo"), "bar");

    pe = new PoseEditor(qtab);
    qtab->addTab(pe, tr("pose edit"));

    timer = new QTimer(this);

    // set size policy
//    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // connecting signals and slots
    connect(qtab, SIGNAL(currentChanged(int)), mesi, SLOT(setUsingEditor(int)));
    connect(pe, SIGNAL(newPoseMade(Pose)), this, SLOT(setNewPose(Pose)));

    connect(beamingAct, SIGNAL(toggled(bool)), mesi, SLOT(setBeaming(bool)));

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(5); // less 50 fps.
}

void meMainWindow::createMenus(){
    //create actions
    beamingAct = new QAction(tr("beam"), this);
    beamingAct->setCheckable(true);
    beamingAct->setChecked(true);

    //create and set menu
    QMenu* robotMenu = menuBar()->addMenu(tr("&Robot"));
    robotMenu->addAction(beamingAct);
    QMenu* serverMenu = menuBar()->addMenu(tr("Server"));
    serverMenu->addMenu(tr("under construction..."));
    QMenu* poseEditMenu = menuBar()->addMenu(tr("&PoseEdit"));
    poseEditMenu->addMenu(tr("under construction..."));
    QMenu* sequenceEditMenu = menuBar()->addMenu(tr("&SequenceEdit"));
    sequenceEditMenu->addMenu(tr("under construction..."));

    //create and set toolbar
    QToolBar *robotBar = addToolBar(tr("Robot"));
    robotBar->addAction(beamingAct);

}

meMainWindow::~meMainWindow()
{
    delete soc;
    delete robo;
    delete mesi;
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

    /* proto2
        check using editor in robo->getNextAngle by sharedInformation
     */

    std::string msg;
    soc->GetMessage(msg);
    soc->PutMessage(robo->getNextAngle(msg));
}

void meMainWindow::setNewPose(Pose p){
    // may be insert option "not copy immediately"
    mesi->setPose(p);
}
