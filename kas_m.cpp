#include "kas_m.h"
#include "ui_kas_m.h"
#include "flights.h"
#include "QDebug"
#include "QFile"
#include "QTextStream"
#include "QIODevice"

QVector<passengers> kas_m::pass_db;
bool flight_sel;
int kas_m::sel_fl;
kas_m::kas_m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kas_m)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
}

void kas_m::plantTable()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < flights::f_db.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(flights::f_db[i].number));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(flights::f_db[i].from));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(flights::f_db[i].to));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(flights::f_db[i].mark));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(flights::f_db[i].seats)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(flights::f_db[i].f_seats)));
    }
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

void kas_m::on_tableWidget_cellClicked(int row)
{
    flight_sel = true;
    kas_m::sel_fl = row;
}

void kas_m::on_return_b_clicked()
{
    QFile file("D:\\DB\\passengers.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream ost(&file);
    load_db(ost);
    file.close();
}
