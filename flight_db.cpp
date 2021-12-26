#include "flight_db.h"
#include "flights.h"

void LoadFlightDataBase(QTextStream &ost)
{
   int i = 0;
    while(!ost.atEnd())
    {
        flights::f_db.resize(i + 1);
        ost >> flights::f_db[i].number_ >> flights::f_db[i].from_
                >> flights::f_db[i].to_ >> flights::f_db[i].mark_
                >> flights::f_db[i].seats_ >> flights::f_db[i].free_seats;
        i++;
    }
}

void SaveDataToText(QTextStream& ost)
{
   for (int i = 0; i < flights::f_db.size(); i++)
   {
       if (i != 0)
           ost << "\n";
       ost << flights::f_db[i].number_ << " " << flights::f_db[i].from_ << " "
                << flights::f_db[i].to_ <<" " << flights::f_db[i].mark_
                << " " << flights::f_db[i].seats_ <<" " << flights::f_db[i].free_seats;
   }
}

void DeleteFlight(int index)
{
    flights::f_db.erase(flights::f_db.begin() + index);
}

void InsertFlight(QString number, QString from, QString to, QString mark, int seats, int f_seats)
{
    flights::f_db.resize(flights::f_db.size() + 1);
    flights::f_db[flights::f_db.size() - 1].number_ = number;
    flights::f_db[flights::f_db.size() - 1].from_ = from;
    flights::f_db[flights::f_db.size() - 1].to_ = to;
    flights::f_db[flights::f_db.size() - 1].mark_ = mark;
    flights::f_db[flights::f_db.size() - 1].seats_ = seats;
    flights::f_db[flights::f_db.size() - 1].free_seats = f_seats;
}

bool CheckFlght(QString number)
{
    for (int i = 0; i < flights::f_db.size(); i++)
    {
        if (flights::f_db[i].number_ == number)
            return true;
    }
    return false;
}

int FindIndexFromNumber(QString number)
{
    for (int i = 0; i < flights::f_db.size(); i++)
    {
        if (flights::f_db[i].number_ == number)
            return i;
    }
    return -1;
}
