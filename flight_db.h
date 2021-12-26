#ifndef FLIGHT_DB_H
#define FLIGHT_DB_H

#include <QString>
#include <QVector>
#include <QTextStream>
#include <flights.h>

class FlightDataBase
{
public:
    QString number_;
    QString from_;
    QString to_;
    QString mark_;
    int seats_;
    int free_seats;
};

void LoadFlightDataBase(QTextStream& ost);
void DeleteFlight(int index);
void SaveDataToText(QTextStream& ost);
int FindIndexFromNumber(QString number);
bool CheckFlght(QString number);
void InsertFlight(QString number, QString from, QString to, QString mark, int seats, int f_seats);

#endif // FLIGHT_DB_H
