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

class UsersDataBase
{
public:
    UsersDataBase();
    QString name_;
    QString passw_;
    st status_;
};

void LoadDataBaseUsers(QTextStream& ost);
void InsertUser(QString n, QString p, st s);
void SaveToText(QTextStream& ost);
bool FindUser(QString str);
void DeleteUser(int index);
st FindStatus(QString str);
QString GetStatus(st status);

#endif // USERS_DB_H
