#include "memainwindow.h"
//#include <QPushButton>
#include <QMenuBar>
#include <QToolBar>

meMainWindow::meMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    int port = 3100;
//    std::string host = "127.0.0.1";
//    std::string teamname = "MotionEditor";

//    //make socket and robot
//    soc = new rcss3dSocket(port, host);
//    robo = new meRobot(teamname);

//    //robot initializing
//    soc->PutMessage(robo->Init());
//    {
//        std::string msg;
//        soc->GetMessage(msg);
//    }
//    soc->PutMessage(robo->Init2());

//    mesi = new meSharedInformation();
//    robo->saveMeSIpointer(mesi);
    soc = NULL;
    robo = NULL;
    connectRobot();

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
    connect(connectRobotAct, SIGNAL(triggered()), this, SLOT(connectRobot()));

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(5); // less 50 fps.
}

void meMainWindow::createMenus(){
    //create actions
    beamingAct = new QAction(tr("beam"), this);
    beamingAct->setCheckable(true);
    beamingAct->setChecked(true);
    connectRobotAct = new QAction(tr("connect"), this);

    //create and set menu
    QMenu* robotMenu = menuBar()->addMenu(tr("&Robot"));
    robotMenu->addAction(beamingAct);
    robotMenu->addAction(connectRobotAct);
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

void meMainWindow::connectRobot(){
    int port = 3100;
    std::string host = "127.0.0.1";
    std::string teamname = "MotionEditor";

    //if already exist robot
    if(soc != NULL){
        soc->Done();
        delete soc;
    }
    if(robo != NULL){
        delete robo;
    }

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
}

void meMainWindow::onTimer(){
    std::string msg;
    soc->GetMessage(msg);
    soc->PutMessage(robo->getNextAngle(msg));
}

void meMainWindow::setNewPose(Pose p){
    // may be insert option "not copy immediately"
    mesi->setPose(p);
}
