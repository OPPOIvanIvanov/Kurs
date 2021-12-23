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
    void setPass();

signals:
    void exitpls();
    void upd();

private slots:
    void on_back_clicked();

    void on_tableWidget_cellClicked(int row);

    void on_backup_clicked();

private:
    Ui::list_pass *ui;
};

#endif // LIST_PASS_H
