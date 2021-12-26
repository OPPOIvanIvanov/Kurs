#include "flights.h"
#include "ui_flights.h"
#include "QDebug"
#include "QFile"
#include "QTextStream"
#include "QIODevice"
#include <QMessageBox>

bool b;
int flights::row_s;
QVector<FlightDataBase> flights::f_db;
flights::flights(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flights)
{
    ui->setupUi(this);
    e_f = new edit_f;
    connect(e_f, &edit_f::UpdateTable, this, &flights::SetTable);
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
    LoadFlightDataBase(ost);
    file.close();
}

flights::~flights()
{
    delete ui;
}

void flights::UsersManagement()
{
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    b = false;
    this->close();
    emit PreviousWindow();
}
void flights::SetTable()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < flights::f_db.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(flights::f_db[i].number_));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(flights::f_db[i].from_));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(flights::f_db[i].to_));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(flights::f_db[i].mark_));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(flights::f_db[i].seats_)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(flights::f_db[i].free_seats)));
    }
}

void flights::OnTableWidgetCellClicked(int row)
{
    row_s = row;
    b = true;
}

void flights::OnDelFClicked()
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
          DeleteFlight(flights::row_s);
          SaveFlight();
          b = false;

    }
    }
}
void SaveFlight()
{
    QFile file("D:\\DB.\\flights.txt");
    QFile::remove("D:\\DB\\flights.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream ost(&file);
    SaveDataToText(ost);
    file.close();
}

void flights::OnAddFClicked()
{
    e_f->show();
    e_f->CreateFlight();
}

void flights::OnEdFClicked()
{
    if (!b)
    {
        QMessageBox::warning(this, "Внимание", "Сначала выберите рейс");
    }
    else
    {
        ui->tableWidget->setFocusPolicy(Qt::NoFocus);
        e_f->show();
        e_f->ChangeFlightt();
        b = false;
    }
}
