#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <QWidget>

namespace Ui {
class flights;
}

class flights : public QWidget
{
    Q_OBJECT

public:
    explicit flights(QWidget *parent = nullptr);
    ~flights();

signals:
    void exitpls();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::flights *ui;
};

#endif // FLIGHTS_H
