#include "us_flights.h"
#include "ui_us_flights.h"
#include "kas_m.h"
#include "user_m.h"
#include "flights.h"

us_flights::us_flights(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::us_flights)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
}

us_flights::~us_flights()
{
    delete ui;
}

void us_flights::pop_table()
{
    int j = 0;
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < kas_m::pass_db.size(); i++)
        if (kas_m::pass_db[i].passport == user_m::text)
        {
                ui->tableWidget->insertRow(j);
                ui->tableWidget->setItem(j, 0, new QTableWidgetItem(flights::f_db[find_indx(kas_m::pass_db[i].numb_fl)].number));
                ui->tableWidget->setItem(j, 1, new QTableWidgetItem(flights::f_db[find_indx(kas_m::pass_db[i].numb_fl)].from));
                ui->tableWidget->setItem(j, 2, new QTableWidgetItem(flights::f_db[find_indx(kas_m::pass_db[i].numb_fl)].to));
                ui->tableWidget->setItem(j, 3, new QTableWidgetItem(flights::f_db[find_indx(kas_m::pass_db[i].numb_fl)].mark));
                ui->tableWidget->setItem(j, 4, new QTableWidgetItem(QString::number(flights::f_db[find_indx(kas_m::pass_db[i].numb_fl)].seats)));
                ui->tableWidget->setItem(j, 5, new QTableWidgetItem(QString::number(flights::f_db[find_indx(kas_m::pass_db[i].numb_fl)].f_seats)));
                j++;
        }
}

void us_flights::on_pushButton_clicked()
{
    this->close();
    emit exitpls();
}
