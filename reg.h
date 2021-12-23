#ifndef REG_H
#define REG_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class reg;
}

class reg : public QWidget
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = nullptr);
    ~reg();

signals:
    void exitpls();

private slots:
    void on_accept_clicked();

private:
    Ui::reg *ui;
};

#endif // REG_H
