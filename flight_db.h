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
/*bool find_us(QString str);
void insert(QString n, QString p, st s);
void save_text(QTextStream& ost);
void del(int index);*/

#endif // FLIGHT_DB_H
