#include "passengers.h"
#include "kas_m.h"
#include "QDebug"

void load_db(QTextStream& ost)
{
    int i = 0;
     while(!ost.atEnd())
     {
         kas_m::pass_db.resize(i + 1);
         ost >> kas_m::pass_db[i].surname >> kas_m::pass_db[i].name
                 >> kas_m::pass_db[i].patronymic >> kas_m::pass_db[i].passport
                 >> kas_m::pass_db[i].numb_fl;
                  i++;
     }
}

void returnTicket(int indx)
{
    kas_m::pass_db.erase(kas_m::pass_db.begin() + indx);
}

void save_to_txt(QTextStream& ost)
{
    for (int i = 0; i < kas_m::pass_db.size(); i++)
    {
        if (i != 0)
            ost << "\n";
        ost << kas_m::pass_db[i].surname << " " << kas_m::pass_db[i].name
                << " " << kas_m::pass_db[i].patronymic << " " << kas_m::pass_db[i].passport
                << " " << kas_m::pass_db[i].numb_fl;
    }
}
