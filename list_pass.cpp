#include "list_pass.h"
#include "ui_list_pass.h"

list_pass::list_pass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_pass)
{
    ui->setupUi(this);
}

list_pass::~list_pass()
{
    delete ui;
}
