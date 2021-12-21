#ifndef AICCCHANNELMDISUBWINDOW_H
#define AICCCHANNELMDISUBWINDOW_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <forms/AICCMdiSubWindow.hpp>

class AICCChannelMdiSubWindow:public AICCMdiSubWindow
{
    Q_OBJECT
public:
    AICCChannelMdiSubWindow(){

        this->setWindowTitle("Channel State");
        this->resize(340,360);
        initTableWidget();
    }
    ~AICCChannelMdiSubWindow(){}

private:
    void initTableWidget(){
        QTableWidget *table = new QTableWidget(10,3,this);
//        table->resize(1800,600);
        QStringList header;
        header << "name" << "Status" << "FPS";
        table->setHorizontalHeaderLabels(header);
        table->setItem(0,0,new QTableWidgetItem("Camera1"));
        table->setItem(1,0,new QTableWidgetItem("Camera2"));
        table->setItem(2,0,new QTableWidgetItem("Camera3"));
        this->setWidget(table);

    }
};

#endif // AICCCHANNELMDISUBWINDOW_H
