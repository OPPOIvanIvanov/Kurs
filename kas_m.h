#ifndef KAS_M_H
#define KAS_M_H

#include <QWidget>

namespace Ui {
class kas_m;
}

class kas_m : public QWidget
{
    Q_OBJECT

public:
    explicit kas_m(QWidget *parent = nullptr);
    ~kas_m();

signals:
    void exitpls();

private slots:
    void on_exits_clicked();

private:
    Ui::kas_m *ui;
};

#endif // KAS_M_H
