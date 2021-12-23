#include "flights.h"
#include "ui_flights.h"
#include "QDebug"
#include "QFile"
#include "QTextStream"
#include "QIODevice"

QVector<flight_db> flights::f_db;
flights::flights(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flights)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    QFile file("D:\\DB\\flights.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream ost(&file);
    load_text(ost);
    file.close();
    for (int i = 0; i < flights::f_db.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(flights::f_db[i].number));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(flights::f_db[i].from));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(flights::f_db[i].to));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(flights::f_db[i].mark));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(flights::f_db[i].seats));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(flights::f_db[i].f_seats));
    }
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
void flights::settable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

}
