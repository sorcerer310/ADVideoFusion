#include "multiplevideoform.h"
#include "ui_multiplevideoform.h"

MultipleVideoForm::MultipleVideoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultipleVideoForm)
{
    ui->setupUi(this);
}

MultipleVideoForm::~MultipleVideoForm()
{
    delete ui;
}

QGridLayout *MultipleVideoForm::gridLayout(){
    return ui->gridLayout;
}
