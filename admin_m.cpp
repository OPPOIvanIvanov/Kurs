#include "admin_m.h"
#include "ui_admin_m.h"
#include "mainwindow.h"
#include <QDebug>
#include <QtGui>
#include <QMessageBox>

bool selected = false;
int admin_m::row_sel = -1;
admin_m::admin_m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_m)
{
    ui->setupUi(this);
    e_u = new edit_us;
    f_m = new flights;
    connect(e_u, &edit_us::UpdateUsersTable, this, &admin_m::SeTtable);
    connect(f_m, &flights::PreviousWindow, this, &admin_m::show);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}
void admin_m::SeTtable()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
     for (int i = 0; i < MainWindow::dt.size(); i++)
     {
         ui->tableWidget->insertRow(i);
         ui->tableWidget->setItem(i, 0, new QTableWidgetItem(MainWindow::dt[i].name_));
         ui->tableWidget->setItem(i, 1, new QTableWidgetItem(GetStatus(MainWindow::dt[i].status_)));
     }
}
admin_m::~admin_m()
{

    delete ui;
}

void admin_m::OnExitsClicked()
{
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    selected = false;
    this->close();
    emit PreviousWindow();
}

void admin_m::OnDeleteButtonClicked()
{
    if (selected == false)
    {
         QMessageBox::warning(this, "Внимание","Сначала выберите пользователя");
    }
    else {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QString::fromUtf8("Удаление пользователя"),
                          QString::fromUtf8("Вы действительно хотите удалить пользователя?"),
                          QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
          ui->tableWidget->setFocusPolicy(Qt::NoFocus);
          ui->tableWidget->removeRow(admin_m::row_sel);
          DeleteUser(admin_m::row_sel);
          selected = false;
    }
    }
}

void admin_m::OnTableWidgetCellClicked(int row)
{
    selected = true;
    admin_m::row_sel = row;
}

void admin_m::OnAddButtonClicked()
{
    e_u->AddUser();
    e_u->show();
}

void admin_m::OnChangeClicked()
{
    if (selected == false)
    {
         QMessageBox::warning(this, "Внимание","Сначала выберите пользователя");
    }
    else
    {
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    e_u->EditUser();
    e_u->show();
    selected = false;
    }
}

void admin_m::FlightManagement()
{
    f_m->SetTable();
    f_m->show();
    this->close();
}
