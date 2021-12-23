#ifndef USER_M_H
#define USER_M_H

#include <QWidget>
#include <us_flights.h>

namespace Ui {
class user_m;
}

class user_m : public QWidget
{
    Q_OBJECT

public:
    explicit user_m(QWidget *parent = nullptr);
    ~user_m();
    void getTable();
static QString text;
signals:
    void exitpls();

private slots:
    void on_exits_clicked();

    void on_flights_pa_clicked();

private:
    Ui::user_m *ui;
    us_flights *us_fl;
};

#endif // USER_M_H
