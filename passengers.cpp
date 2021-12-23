#include "passengers.h"
#include "kas_m.h"

void load_db(QTextStream& ost)
{
    int i = 0;
     while(!ost.atEnd())
     {
         kas_m::pass_db.resize(i + 1);
         ost >> kas_m::pass_db[i].surname >> kas_m::pass_db[i].name
                 >> kas_m::pass_db[i].passport >> kas_m::pass_db[i].numb_fl;
         i++;
     }
}
