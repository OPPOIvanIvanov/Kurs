#include "user_m.h"
#include "ui_user_m.h"

user_m::user_m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_m)
{
    ui->setupUi(this);
}

user_m::~user_m()
{
    delete ui;
}

void user_m::on_exits_clicked()
{
    this->close();
    emit exitpls();
}
