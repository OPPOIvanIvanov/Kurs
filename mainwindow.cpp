#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFile"
#include "QTextStream"
#include "QIODevice"

QVector<users_db> MainWindow::dt;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file("D:\\DB\\users.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream ost(&file);
    load_data(ost);
    file.close();
    a_m = new admin_m;
    k_m = new kas_m;
    u_m = new user_m;
    r = new reg;
    connect(a_m, &admin_m::exitpls, this, &MainWindow::show);
    connect(k_m, &kas_m::exitpls, this, &MainWindow::show);
    connect(u_m, &user_m::exitpls, this, &MainWindow::show);
    connect(r, &reg::exitpls, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    QString str2 = ui->lineEdit_2->text();
    st stat = get_status(str, str2);
    switch(stat)
    {
    case pass:
        u_m->show();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        this->close();
        break;
    case kass:
        k_m->plantTable();
        k_m->show();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        this->close();
        break;
    case admin:
        a_m->settable();
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

void MainWindow::on_pushButton_2_clicked()
{
    r->show();
    this->close();
}

void save()
{
    QFile file("D:\\DB.\\users.txt");
    QFile::remove("D:\\DB\\users.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream ost(&file);
    save_text(ost);
    file.close();
}
