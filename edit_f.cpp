#include "edit_f.h"
#include "ui_edit_f.h"
#include "flights.h"
#include "flight_db.h"
#include "QMessageBox"

bool mode;
QString str;
edit_f::edit_f(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_f)
{
    ui->setupUi(this);
}

edit_f::~edit_f()
{
    delete ui;
}

void edit_f::OkButton()
{
    bool new_value = true;
    if (ui->num->text() == str)
        new_value = false;
    if ((!new_value || !CheckFlght(ui->num->text())) && !ui->num->text().isEmpty() &&
          !ui->count->text().isEmpty() && !ui->free->text().isEmpty()
            && !ui->from->text().isEmpty() && !ui->mark->text().isEmpty()
            && !ui->to->text().isEmpty() && (ui->free->text() <= ui->count->text()))
    {
         if (mode)
         {
             DeleteFlight(flights::row_s);
         }
         InsertFlight(ui->num->text(), ui->from->text(), ui->to->text(),
                   ui->mark->text(), ui->count->text().toInt(), ui->free->text().toInt());
         SaveFlight();
         ui->count->clear();
         ui->free->clear();
         ui->from->clear();
         ui->mark->clear();
         ui->num->clear();
         ui->to->clear();
         this->close();
         emit UpdateTable();
    }
    else
        if (new_value && CheckFlght(ui->num->text()))
         QMessageBox::warning(this, "Внимание","Номер рейса занят");
    else
            if (ui->num->text().isEmpty() || ui->count->text().isEmpty() ||
                    ui->free->text().isEmpty() || ui->from->text().isEmpty() ||
                    ui->mark->text().isEmpty() || ui->to->text().isEmpty())
                QMessageBox::warning(this, "Внимание","Заполните пустые поля");
    else
            if (ui->free->text() > ui->count->text())
               QMessageBox::warning(this, "Внимание",
                               "Свободных мест не может быть больше общего числа мест");
}

void edit_f::CreateFlight()
{
    ui->label_7->setText("Добавление рейса");
    mode = false;
}

void edit_f::ChangeFlightt()

{
    ui->label_7->setText("Редактирование рейса");
    str = flights::f_db[flights::row_s].number_;
    mode = true;
    ui->num->setText(flights::f_db[flights::row_s].number_);
    ui->from->setText(flights::f_db[flights::row_s].from_);
    ui->to->setText(flights::f_db[flights::row_s].to_);
    ui->mark->setText(flights::f_db[flights::row_s].mark_);
    ui->count->setText(QString::number(flights::f_db[flights::row_s].seats_));
    ui->free->setText(QString::number(flights::f_db[flights::row_s].free_seats));
}

void edit_f::CloseButton()
{
    this->close();
}
