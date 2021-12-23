#include "flights.h"
#include "ui_flights.h"

flights::flights(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flights)
{
    ui->setupUi(this);
}

flights::~flights()
{
    delete ui;
}

void flights::on_pushButton_4_clicked()
{
    this->close();
    emit exitpls();
}
