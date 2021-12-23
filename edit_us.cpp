#include "edit_us.h"
#include "ui_edit_us.h"
#include "mainwindow.h"
#include "QMessageBox"

bool ed;
edit_us::edit_us(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_us)
{
    ui->setupUi(this);
}

edit_us::~edit_us()
{
    delete ui;
}

void edit_us::on_ok_clicked()
{
    if ((ed || !find_us(ui->name_us->text())) && !ui->pssw->text().isEmpty() &&
            !ui->name_us->text().isEmpty())
    {
        st status = unknow;
        if (ui->comboBox->currentText() == "Пассажир")
            status = pass;
        else
            if (ui->comboBox->currentText() == "Кассир")
                  status = kass;
        else
                if (ui->comboBox->currentText() == "Администратор")
                    status = admin;
         if (ed)
         {
             del(admin_m::row_sel);
         }
         insert(ui->name_us->text(), ui->pssw->text(), status);
         save();
         ui->name_us->clear();
         ui->pssw->clear();
         ed = false;
         this->close();
         emit upd();
    }
    else
        if (!ed && find_us(ui->name_us->text()))
         QMessageBox::warning(this, "Внимание","Имя пользователя занято");
    else
            if (ui->pssw->text().isEmpty()||ui->name_us->text().isEmpty())
                QMessageBox::warning(this, "Внимание","Заполните пустые поля");
}

void edit_us::on_exit_clicked()
{
    ui->name_us->clear();
    ui->pssw->clear();
    this->close();

}
void edit_us::create()
{
    ui->label_4->setText("Добавление пользователя");
}
void edit_us::edit()
{
     ui->label_4->setText("Редактирование пользователя");
     ui->name_us->setText(MainWindow::dt[admin_m::row_sel].name);
     ui->pssw->setText(MainWindow::dt[admin_m::row_sel].passw);
     switch(MainWindow::dt[admin_m::row_sel].status)
     {
     case pass:
         ui->comboBox->setCurrentText("Пассажир");
         break;
     case kass:
          ui->comboBox->setCurrentText("Кассир");
         break;
     case admin:
        ui->comboBox->setCurrentText("Администратор");
         break;
     default:
         break;
     }
     ed = true;
}
