#ifndef LIST_PASS_H
#define LIST_PASS_H

#include <QWidget>

namespace Ui {
class list_pass;
}

class list_pass : public QWidget
{
    Q_OBJECT

public:
    explicit list_pass(QWidget *parent = nullptr);
    ~list_pass();
    ///\brief Заполнить таблицу пассажиров
    void SetPassengersTable();

signals:
    void LeaveButton();
    void UpdatePassengersTable();

private slots:
    void OnBackClicked();
    void OnTableWidgetCellClicked(int row);
    void OnBackupClicked();

private:
    Ui::list_pass *ui;
};

#endif // LIST_PASS_H
