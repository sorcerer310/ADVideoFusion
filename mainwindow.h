﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QVideoFrame>
#include <QMediaPlaylist>
#include <QUrl>
#include <QVideoSurfaceFormat>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
   bool checkCameraAvailability();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player = nullptr;
    QVideoWidget *m_videoWidget = nullptr;
    QMediaPlaylist *m_playerlist = nullptr;

};
#endif // MAINWINDOW_H