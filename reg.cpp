#include "reg.h"
#include "ui_reg.h"
#include "mainwindow.h"
#include <QMessageBox>

reg::reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reg)
{
    ui->setupUi(this);
}

reg::~reg()
{
    delete ui;
}

void reg::on_accept_clicked()
{
    if (!find_us(ui->lineEdit->text()) && (ui->lineEdit_2->text() == ui->lineEdit_3->text())
            && !ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty())
    {
        st s = pass;
        insert(ui->lineEdit->text(), ui->lineEdit_2->text(), s);
        save();
        this->close();
        emit exitpls();
    }
    else
        if (find_us(ui->lineEdit->text()))
        {
            QMessageBox::warning(this, "Внимание","Такой пользователь уже существует");
        }
    else
            if (ui->lineEdit_2->text() != ui->lineEdit_3->text())
                QMessageBox::warning(this, "Внимание","Пароли не совпадают");
    else
            if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
                QMessageBox::warning(this, "Внимание","Заполните пустые поля");
}
