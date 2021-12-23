#ifndef KAS_M_H
#define KAS_M_H

#include <QWidget>
#include <passengers.h>
#include <list_pass.h>

namespace Ui {
class kas_m;
}
class passengers;
class kas_m : public QWidget
{
    Q_OBJECT

public:
    explicit kas_m(QWidget *parent = nullptr);
    ~kas_m();
    void plantTable();
    static int sel_fl;
    static QVector<passengers> pass_db;

signals:
    void exitpls();

private slots:
    void on_exits_clicked();

    void on_tableWidget_cellClicked(int row);

    void on_return_b_clicked();

private:
    Ui::kas_m *ui;
    list_pass *l_p;
};

#endif // KAS_M_H
