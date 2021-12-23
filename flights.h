#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <QWidget>
#include <flight_db.h>

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

    static QVector <flight_db> f_db;


signals:
    void exitpls();

private slots:
    void on_pushButton_4_clicked();
    void settable();

private:
    Ui::flights *ui;
};

#endif // FLIGHTS_H
