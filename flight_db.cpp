#include "flight_db.h"
#include "flights.h"

void load_text(QTextStream &ost)
{
   int i = 0;
    while(!ost.atEnd())
    {
        flights::f_db.resize(i + 1);
        ost >> flights::f_db[i].number >> flights::f_db[i].from
                >> flights::f_db[i].to >> flights::f_db[i].mark
                >> flights::f_db[i].seats >> flights::f_db[i].f_seats;
        i++;
    }
}

void save_txt(QTextStream& ost)
{
   for (int i = 0; i < flights::f_db.size(); i++)
   {
       if (i != 0)
           ost << "\n";
       ost << flights::f_db[i].number << " " << flights::f_db[i].from << " "
                << flights::f_db[i].to <<" " << flights::f_db[i].mark
                << " " << flights::f_db[i].seats <<" " << flights::f_db[i].f_seats;
   }
}

void del_f(int index)
{
    flights::f_db.erase(flights::f_db.begin() + index);
}

void insert_fl(QString number, QString from, QString to, QString mark, int seats, int f_seats)
{
    flights::f_db.resize(flights::f_db.size() + 1);
    flights::f_db[flights::f_db.size() - 1].number = number;
    flights::f_db[flights::f_db.size() - 1].from = from;
    flights::f_db[flights::f_db.size() - 1].to = to;
    flights::f_db[flights::f_db.size() - 1].mark = mark;
    flights::f_db[flights::f_db.size() - 1].seats = seats;
    flights::f_db[flights::f_db.size() - 1].f_seats = f_seats;
}

bool find_fl(QString number)
{
    for (int i = 0; i < flights::f_db.size(); i++)
    {
        if (flights::f_db[i].number == number)
            return true;
    }
    return false;
}

int find_indx(QString number)
{
    for (int i = 0; i < flights::f_db.size(); i++)
    {
        if (flights::f_db[i].number == number)
            return i;
    }
    return -1;
}
