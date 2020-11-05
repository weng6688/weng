#ifndef WEATHER_H
#define WEATHER_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class Weather;
}

class Weather : public QDialog
{
    Q_OBJECT

public:
    explicit Weather(QWidget *parent = nullptr);
    ~Weather();

private slots:
    void get_city_name();

    void get_weather();

    void on_pushButton_clicked();

    QString swit_pic(QString pic);

private:
    Ui::Weather *ui;
    QTcpSocket *http;
    QTcpSocket *http1;
    QString city_ip;
};

#endif // WEATHER_H
