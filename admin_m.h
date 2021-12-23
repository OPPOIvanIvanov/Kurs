#ifndef ADMIN_M_H
#define ADMIN_M_H

#include <QWidget>
#include <edit_us.h>
#include <flights.h>

namespace Ui {
class admin_m;
}
class admin_m : public QWidget
{
    Q_OBJECT

signals:
    void exitpls();

public:
    explicit admin_m(QWidget *parent = nullptr);
    ~admin_m();
    void settable();

    static int row_sel;

private slots:
    void on_exits_clicked();

    void on_deleteButton_clicked();

    void on_tableWidget_cellClicked(int row);

    void on_addButton_clicked();

    void on_change_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::admin_m *ui;
    edit_us *e_u;
    flights *f_m;
};
#endif // ADMIN_M_H
