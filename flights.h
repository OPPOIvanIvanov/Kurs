#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <QWidget>
#include <flight_db.h>
#include <edit_f.h>

namespace Ui {
class flights;
}
class FlightDataBase;
class flights : public QWidget
{
    Q_OBJECT

public:
    explicit flights(QWidget *parent = nullptr);
    ~flights();

void SetTable();

    static QVector <FlightDataBase> f_db;
    static int row_s;


signals:
    void PreviousWindow();

private slots:
    void UsersManagement();
    void OnTableWidgetCellClicked(int row);
    void OnDelFClicked();
    void OnAddFClicked();
    void OnEdFClicked();

private:
    Ui::flights *ui;
    edit_f * e_f;
};
void SaveFlight();
#endif // FLIGHTS_H
