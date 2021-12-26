#include "list_pass.h"
#include "ui_list_pass.h"
#include "QDebug"
#include "QFile"
#include "QTextStream"
#include "QIODevice"
#include "QMessageBox"
#include "passengers.h"
#include "kas_m.h"
#include "flights.h"

int pass_row;
bool pass_sel;
list_pass::list_pass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_pass)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
}

list_pass::~list_pass()
{
    delete ui;
}

void list_pass::OnBackClicked()
{
    QFile file_f("D:\\DB.\\flights.txt");
    QFile::remove("D:\\DB\\flights.txt");
    file_f.open(QIODevice::WriteOnly);
    QTextStream ost_f(&file_f);
    SaveDataToText(ost_f);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    pass_sel = false;
    emit UpdatePassengersTable();
    this->close();
    emit LeaveButton();
}
void list_pass::SetPassengersTable()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    for (int i = 0; i < kas_m::passengers_data_base.size(); i++)
    {
        int j = 0;
        if (kas_m::passengers_data_base[i].numb_flight_ == flights::f_db[kas_m::selected_flight].number_)
        {
        ui->tableWidget->insertRow(j);
        ui->tableWidget->setItem(j, 0, new QTableWidgetItem(kas_m::passengers_data_base[i].surname_));
        ui->tableWidget->setItem(j, 1, new QTableWidgetItem(kas_m::passengers_data_base[i].name_));
        ui->tableWidget->setItem(j, 2, new QTableWidgetItem(kas_m::passengers_data_base[i].patronymic_));
        ui->tableWidget->setItem(j, 3, new QTableWidgetItem(kas_m::passengers_data_base[i].passport_));
        ui->tableWidget->setItem(j, 4, new QTableWidgetItem(kas_m::passengers_data_base[i].numb_flight_));
        j++;
        }
    }

}

void list_pass::OnTableWidgetCellClicked(int row)
{
    pass_row = row;
    pass_sel = true;
}

void list_pass::OnBackupClicked()
{
    if (pass_sel == false)
    {
         QMessageBox::warning(this, "Внимание","Выберите пассажира");
    }
    else {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QString::fromUtf8("Возврат билета"),
                          QString::fromUtf8("Вы действительно хотите оформить возврат?"),
                          QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
          ui->tableWidget->setFocusPolicy(Qt::NoFocus);
          ui->tableWidget->removeRow(pass_row);
          flights::f_db[FindIndexFromNumber(kas_m::passengers_data_base[pass_row].numb_flight_)].free_seats++;
          ReturnTicket(kas_m::selected_flight);
          pass_sel = false;
          QFile file("D:\\DB.\\passengers.txt");
          QFile::remove("D:\\DB\\passengers.txt");
          file.open(QIODevice::WriteOnly);
          QTextStream ost(&file);
          SaveToTxt(ost);
          file.close();
    }
    }
}
