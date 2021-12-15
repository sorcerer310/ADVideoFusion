#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_videoWidget = new QVideoWidget(this);
    ui->layout->addWidget(m_videoWidget);

    m_player = new QMediaPlayer(this);
    m_playerlist = new QMediaPlaylist(m_player);
    m_player->setVideoOutput(m_videoWidget);
    m_player->setMedia(QUrl("C:/Users/fengc/Videos/WeChat_20211213112711.mp4"));
    m_player->play();

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

