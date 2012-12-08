#include "memainwindow.h"
//#include <QPushButton>
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>

#include "util.h"

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

    qDebug() << "starting program";
    this->setWindowTitle("rcss3dMotionEditor");

    robo = NULL;
    beaming = true;
    connectRobot();

    createMenus();

    // gui part
    gui = new GuiEditorTab(this);
    this->setCentralWidget(gui);

//    qtab = new QTabWidget(this);
//    this->setCentralWidget(qtab);

//    qtab->addTab(new QPushButton("hoge"), "piyo");
//    qtab->addTab(new QPushButton("foo"), "bar");

//    pe = new PoseEditor(qtab);
//    qtab->addTab(pe, tr("pose edit"));

    timer = new QTimer(this);

    // set size policy
//    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    qDebug() << "connectiong at main window";
    // connecting signals and slots
//    connect(qtab, SIGNAL(currentChanged(int)), mesi, SLOT(setUsingEditor(int)));

    connect(beamingAct, SIGNAL(toggled(bool)), this, SLOT(changeBeaming(bool)));
//    connect(connectRobotAct, SIGNAL(triggered()), this, SLOT(connectRobot()));
    connect(standUpAomukeAct, SIGNAL(triggered()), this, SLOT(sendStandUpAomuke()));
    connect(standUpUtsubuseAct, SIGNAL(triggered()), this, SLOT(sendStandUpUtsubuse()));

    connect(gui, SIGNAL(newSequenceMade(Sequence)), this, SLOT(setSequenceToRobot(Sequence)));

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(5); // less 50 fps.
}

void meMainWindow::createMenus(){
    qDebug() << "create menus";

    //create actions
    beamingAct = new QAction(tr("beam"), this);
    beamingAct->setCheckable(true);
    beamingAct->setChecked(true);

    standUpAomukeAct = new QAction(tr("standUp aomuke"), this);
    standUpUtsubuseAct = new QAction(tr("standUp utsubuse"), this);

//    connectRobotAct = new QAction(tr("connect"), this); // reconnect function not works now

/*
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
*/
    //create and set toolbar
    QToolBar *robotBar = addToolBar(tr("Robot"));
    robotBar->addAction(beamingAct);
    robotBar->addAction(standUpAomukeAct);
    robotBar->addAction(standUpUtsubuseAct);
}

meMainWindow::~meMainWindow()
{
//    delete soc;
    delete robo;
//    delete mesi;
}

void meMainWindow::connectRobot(){


    int port = 3100;
    std::string host = "127.0.0.1";
    std::string teamname = "MotionEditor";

    //if already exist robot
//    if(soc != NULL){
//        soc->Done();
//        delete soc;
//    }

    static int called = 0;

    if(called > 0){
        soc.Done();
    }
    called++;

    if(robo != NULL){
        delete robo;
        robo = NULL;
    }

    //make socket and robot
//    soc = new rcss3dSocket(port, host);
    soc.Connect(port, host);

    robo = new meRobot(teamname);

    //robot initializing
    soc.PutMessage(robo->Init());
    {
        std::string msg;
        soc.GetMessage(msg);
    }

    soc.PutMessage(robo->Init2());

//    mesi = new meSharedInformation();
//    robo->saveMeSIpointer(mesi);
}

void meMainWindow::onTimer(){
//    qDebug() << "tick";
    std::string msg;
    soc.GetMessage(msg);
    std::string ret = robo->getNextAngle(msg);
    if(beaming){
        ret = ret + "(beam -1.0 -3 0)";
    }
    soc.PutMessage(ret);
}

void meMainWindow::changeBeaming(bool b){
    beaming = b;
}

void meMainWindow::setSequenceToRobot(Sequence s){
//    qDebug() << "new seq num = " << s.getNum();
    robo->setSequence(s);
}

