#ifndef USERS_DB_H
#define USERS_DB_H

#include <QString>
#include <QVector>
#include <QTextStream>
#include "mainwindow.h"

enum st // создание перечисляемого типа enum
{
    pass,
    kass,
    admin,
    unknow
};

class users_db
{
public:
    users_db();
    QString name;
    QString passw;
    st status;
};

void load_data(QTextStream& ost);
st get_status(QString str);
bool find_us(QString str);
void insert(QString n, QString p, st s);
void save_text(QTextStream& ost);
void del(int index);

#endif // USERS_DB_H
