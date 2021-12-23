#include "k_sales.h"
#include "ui_k_sales.h"
#include "flights.h"
#include "kas_m.h"
#include "passengers.h"
#include "QMessageBox"
#include "QFile"
#include "QTextStream"
#include "QIODevice"

k_sales::k_sales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::k_sales)
{
    ui->setupUi(this);
}

k_sales::~k_sales()
{
    delete ui;
}

void k_sales::on_pushButton_clicked()
{
    if (!find_pass(ui->passport->text(), ui->num->text()) && !ui->name->text().isEmpty()
            && !ui->famil->text().isEmpty() && !ui->name->text().isEmpty()
            && !ui->patr->text().isEmpty() && !ui->passport->text().isEmpty())
    {
      insert_pass(ui->famil->text(), ui->name->text(), ui->patr->text(),
                  ui->passport->text(), ui->num->text());
      QFile file("D:\\DB.\\passengers.txt");
      QFile::remove("D:\\DB\\passengers.txt");
      file.open(QIODevice::WriteOnly);
      QTextStream ost(&file);
      flights::f_db[kas_m::sel_fl].f_seats--;
      save_to_txt(ost);
      ui->name->clear();
      ui->famil->clear();
      ui->num->clear();
      ui->patr->clear();
      ui->passport->clear();
      emit upd();
      QFile file_f("D:\\DB.\\flights.txt");
      file_f.open(QIODevice::WriteOnly);
      QTextStream ost_f(&file_f);
      save_txt(ost_f);
      this->close();
    }
    else
        if (find_pass(ui->passport->text(), ui->num->text()))
        {
            QMessageBox::warning(this, "Внимание","Такой пассажир уже есть на данном рейсе");
        }
    else
        if (ui->name->text().isEmpty() || ui->famil->text().isEmpty() || ui->name->text().isEmpty()
                || ui->patr->text().isEmpty() || ui->passport->text().isEmpty())
        {
            QMessageBox::warning(this, "Внимание","Заполните пустые поля");
        }
}

void k_sales::on_pushButton_2_clicked()
{
    this->close();
}

void k_sales::set_num()
{
    ui->num->setText(flights::f_db[kas_m::sel_fl].number);
}
