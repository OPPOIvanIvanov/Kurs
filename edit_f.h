#ifndef EDIT_F_H
#define EDIT_F_H

#include <QWidget>

namespace Ui {
class edit_f;
}

class edit_f : public QWidget
{
    Q_OBJECT

public:
    explicit edit_f(QWidget *parent = nullptr);
    ~edit_f();

    void create_f();
    void change_f();

signals:
    void upd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::edit_f *ui;
};

#endif // EDIT_F_H
