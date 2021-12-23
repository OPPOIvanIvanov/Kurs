#include "user_m.h"
#include "ui_user_m.h"
#include "flights.h"

user_m::user_m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_m)
{
    ui->setupUi(this);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
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
void user_m::getTable()
{
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_2->horizontalHeader()->setVisible(true);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < flights::f_db.size(); i++)
    {
        ui->tableWidget_2->insertRow(i);
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(flights::f_db[i].number));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(flights::f_db[i].from));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(flights::f_db[i].to));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(flights::f_db[i].mark));
        ui->tableWidget_2->setItem(i, 4, new QTableWidgetItem(QString::number(flights::f_db[i].seats)));
        ui->tableWidget_2->setItem(i, 5, new QTableWidgetItem(QString::number(flights::f_db[i].f_seats)));
    }
}
