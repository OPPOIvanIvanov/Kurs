#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <users_db.h>
#include <admin_m.h>
#include <kas_m.h>
#include <user_m.h>
#include <reg.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class users_db;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QVector<users_db> dt;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    admin_m *a_m;
    kas_m *k_m;
    user_m *u_m;
    reg *r;

};
    void save();
#endif // MAINWINDOW_H
