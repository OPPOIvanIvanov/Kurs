#ifndef K_SALES_H
#define K_SALES_H

#include <QWidget>

namespace Ui {
class k_sales;
}

class k_sales : public QWidget
{
    Q_OBJECT

public:
    explicit k_sales(QWidget *parent = nullptr);
    ~k_sales();

signals:
    void upd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::k_sales *ui;
};

#endif // K_SALES_H
