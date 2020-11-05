#include "weather.h"
#include "ui_weather.h"

#include <QHostAddress>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QPixmap>
#include <QPainter>
#include <QPalette>

static QJsonParseError err;

Weather::Weather(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);
    this->setWindowTitle("天气");

    QPainter painter(this);
    painter.fillRect(this->rect(), QColor(0, 0, 255, 80));  //QColor最后一个参数80代表背景的透明度

    http = new QTcpSocket(this);
    http->connectToHost(QHostAddress("14.18.240.18"),80);
    http1 = new QTcpSocket(this);
    http1->connectToHost(QHostAddress("103.205.5.134"),80);

    QString msg = "GET /cityjson?ie=utf-8 HTTP/1.1\r\nHost:pv.sohu.com\r\n\r\n";
    http->write(msg.toUtf8());

    connect(http,SIGNAL(readyRead()),this,SLOT(get_city_name()));
    connect(http1,SIGNAL(readyRead()),this,SLOT(get_weather()));
    connect(ui->pushButton_exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(get_city_name()));
}

Weather::~Weather()
{
    delete ui;
}

void Weather::get_city_name()
{
    QByteArray arr = http->readAll();
    QString msg = arr;
    msg = msg.remove(0,msg.indexOf("{"));
    msg = msg.remove(";");

    QJsonDocument my_json = QJsonDocument::fromJson(msg.toUtf8(),&err);
    if(err.error == QJsonParseError::NoError)
        qDebug()<<"成功";
    else
    {
        ui->label_msg->clear();
        ui->label_msg->setText("申请数据失败，请更新重试！！！");
        qDebug()<<"失败";
    }

    QJsonObject obj = my_json.object();

    QJsonValue ip = obj.take("cip");
    city_ip = ip.toString();

    QString http_msg = QString("GET /?app=weather.realtime&weaid=%1&ag=today,futureDay,lifeIndexr&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json HTTP/1.1\r\nHost:api.k780.com\r\n\r\n").arg(city_ip);
    http1->write(http_msg.toUtf8());
}

QString Weather::swit_pic(QString pic)
{
    if(pic=="晴")
        return "sun";
    else if(pic=="多云"||pic=="晴转多云")//
        return "cloudy";
    else if(pic=="阴")
        return "gray";
    else if(pic=="雾")//
        return "fog";
    else if(pic=="小雨")//
        return "small_rain";
    else if(pic=="中雨")//
        return "moderate_rain";
    else if(pic=="阵雨")//
        return "shower";
    else if(pic=="雷阵雨")//
        return "thundershower";
    else if(pic=="大雨")//
        return "big_rain";
    else if(pic=="暴雨")//
        return "rainstorm";
    else if(pic=="大暴雨")//
        return "big_rainstorm";
    else if(pic=="小雪")//
        return "small_snow";
    else if(pic=="中雪")//
        return "moderate_snow";
    else if(pic=="阵雪")//
        return "snow_shower";
    else if(pic=="大雪")//
        return "big_snow";
    else if(pic=="暴雪"||pic=="大暴雪")//
        return "snowstorm";
}

