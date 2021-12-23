#include "users_db.h"

users_db::users_db()
{

}
void load_data(QTextStream &ost)
{
    int i = 0;
    while(!ost.atEnd())
    {
        MainWindow::dt.resize(i + 1);
        ost >> MainWindow::dt[i].name >> MainWindow::dt[i].passw;
        int x;
        ost >> x;
        switch(x)
        {
        case 0:
            MainWindow::dt[i].status = pass;
            break;
        case 1:
            MainWindow::dt[i].status = kass;
            break;
        case 2:
            MainWindow::dt[i].status = admin;
            break;
        default:
            break;
        }
        i++;
    }
}

st get_status(QString str, QString str2)
{
    for (int i = 0; i < MainWindow::dt.size(); i++)
    {
        if (MainWindow::dt[i].name == str && MainWindow::dt[i].passw == str2)
            return MainWindow::dt[i].status;
    }
    return unknow;
}

bool find_us(QString str)
{
    for (int i = 0; i < MainWindow::dt.size(); i++)
    {
        if (MainWindow::dt[i].name == str)
            return true;
    }
    return false;
}

void insert(QString n, QString p, st s)
{
    MainWindow::dt.resize(MainWindow::dt.size() + 1);
    MainWindow::dt[MainWindow::dt.size()-1].name = n;
    MainWindow::dt[MainWindow::dt.size()-1].passw = p;
    MainWindow::dt[MainWindow::dt.size()-1].status = s;
}

void save_text(QTextStream& ost)
{
   for (int i = 0; i < MainWindow::dt.size(); i++)
   {
       if (i != 0)
           ost << "\n";
       ost << MainWindow::dt[i].name << " " << MainWindow::dt[i].passw << " ";
       switch(MainWindow::dt[i].status)
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

void del(int index)
{
    MainWindow::dt.erase(MainWindow::dt.begin() + index);
    save();
}
