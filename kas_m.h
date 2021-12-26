#ifndef KAS_M_H
#define KAS_M_H

#include <QWidget>
#include <passengers.h>
#include <list_pass.h>
#include <k_sales.h>

namespace Ui {
class kas_m;
}
class PassengersDataBase;
class kas_m : public QWidget
{
    Q_OBJECT

public:
    explicit kas_m(QWidget *parent = nullptr);
    ~kas_m();
    void PlantTable();
    static int selected_flight;
    static QVector<PassengersDataBase> passengers_data_base;

signals:
    void  UpdateKassirTable();

private slots:
    void OnExitsClicked();
    void OnTableWidgetCellClicked(int row);
    void OnReturnButtonClicked();
    void OnSaleButtonClicked();

private:
    Ui::kas_m *ui;
    list_pass *l_p;
    k_sales *k_s;
};

#endif // KAS_M_H
