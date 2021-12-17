#ifndef AICCCHANNELMDISUBWINDOW_H
#define AICCCHANNELMDISUBWINDOW_H

#include <QTableWidget>
#include <forms/AICCMdiSubWindow.hpp>

class AICCChannelMdiSubWindow:public AICCMdiSubWindow
{
    Q_OBJECT
public:
    AICCChannelMdiSubWindow(){
        this->setWindowTitle("Channel State");
        initTableWidget();
    }
    ~AICCChannelMdiSubWindow(){}

private:
    void initTableWidget(){
        QTableWidget *table = new QTableWidget(10,3,this);
        table
    }
};

#endif // AICCCHANNELMDISUBWINDOW_H
