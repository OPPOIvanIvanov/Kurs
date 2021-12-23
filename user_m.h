#ifndef USER_M_H
#define USER_M_H

#include <QWidget>

namespace Ui {
class user_m;
}

class user_m : public QWidget
{
    Q_OBJECT

public:
    explicit user_m(QWidget *parent = nullptr);
    ~user_m();

signals:
    void exitpls();

private slots:
    void on_exits_clicked();

private:
    Ui::user_m *ui;
};

#endif // USER_M_H
