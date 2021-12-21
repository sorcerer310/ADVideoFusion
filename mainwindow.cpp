#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initToolBar();
    initTreeView();

//    m_videoWidget = new QVideoWidget(this);
//    ui->layout->addWidget(m_videoWidget);

//    m_player = new QMediaPlayer(this);
//    m_playerlist = new QMediaPlaylist(m_player);
//    m_player->setVideoOutput(m_videoWidget);
//    m_player->setMedia(QUrl("C:/Users/fengc/Videos/WeChat_20211213112711.mp4"));
//    m_player->play();

}

void MainWindow::initToolBar(){
    //去掉dock头
//    QWidget *titleBarWidget = ui->dw_toolbar->titleBarWidget();
    QWidget *toolbarNullTitleBarWidget = new QWidget;
    QWidget *leftNullTitleBarWidget = new QWidget;

    ui->dw_toolbar->setTitleBarWidget(toolbarNullTitleBarWidget);
    ui->dw_left->setTitleBarWidget(leftNullTitleBarWidget);

    //初始化tab标签

    //初始化toolbar按钮

    QToolButton *tb_channel = ui->tb_channel;
    connect(tb_channel,&QToolButton::clicked,tb_channel,[&](){
        AICCChannelMdiSubWindow *msw = new AICCChannelMdiSubWindow;
//        msw->setWidget(new QTextEdit());
//        msw->setWindowTitle("subWindow");
        ui->mdiArea->addSubWindow(msw);
        msw->show();
    });

    //初始化连接按钮
    QToolButton *tb_connect = ui->tb_connect;
    connect(tb_connect,&QToolButton::clicked,tb_connect,[&](){
//        Greeter *greeter = new Greeter();
    });

    QToolButton *tb_testVideo = ui->tb_testVideo;
    connect(tb_testVideo,&QToolButton::clicked,tb_testVideo,[&](){
            AICCVideoMdiSubWindow  *vmsw = new AICCVideoMdiSubWindow();
            ui->mdiArea->addSubWindow(vmsw);
            vmsw->show();
    });
//    connect(pb_mdiform,&QPushButton::clicked,pb_mdiform,[&](){
//        QMdiSubWindow *subWindow = new QMdiSubWindow;
//        subWindow->setWidget(new QTextEdit());
//        subWindow->setWindowTitle("subWindow");
//        ui->mdiArea->addSubWindow(subWindow);
//        subWindow->show();
//    });
}

void MainWindow::initTreeView(){
    QTreeWidget *tw = ui->tw_device;
    tw->clear();
    //根节点
    QTreeWidgetItem* rootGroupSource = new QTreeWidgetItem(tw);
    rootGroupSource->setText(0,QStringLiteral("设备"));

    //分类
    QTreeWidgetItem *itemClass1 = new QTreeWidgetItem(rootGroupSource);
    itemClass1->setText(0,QStringLiteral("毫米波雷达"));
    QTreeWidgetItem *itemClass2 = new QTreeWidgetItem(rootGroupSource);
    itemClass2->setText(0,QStringLiteral("RTK"));
    QTreeWidgetItem *itemClass3 = new QTreeWidgetItem(rootGroupSource);
    itemClass3->setText(0,QStringLiteral("激光雷达"));
    QTreeWidgetItem *itemClass4 = new QTreeWidgetItem(rootGroupSource);
    itemClass4->setText(0,QStringLiteral("摄像头"));

    //设备
    QTreeWidgetItem *itemDevice11 = new QTreeWidgetItem(itemClass1);
    itemDevice11->setText(0,QStringLiteral("雷达1"));
    QTreeWidgetItem *itemDevice21 = new QTreeWidgetItem(itemClass2);
    itemDevice21->setText(0,QStringLiteral("RTK1"));
    QTreeWidgetItem *itemDevice31 = new QTreeWidgetItem(itemClass3);
    itemDevice31->setText(0,QStringLiteral("激光雷达1"));
    QTreeWidgetItem *itemDevice41 = new QTreeWidgetItem(itemClass4);
    itemDevice41->setText(0,QStringLiteral("摄像头1"));
    QTreeWidgetItem *itemDevice42 = new QTreeWidgetItem(itemClass4);
    itemDevice42->setText(0,QStringLiteral("摄像头2"));
    QTreeWidgetItem *itemDevice43 = new QTreeWidgetItem(itemClass4);
    itemDevice43->setText(0,QStringLiteral("摄像头3"));
    QTreeWidgetItem *itemDevice44 = new QTreeWidgetItem(itemClass4);
    itemDevice44->setText(0,QStringLiteral("摄像头4"));


    ui->tw_device->expandAll();
}

bool MainWindow::checkCameraAvailability()
{
//    if (QMediaDevices::videoInputs().count() > 0)
//        return true;
//    else
        return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