void Weather::get_weather()
{
    QByteArray msg_json = http1->readAll();
    QString msg = msg_json;
    msg = msg.remove(0,msg.indexOf("\"result\":{"));
    msg = msg.remove(0,msg.indexOf("{"));
    msg = msg.remove("}\r\n0\r\n\r\n");
//    qDebug()<<msg;

    QJsonDocument my_json = QJsonDocument::fromJson(msg.toUtf8(),&err);
    if(err.error == QJsonParseError::NoError)
    {
        qDebug()<<"成功";
    }
    else
    {
        ui->label_msg->clear();
        ui->label_msg->setText("申请数据失败，请更新重试！！！");
        qDebug()<<"失败";
    }

    QJsonObject obj = my_json.object();
    QJsonValue city_value = obj.take("area_2");
    QString city = city_value.toString();

    QJsonObject obj1 = obj.take("realTime").toObject();
    QJsonObject obj2 = obj.take("today").toObject();


    QString wtNm = obj1.take("wtNm").toString();
    QString wtTemp = obj1.take("wtTemp").toString();
    QString wtWindNm = obj1.take("wtWindNm").toString();

    QString str3 = QString("%1  %2  %3℃  %4").arg(city).arg(wtNm).arg(wtTemp).arg(wtWindNm);
    ui->label_msg->setText(str3);

    QString week = obj1.take("week").toString();
    QString wtNm1 = obj2.take("wtNm1").toString();
    QString wtTemp2 = obj2.take("wtTemp2").toString();
    QString wtTemp1 = obj2.take("wtTemp1").toString();
    QString wtWindNm1 = obj2.take("wtWindNm1").toString();
    QString wtWinpNm1 = obj2.take("wtWinpNm1").toString();

    QString str4 = QString("今天(%1)\n")
                       .arg(week);
    QString str5 = QString("%1\n%2℃~%3℃\n%4\n%5\n")
                       .arg(wtNm1).arg(wtTemp2).arg(wtTemp1).arg(wtWindNm1).arg(wtWinpNm1);

    ui->label_now_1->setText(str4);
    ui->label_now_3->setText(str5);

    QString name;
    name = QString("../weather/%1.jpg").arg(swit_pic(wtNm1));
    QPixmap pix(name);
    pix = pix.scaled(ui->label_now_2->size());
    ui->label_now_2->setPixmap(pix);
    QString gif = QString("../gif/%1.gif").arg(swit_pic(wtNm1));
    QPixmap pixmap = QPixmap(gif).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    //求出数组的大小
    QJsonArray arry =  obj.take("futureDay").toArray();
    int arry_size =  arry.size();

    //遍历数组
    for(int i =0;i<arry_size;i++)
    {
        QString str6;
        QJsonValue value =  arry.at(i);
        QString dateYmd = value.toObject().take("dateYmd").toString();
        QString week = value.toObject().take("week").toString();
        QString wtNm1 = value.toObject().take("wtNm1").toString();
        QString wtTemp2 = value.toObject().take("wtTemp2").toString();
        QString wtTemp1 = value.toObject().take("wtTemp1").toString();
        QString wtWindNm1 = value.toObject().take("wtWindNm1").toString();
        QString wtWinpNm1 = value.toObject().take("wtWinpNm1").toString();

        if(i==0)
            str6 = QString("明天(%1)\n%2\n").arg(week).arg(dateYmd);
        else if(i==1)
            str6 = QString("后天(%1)\n%2\n").arg(week).arg(dateYmd);
        else
            str6 = QString("%1\n%2\n").arg(week).arg(dateYmd);

        QString str7 = QString("%1\n%2℃~%3℃\n%4\n%5\n")
                           .arg(wtNm1).arg(wtTemp2).arg(wtTemp1).arg(wtWindNm1).arg(wtWinpNm1);

        if(i==0)
        {
            ui->label_2_1->setText(str6);
            ui->label_2_3->setText(str7);
            name = QString("../weather/%1.jpg").arg(swit_pic(wtNm1));
            QPixmap pix(name);
            pix = pix.scaled(ui->label_2_2->size());
            ui->label_2_2->setPixmap(pix);
        }
        else if(i==1)
        {
            ui->label_3_1->setText(str6);
            ui->label_3_3->setText(str7);
            name = QString("../weather/%1.jpg").arg(swit_pic(wtNm1));
            QPixmap pix(name);
            pix = pix.scaled(ui->label_3_2->size());
            ui->label_3_2->setPixmap(pix);
        }
        else if(i==2)
        {
            ui->label_4_1->setText(str6);
            ui->label_4_3->setText(str7);
            name = QString("../weather/%1.jpg").arg(swit_pic(wtNm1));
            QPixmap pix(name);
            pix = pix.scaled(ui->label_4_2->size());
            ui->label_4_2->setPixmap(pix);
        }
        else if(i==3)
        {
            ui->label_5_1->setText(str6);
            ui->label_5_3->setText(str7);
            name = QString("../weather/%1.jpg").arg(swit_pic(wtNm1));
            QPixmap pix(name);
            pix = pix.scaled(ui->label_5_2->size());
            ui->label_5_2->setPixmap(pix);
        }
        else if(i==4)
        {
            ui->label_6_1->setText(str6);
            ui->label_6_3->setText(str7);
            name = QString("../weather/%1.jpg").arg(swit_pic(wtNm1));
            QPixmap pix(name);
            pix = pix.scaled(ui->label_6_2->size());
            ui->label_6_2->setPixmap(pix);
        }
    }
}

void Weather::on_pushButton_clicked()
{
    QString msg = "GET /cityjson?ie=utf-8 HTTP/1.1\r\nHost:pv.sohu.com\r\n\r\n";
    http->write(msg.toUtf8());
}


