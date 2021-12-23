#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <QWidget>
#include <flight_db.h>
#include <edit_f.h>

namespace Ui {
class flights;
}
class flight_db;
class flights : public QWidget
{
    Q_OBJECT

public:
    explicit flights(QWidget *parent = nullptr);
    ~flights();

void settable();

    static QVector <flight_db> f_db;
    static int row_s;


signals:
    void exitpls();

private slots:
    void on_pushButton_4_clicked();

    void on_tableWidget_cellClicked(int row);

    void on_del_f_clicked();

    void on_add_f_clicked();

    void on_ed_f_clicked();

private:
    Ui::flights *ui;
    edit_f * e_f;
};
void save_f();
#endif // FLIGHTS_H
