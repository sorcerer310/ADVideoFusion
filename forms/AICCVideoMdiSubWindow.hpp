#ifndef AICCVIDEOMDISUBWINDOW_H
#define AICCVIDEOMDISUBWINDOW_H

#include <QVideoWidget>
#include <QAbstractVideoSurface>
#include <QHBoxLayout>
#include <QPushButton>
#include <iostream>
#include <qs_video_player/include/qs/frame_converter.h>
#include <qs_video_player/include/qs/tcp_raw_video_player.h>
#include <forms/AICCMdiSubWindow.hpp>
#include <widgets/multiplevideoform.h>
#include <qs/tcp_raw_video_player.h>

#include <QVector>


class AICCVideoMdiSubWindow:public AICCMdiSubWindow
{
    Q_OBJECT
public:
    AICCVideoMdiSubWindow()
    {
        this->setWindowTitle("Test Video Window");
        this->resize(800,400);
        const QSharedPointer<qs::TcpRawVideoPlayer> vp1(new qs::TcpRawVideoPlayer(640,480,"192.168.1.110",6590));
        const QSharedPointer<qs::TcpRawVideoPlayer> vp2(new qs::TcpRawVideoPlayer(640,480,"192.168.1.110",6590));
        const QSharedPointer<qs::TcpRawVideoPlayer> vp3(new qs::TcpRawVideoPlayer(640,480,"192.168.1.110",6590));
        const QSharedPointer<qs::TcpRawVideoPlayer> vp4(new qs::TcpRawVideoPlayer(640,480,"192.168.1.110",6590));
        const QSharedPointer<qs::TcpRawVideoPlayer> vp5(new qs::TcpRawVideoPlayer(640,480,"192.168.1.110",6590));
        const QSharedPointer<qs::TcpRawVideoPlayer> vp6(new qs::TcpRawVideoPlayer(640,480,"192.168.1.110",6590));
        const QSharedPointer<qs::TcpRawVideoPlayer> vp7(new qs::TcpRawVideoPlayer(640,480,"192.168.1.110",6590));
        const QSharedPointer<qs::TcpRawVideoPlayer> vp8(new qs::TcpRawVideoPlayer(640,480,"192.168.1.110",6590));

        videoPlayerVector = {vp1,vp2,vp3,vp4,vp5,vp6,vp7,vp8};
        initMultipleVideoWidget();
    }
    ~AICCVideoMdiSubWindow(){
//        delete videoPlayer;
    }
private:
    void initMultipleVideoWidget(){
        MultipleVideoForm *mvform = new MultipleVideoForm(this);
        this->setWidget(mvform);
        mvform->gridLayout()->addWidget(makeVideoWidget(0),0,0);
        mvform->gridLayout()->addWidget(makeVideoWidget(1),0,1);
        mvform->gridLayout()->addWidget(makeVideoWidget(2),0,2);
        mvform->gridLayout()->addWidget(makeVideoWidget(3),0,3);
        mvform->gridLayout()->addWidget(makeVideoWidget(4),1,0);
        mvform->gridLayout()->addWidget(makeVideoWidget(5),1,1);
        mvform->gridLayout()->addWidget(makeVideoWidget(6),1,2);
        mvform->gridLayout()->addWidget(makeVideoWidget(7),1,3);
    }


    QVideoWidget *makeVideoWidget(int index){
        QVideoWidget *vwidget = new QVideoWidget(this);
        vwidget->setAspectRatioMode(Qt::KeepAspectRatio);
        auto *surface = vwidget->videoSurface();
        const auto &formats = surface->supportedPixelFormats();
//        for(const auto & f:formats)
//            std::cout << f << std::endl;

        vwidget->resize(400,300);
        vwidget->show();

        qs::TcpRawVideoPlayer *videoPlayer = new qs::TcpRawVideoPlayer(640,480,"192.168.1.110",6590);
        videoPlayer->setVideoOutput(vwidget);
        videoPlayer->play();

        return vwidget;
    }

private:
    QVector<QSharedPointer<qs::TcpRawVideoPlayer>> videoPlayerVector;
};

#endif // AICCVIDEOMDISUBWINDOW_H
