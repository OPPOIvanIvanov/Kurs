#include "users_db.h"

UsersDataBase::UsersDataBase()
{

}
void LoadDataBaseUsers(QTextStream &ost)
{
    int i = 0;
    while(!ost.atEnd())
    {
        MainWindow::dt.resize(i + 1);
        ost >> MainWindow::dt[i].name_ >> MainWindow::dt[i].passw_;
        int x;
        ost >> x;
        switch(x)
        {
        case 0:
            MainWindow::dt[i].status_ = pass;
            break;
        case 1:
            MainWindow::dt[i].status_ = kass;
            break;
        case 2:
            MainWindow::dt[i].status_ = admin;
            break;
        default:
            break;
        }
        i++;
    }
}

st FindStatus(QString name)
{
    for (int i = 0; i < MainWindow::dt.size(); i++)
    {
        if (MainWindow::dt[i].name_ == name)
            return MainWindow::dt[i].status_;
    }
    return unknow;
}

bool FindUser(QString name)
{
    for (int i = 0; i < MainWindow::dt.size(); i++)
    {
        if (MainWindow::dt[i].name_ == name)
            return true;
    }
    return false;
}

void InsertUser(QString n, QString p, st s)
{
    MainWindow::dt.resize(MainWindow::dt.size() + 1);
    MainWindow::dt[MainWindow::dt.size()-1].name_ = n;
    MainWindow::dt[MainWindow::dt.size()-1].passw_ = p;
    MainWindow::dt[MainWindow::dt.size()-1].status_ = s;
}

void SaveToText(QTextStream& ost)
{
   for (int i = 0; i < MainWindow::dt.size(); i++)
   {
       if (i != 0)
           ost << "\n";
       ost << MainWindow::dt[i].name_ << " " << MainWindow::dt[i].passw_ << " ";
       switch(MainWindow::dt[i].status_)
       {
       case pass:
           ost << 0;
           break;
       case kass:
           ost << 1;
           break;
       case admin:
           ost << 2;
           break;
       default:
           break;
       }
   }
}

void DeleteUser(int index)
{
    MainWindow::dt.erase(MainWindow::dt.begin() + index);
    SaveData();
}

QString GetStatus(st status)
{
    switch(status)
    {
    case pass:
        return "Пассажир";
        break;
    case kass:
         return "Кассир";
        break;
    case admin:
        return "Администратор";
        break;
    default:
        return "Неизвество";
        break;
    }
}
