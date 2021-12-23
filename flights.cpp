#include "flights.h"
#include "ui_flights.h"
#include "QDebug"
#include "QFile"
#include "QTextStream"
#include "QIODevice"
#include <QMessageBox>

bool b;
int flights::row_s;
QVector<flight_db> flights::f_db;
flights::flights(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flights)
{
    ui->setupUi(this);
    e_f = new edit_f;
    connect(e_f, &edit_f::upd, this, &flights::settable);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    QFile file("D:\\DB\\flights.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream ost(&file);
    load_text(ost);
    file.close();
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

void flights::on_tableWidget_cellClicked(int row)
{
    row_s = row;
    b = true;
}

void flights::on_del_f_clicked()
{
    if (b == false)
    {
         QMessageBox::warning(this, "Внимание","Выберите рейс");
    }
    else {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QString::fromUtf8("Удаление рейса"),
                          QString::fromUtf8("Вы действительно хотите удалить рейс?"),
                          QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
          ui->tableWidget->setFocusPolicy(Qt::NoFocus);
          ui->tableWidget->removeRow(flights::row_s);
          del_f(flights::row_s);
          save_f();
          b = false;

    }
    }
}
void save_f()
{
    QFile file("D:\\DB.\\flights.txt");
    QFile::remove("D:\\DB\\flights.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream ost(&file);
    save_txt(ost);
    file.close();
}

void flights::on_add_f_clicked()
{
    e_f->show();
    e_f->create_f();
}

void flights::on_ed_f_clicked()
{
    if (!b)
    {
        QMessageBox::warning(this, "Внимание", "Сначала выберите рейс");
    }
    else
    {
        ui->tableWidget->setFocusPolicy(Qt::NoFocus);
        e_f->show();
        e_f->change_f();
        b = false;
    }
}
