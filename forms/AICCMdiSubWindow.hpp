#ifndef AICCMDISUBWINDOW_H
#define AICCMDISUBWINDOW_H

#include <QMdiSubWindow>

class AICCMdiSubWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    AICCMdiSubWindow(){
        setWindowFlags(Qt::Window | Qt::WindowTitleHint    | Qt::WindowCloseButtonHint);
    }
    ~AICCMdiSubWindow(){}

};

#endif // AICCMDISUBWINDOW_H
