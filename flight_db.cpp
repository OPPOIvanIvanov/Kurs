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
