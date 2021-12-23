#ifndef FLIGHT_DB_H
#define FLIGHT_DB_H

#include <QString>
#include <QVector>
#include <QTextStream>
#include <flights.h>

class flight_db
{
public:
    QString number;
    QString from;
    QString to;
    QString mark;
    int seats;
    int f_seats;
};

void load_text(QTextStream& ost);
void del_f(int index);
void save_txt(QTextStream& ost);
bool find_fl(QString number);
void insert_fl(QString number, QString from, QString to, QString mark, int seats, int f_seats);

#endif // FLIGHT_DB_H
