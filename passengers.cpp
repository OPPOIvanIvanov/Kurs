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

bool find_pass(QString str)
{
    for (int i = 0; i < kas_m::pass_db.size(); i++)
    {
        if (kas_m::pass_db[i].passport == str)
            return true;
    }
    return false;
}

void insert_pass(QString surname, QString name, QString patronymic, QString passport, QString numb_fl)
{
    kas_m::pass_db.resize(kas_m::pass_db.size() + 1);
    kas_m::pass_db[kas_m::pass_db.size() - 1].surname = surname;
    kas_m::pass_db[kas_m::pass_db.size() - 1].name = name;
    kas_m::pass_db[kas_m::pass_db.size() - 1].patronymic = patronymic;
    kas_m::pass_db[kas_m::pass_db.size() - 1].passport = passport;
    kas_m::pass_db[kas_m::pass_db.size() - 1].numb_fl = numb_fl;
}
