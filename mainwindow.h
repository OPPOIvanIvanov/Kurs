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

class UsersDataBase;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QVector<UsersDataBase> dt;

private slots:
    void OnLogInButtonClicked();
    void OnRegistrationButtonClicked();

private:
    Ui::MainWindow *ui;
    admin_m *a_m;
    kas_m *k_m;
    user_m *u_m;
    reg *r;

};
    void SaveData();
#endif // MAINWINDOW_H
