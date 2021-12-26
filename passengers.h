#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <QString>
#include <QVector>
#include <QTextStream>

class PassengersDataBase
{
public:
    QString surname_;
    QString name_;
    QString patronymic_;
    QString passport_;
    QString numb_flight_;
};
void LoadDataBase(QTextStream& ost);
void ReturnTicket(int indx);
void SaveToTxt(QTextStream& ost);
bool FindPassengers(QString str, QString str2);
void InsertPassengers(QString surname, QString name, QString patronymic, QString passport, QString numb_fl);
bool FindPasport(QString str);
#endif // PASSENGERS_H
