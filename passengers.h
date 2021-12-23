#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <QString>
#include <QVector>
#include <QTextStream>

class passengers
{
public:
    QString surname;
    QString name;
    QString patronymic;
    QString passport;
    QString numb_fl;
};
void load_db(QTextStream& ost);
void returnTicket(int indx);
void save_to_txt(QTextStream& ost);
bool find_pass(QString str);
void insert_pass(QString surname, QString name, QString patronymic, QString passport, QString numb_fl);
#endif // PASSENGERS_H
