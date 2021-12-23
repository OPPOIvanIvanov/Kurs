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
    connect(e_u, &edit_us::upd, this, &admin_m::settable);
    connect(f_m, &flights::exitpls, this, &admin_m::show);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}
void admin_m::settable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
     for (int i = 0; i < MainWindow::dt.size(); i++)
     {
         ui->tableWidget->insertRow(i);
         ui->tableWidget->setItem(i, 0, new QTableWidgetItem(MainWindow::dt[i].name));
         switch(MainWindow::dt[i].status)
         {
         case pass:
             ui->tableWidget->setItem(i, 1, new QTableWidgetItem("Пассажир"));
             break;
         case kass:
              ui->tableWidget->setItem(i, 1, new QTableWidgetItem("Кассир"));
             break;
         case admin:
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem("Администратор"));
             break;
         default:
             break;
         }
     }
}
admin_m::~admin_m()
{

    delete ui;
}

void admin_m::on_exits_clicked()
{
    this->close();
    emit exitpls();
}

void admin_m::on_deleteButton_clicked()
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
          del(admin_m::row_sel);
          selected = false;
    }
    }
}

void admin_m::on_tableWidget_cellClicked(int row)
{
    selected = true;
    admin_m::row_sel = row;
}

void admin_m::on_addButton_clicked()
{
    e_u->create();
    e_u->show();
}

void admin_m::on_change_clicked()
{
    if (selected == false)
    {
         QMessageBox::warning(this, "Внимание","Сначала выберите пользователя");
    }
    else
    {
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    e_u->edit();
    e_u->show();
    selected = false;
    }
}

void admin_m::on_pushButton_3_clicked()
{
    f_m->settable();
    f_m->show();
    this->close();
}
