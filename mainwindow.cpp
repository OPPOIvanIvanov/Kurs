#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFile"
#include "QTextStream"
#include "QIODevice"
#include "QMessageBox"

QVector<UsersDataBase> MainWindow::dt;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file("D:\\DB\\users.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream ost(&file);
    LoadDataBaseUsers(ost);
    file.close();
    a_m = new admin_m;
    k_m = new kas_m;
    u_m = new user_m;
    r = new reg;
    connect(a_m, &admin_m::PreviousWindow, this, &MainWindow::show);
    connect(k_m, &kas_m:: UpdateKassirTable, this, &MainWindow::show);
    connect(u_m, &user_m::BackButton, this, &MainWindow::show);
    connect(r, &reg::BackButton, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnLogInButtonClicked()
{
    bool accept = false;
    QString str = ui->lineEdit->text();
    QString str2 = ui->lineEdit_2->text();
    for (int i = 0; i < MainWindow::dt.size(); i++)
    {
        if (MainWindow::dt[i].passw_ == str2 && MainWindow::dt[i].name_ == str)
        {
            accept = true;
            st stat = FindStatus(str);
            switch(stat)
            {
            case pass:
                u_m->show();
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                u_m->GetTable();
                this->close();
                break;
            case kass:
                k_m->PlantTable();
                k_m->show();
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                this->close();
                break;
            case admin:
                a_m->SeTtable();
                a_m->show();
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                this->close();
                break;
            case unknow:

                break;
            default:

               break;
            }
        }
    }
    if(!accept)
    {
        if (str.isEmpty() || str2.isEmpty())
                QMessageBox::warning(this, "Внимание","Заполните пустые поля");
        else
                QMessageBox::warning(this, "Внимание","Неверное имя пользователя или пароль");
    }
}

void MainWindow::OnRegistrationButtonClicked()
{
    r->show();
    this->close();
}

void SaveData()
{
    QFile file("D:\\DB.\\users.txt");
    QFile::remove("D:\\DB\\users.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream ost(&file);
    SaveToText(ost);
    file.close();
}
