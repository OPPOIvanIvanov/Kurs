#ifndef EDIT_US_H
#define EDIT_US_H

#include <QWidget>

namespace Ui {
class edit_us;
}

class edit_us : public QWidget
{
    Q_OBJECT

public:
    explicit edit_us(QWidget *parent = nullptr);
    ~edit_us();
    void create();
    void edit();
signals:
    void upd();

private slots:
    void on_ok_clicked();

    void on_exit_clicked();

private:
    Ui::edit_us *ui;
};
#endif // EDIT_US_H
