#include "edit_f.h"
#include "ui_edit_f.h"
#include "flights.h"
#include "flight_db.h"
#include "QMessageBox"

bool mode;
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

void edit_f::on_pushButton_clicked()
{
    if ((mode || !find_fl(ui->num->text())) && !ui->num->text().isEmpty() &&
          !ui->count->text().isEmpty() && !ui->free->text().isEmpty()
            && !ui->from->text().isEmpty() && !ui->mark->text().isEmpty()
            && !ui->to->text().isEmpty())
    {
         if (mode)
         {
             del_f(flights::row_s);
         }
         insert_fl(ui->num->text(), ui->from->text(), ui->to->text(),
                   ui->mark->text(), ui->count->text().toInt(), ui->free->text().toInt());
         save_f();
         this->close();
         emit upd();
    }
    else
        if (!mode && find_fl(ui->num->text()))
         QMessageBox::warning(this, "Внимание","Имя пользователя занято");
    else
            if (ui->num->text().isEmpty() || ui->count->text().isEmpty() ||
                    ui->free->text().isEmpty() || ui->from->text().isEmpty() ||
                    ui->mark->text().isEmpty() || !ui->to->text().isEmpty())
                QMessageBox::warning(this, "Внимание","Заполните пустые поля");
}

void edit_f::create_f()
{
    ui->label_7->setText("Добавление рейса");
    mode = false;
}

void edit_f::change_f()

{
    ui->label_7->setText("Редактирование рейса");
    mode = true;
    ui->num->setText(flights::f_db[flights::row_s].number);
    ui->from->setText(flights::f_db[flights::row_s].from);
    ui->to->setText(flights::f_db[flights::row_s].to);
    ui->mark->setText(flights::f_db[flights::row_s].mark);
    ui->count->setText(QString::number(flights::f_db[flights::row_s].seats));
    ui->free->setText(QString::number(flights::f_db[flights::row_s].f_seats));
}

void edit_f::on_pushButton_2_clicked()
{
    this->close();
}
