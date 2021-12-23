#include "kas_m.h"
#include "ui_kas_m.h"

kas_m::kas_m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kas_m)
{
    ui->setupUi(this);
}

kas_m::~kas_m()
{
    delete ui;
}

void kas_m::on_exits_clicked()
{
    this->close();
    emit exitpls();
}
