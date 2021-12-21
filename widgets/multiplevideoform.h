#ifndef MULTIPLEVIDEOFORM_H
#define MULTIPLEVIDEOFORM_H

#include <QWidget>
#include <QLayout>

namespace Ui {
class MultipleVideoForm;
}

class MultipleVideoForm : public QWidget
{
    Q_OBJECT

public:
    explicit MultipleVideoForm(QWidget *parent = nullptr);
    ~MultipleVideoForm();
    QGridLayout *gridLayout();

private:
    Ui::MultipleVideoForm *ui;
};

#endif // MULTIPLEVIDEOFORM_H
