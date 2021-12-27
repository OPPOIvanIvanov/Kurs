#ifndef US_FLIGHTS_H
#define US_FLIGHTS_H

#include <QWidget>

namespace Ui {
class us_flights;
}

class us_flights : public QWidget
{
    Q_OBJECT

public:
    explicit us_flights(QWidget *parent = nullptr);
    ~us_flights();
    ///\brief Заполнить таблицу рейсов
    void SetFlightsTable();
signals:
    void BackButton();

private slots:
    void OnBackButtonClicked();

private:
    Ui::us_flights *ui;
};
#endif // US_FLIGHTS_H
