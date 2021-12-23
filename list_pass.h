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

private:
    Ui::list_pass *ui;
};

#endif // LIST_PASS_H
