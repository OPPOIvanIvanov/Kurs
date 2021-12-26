#include "edit_us.h"
#include "ui_edit_us.h"
#include "mainwindow.h"
#include "QMessageBox"

bool ed;
QString name;
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

void edit_us::OnOkClicked()
{
    bool changed = true;
    if (ui->name_us->text() == name)
        changed = false;
    if ((!changed || !FindUser(ui->name_us->text())) && !ui->pssw->text().isEmpty() &&
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
             DeleteUser(admin_m::row_sel);
         }
         InsertUser(ui->name_us->text(), ui->pssw->text(), status);
         SaveData();
         ui->name_us->clear();
         ui->pssw->clear();
         ed = false;
         this->close();
         emit UpdateUsersTable();
    }
    else
        if (changed && FindUser(ui->name_us->text()))
         QMessageBox::warning(this, "Внимание","Имя пользователя занято");
    else
            if (ui->pssw->text().isEmpty()||ui->name_us->text().isEmpty())
                QMessageBox::warning(this, "Внимание","Заполните пустые поля");
}

void edit_us::OnExitClicked()
{
    ui->name_us->clear();
    ui->pssw->clear();
    this->close();

}
void edit_us::AddUser()
{
    ui->label_4->setText("Добавление пользователя");
}
void edit_us::EditUser()
{
     ui->label_4->setText("Редактирование пользователя");
     ui->name_us->setText(MainWindow::dt[admin_m::row_sel].name_);
     ui->pssw->setText(MainWindow::dt[admin_m::row_sel].passw_);
     ui->comboBox->setCurrentText(GetStatus(MainWindow::dt[admin_m::row_sel].status_));
     name = ui->name_us->text();
     ed = true;
}
