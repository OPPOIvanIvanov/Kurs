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
    void PreviousWindow();

public:
    explicit admin_m(QWidget *parent = nullptr);
    ~admin_m();
    ///\brief Метод нужен для заполнения таблицы
    void SeTtable();

    static int row_sel;

private slots:
    void OnExitsClicked();
    void OnDeleteButtonClicked();
    void OnTableWidgetCellClicked(int row);
    void OnAddButtonClicked();
    void OnChangeClicked();
    void FlightManagement();

private:
    Ui::admin_m *ui;
    edit_us *e_u;
    flights *f_m;
};
#endif // ADMIN_M_H
