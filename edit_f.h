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

    void CreateFlight();
    void ChangeFlightt();

signals:
    void UpdateTable();

private slots:
    void OkButton();
    void CloseButton();

private:
    Ui::edit_f *ui;
};

#endif // EDIT_F_H