void meMainWindow::sendStandUpAomuke(){
    Pose reverse0;
    reverse0.setTarget(laj2, 90);
    reverse0.setTarget(raj2, -90);
    Pose reverse1;
    reverse1.setTarget(laj1, -120);
    reverse1.setTarget(raj1, -120);
    reverse1.setTarget(laj3, 90);
    reverse1.setTarget(raj3, -90);
    reverse1.setTarget(laj4, -45);
    reverse1.setTarget(raj4, 45);
    reverse1.setTarget(llj5, 75);
    reverse1.setTarget(rlj5, 75);
    Pose reverse2;
    reverse2.setTarget(laj1, -120);
    reverse2.setTarget(raj1, -120);
    reverse2.setTarget(laj3, 90);
    reverse2.setTarget(raj3, -90);
    reverse2.setTarget(laj4, -45);
    reverse2.setTarget(raj4, 45);
    reverse2.setTarget(llj1, -90);
    reverse2.setTarget(rlj1, -90);
    reverse2.setTarget(llj3, 100);
    reverse2.setTarget(rlj3, 100);
    reverse2.setTarget(llj4, -130);
    reverse2.setTarget(rlj4, -130);
    reverse2.setTarget(llj5, 75);
    reverse2.setTarget(rlj5, 75);
    Pose reverse3;
    reverse3.setTarget(laj1, -45);
    reverse3.setTarget(raj1, -45);
    reverse3.setTarget(llj1, -90);
    reverse3.setTarget(rlj1, -90);
    reverse3.setTarget(llj3, 100);
    reverse3.setTarget(rlj3, 100);
    reverse3.setTarget(llj4, -90);
    reverse3.setTarget(rlj4, -90);
    reverse3.setTarget(llj5, -45);
    reverse3.setTarget(rlj5, -45);
    /*
    Pose reverse4;
    reverse4.setGain(0.01);
    reverse4.setTarget(laj1, -100);
    reverse4.setTarget(raj1, -100);
    reverse4.setTarget(laj3, -90);
    reverse4.setTarget(raj3, 90);
    reverse4.setTarget(laj4, -90);
    reverse4.setTarget(raj4, 90);
    */
    Pose stand1;
    stand1.setTarget(laj1, -45);
    stand1.setTarget(raj1, -45);
    stand1.setTarget(laj3, -90);
    stand1.setTarget(raj3, 90);
    stand1.setTarget(llj1, -90);
    stand1.setTarget(rlj1, -90);
    stand1.setTarget(llj3, 100);
    stand1.setTarget(rlj3, 100);
    stand1.setTarget(llj4, -130);
    stand1.setTarget(rlj4, -130);
    Pose stand2;
    stand2.setGain(0.01);
    stand2.setTarget(laj1, -100);
    stand2.setTarget(raj1, -100);
    stand2.setTarget(laj3, -90);
    stand2.setTarget(raj3, 90);
    stand2.setTarget(laj4, -90);
    stand2.setTarget(raj4, 90);


    Sequence reverse;
    reverse.addPose(reverse0);
    reverse.addPose(reverse1);
    reverse.addPose(reverse2);
    reverse.addPose(reverse3);
//    reverse.addPose(reverse4);
    reverse.addPose(stand1);
    reverse.addPose(stand2);

    robo->setSequence(reverse);
}

void meMainWindow::sendStandUpUtsubuse(){
    Pose open;
    open.setTarget(laj2, 95);
    open.setTarget(raj2, -95);
    Pose stand0;
    stand0.setTarget(laj2, 45);
    stand0.setTarget(raj2, -45);
    stand0.setTarget(laj3, -90);
    stand0.setTarget(raj3, 90);
    stand0.setTarget(laj4, -90);
    stand0.setTarget(raj4, 90);
    stand0.setTarget(llj1, -90);
    stand0.setTarget(rlj1, -90);
    stand0.setTarget(llj3, 100);
    stand0.setTarget(rlj3, 100);
    stand0.setTarget(llj4, -130);
    stand0.setTarget(rlj4, -130);
    stand0.setTarget(llj5, 75);
    stand0.setTarget(rlj5, 75);
    Pose stand1;
    stand1.setTarget(laj1, -45);
    stand1.setTarget(raj1, -45);
    stand1.setTarget(laj3, -90);
    stand1.setTarget(raj3, 90);
    stand1.setTarget(llj1, -90);
    stand1.setTarget(rlj1, -90);
    stand1.setTarget(llj3, 100);
    stand1.setTarget(rlj3, 100);
    stand1.setTarget(llj4, -130);
    stand1.setTarget(rlj4, -130);
    Pose stand2;
    stand2.setGain(0.01);
    stand2.setTarget(laj1, -100);
    stand2.setTarget(raj1, -100);
    stand2.setTarget(laj3, -90);
    stand2.setTarget(raj3, 90);
    stand2.setTarget(laj4, -90);
    stand2.setTarget(raj4, 90);

    Sequence stand;
    stand.addPose(open);
    stand.addPose(stand0);
    stand.addPose(stand1);
    stand.addPose(stand2);

    robo->setSequence(stand);
}
