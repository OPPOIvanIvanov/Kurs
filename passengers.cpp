#include "passengers.h"
#include "kas_m.h"
#include "QDebug"

void LoadFlightsDataBase(QTextStream& ost)
{
    int i = 0;
     while(!ost.atEnd())
     {
         kas_m::passengers_data_base.resize(i + 1);
         ost >> kas_m::passengers_data_base[i].surname_ >> kas_m::passengers_data_base[i].name_
                 >> kas_m::passengers_data_base[i].patronymic_ >> kas_m::passengers_data_base[i].passport_
                 >> kas_m::passengers_data_base[i].numb_flight_;
                  i++;
     }
}

void ReturnTicket(int indx)
{
    kas_m::passengers_data_base.erase(kas_m::passengers_data_base.begin() + indx);
}

void SaveToTxt(QTextStream& ost)
{
    for (int i = 0; i < kas_m::passengers_data_base.size(); i++)
    {
        if (i != 0)
            ost << "\n";
        ost << kas_m::passengers_data_base[i].surname_ << " " << kas_m::passengers_data_base[i].name_
                << " " << kas_m::passengers_data_base[i].patronymic_ << " " << kas_m::passengers_data_base[i].passport_
                << " " << kas_m::passengers_data_base[i].numb_flight_;
    }
}

bool FindPassengers(QString pasport, QString number)
{
    for (int i = 0; i < kas_m::passengers_data_base.size(); i++)
    {
        if (kas_m::passengers_data_base[i].passport_ == pasport && kas_m::passengers_data_base[i].numb_flight_ == number)
            return true;
    }
    return false;
}

void InsertPassengers(QString surname, QString name, QString patronymic, QString passport, QString numb_fl)
{
    kas_m::passengers_data_base.resize(kas_m::passengers_data_base.size() + 1);
    kas_m::passengers_data_base[kas_m::passengers_data_base.size() - 1].surname_ = surname;
    kas_m::passengers_data_base[kas_m::passengers_data_base.size() - 1].name_ = name;
    kas_m::passengers_data_base[kas_m::passengers_data_base.size() - 1].patronymic_ = patronymic;
    kas_m::passengers_data_base[kas_m::passengers_data_base.size() - 1].passport_ = passport;
    kas_m::passengers_data_base[kas_m::passengers_data_base.size() - 1].numb_flight_ = numb_fl;
}

bool FindPasport(QString pasport)
{
    for (int i = 0; i < kas_m::passengers_data_base.size(); i++)
    {
        if (kas_m::passengers_data_base[i].passport_ == pasport)
            return true;
    }
    return false;
}
