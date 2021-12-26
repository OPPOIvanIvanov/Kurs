#include "user_m.h"
#include "ui_user_m.h"
#include "flights.h"
#include "kas_m.h"
#include <QtGui>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>

QString user_m::text;
user_m::user_m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_m)
{
    ui->setupUi(this);
    us_fl = new us_flights;
    connect(us_fl, &us_flights::BackButton, this, &user_m::show);
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

void user_m::OnExitsClicked()
{
    this->close();
    emit BackButton();
}
void user_m::GetTable()
{
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_2->horizontalHeader()->setVisible(true);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < flights::f_db.size(); i++)
    {
        ui->tableWidget_2->insertRow(i);
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(flights::f_db[i].number_));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(flights::f_db[i].from_));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(flights::f_db[i].to_));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(flights::f_db[i].mark_));
        ui->tableWidget_2->setItem(i, 4, new QTableWidgetItem(QString::number(flights::f_db[i].seats_)));
        ui->tableWidget_2->setItem(i, 5, new QTableWidgetItem(QString::number(flights::f_db[i].free_seats)));
    }
}

void user_m::OnFlightsPaClicked()
{
    user_m::text = QInputDialog::getText(this,
    QString::fromUtf8("Введите необходимые данные"),
    QString::fromUtf8("Даные паспорта без пробелов:"),
    QLineEdit::Normal);
    if (FindPasport(user_m::text))
    {
        us_fl->show();
        us_fl->SetFlightsTable();
        this->close();
    }
    else
        QMessageBox::warning(this, "Внимание","Введены неверные данные");
}
