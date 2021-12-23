#include "kas_m.h"
#include "ui_kas_m.h"
#include "flights.h"
#include "QFile"
#include "QTextStream"
#include "QIODevice"
#include "QMessageBox"
#include "passengers.h"

QVector<passengers> kas_m::pass_db;
bool flight_sel;
int kas_m::sel_fl;
kas_m::kas_m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kas_m)
{
    ui->setupUi(this);
    l_p = new list_pass;
    k_s = new k_sales;
    connect(l_p, &list_pass::exitpls, this, &kas_m::show);
    connect(l_p, &list_pass::upd, this, &kas_m::plantTable);
    connect(k_s, &k_sales::upd, this, &kas_m::plantTable);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    QFile file_p("D:\\DB\\passengers.txt");
    file_p.open(QIODevice::ReadOnly);
    QTextStream ist(&file_p);
    load_db(ist);
    file_p.close();
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
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

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
    if (flight_sel == false)
    {
         QMessageBox::warning(this, "Внимание","Сначала выберите рейс");
    }
    else
    {
        ui->tableWidget->setFocusPolicy(Qt::NoFocus);
        l_p->setPass();
        l_p->show();
        flight_sel = false;
        this->close();
    }
}

void kas_m::on_sale_b_clicked()
{
    if (flight_sel == false)
    {
         QMessageBox::warning(this, "Внимание","Сначала выберите рейс");
    }
    else
    {
        ui->tableWidget->setFocusPolicy(Qt::NoFocus);
        flight_sel = false;
        k_s->show();
    }
}
