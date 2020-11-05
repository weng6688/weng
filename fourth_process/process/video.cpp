#include "video.h"
#include "ui_video.h"

#include<QDebug>
#include <QFileDialog>

Video::Video(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Video)
{
    ui->setupUi(this);

    this->setWindowTitle("视频");
    play = new QProcess(this);
    t = new QTimer(this);
    t->start(1000);
    begin=15;
    speed=1;
    swit=true;
    name = "/IOT/tmp/fourth_process/video/Faded3.avi";

    QDir dir("/IOT/tmp/fourth_process/video/");
    QStringList filters("*.avi");
    QStringList filters1("*.mp4");
    QStringList file_list=dir.entryList(filters,QDir::Files|QDir::Readable, QDir::Name);
    QStringList file_list1=dir.entryList(filters1,QDir::Files|QDir::Readable, QDir::Name);
    ui->listWidget->addItems(file_list);
    ui->listWidget->addItems(file_list1);

    QString cmd = QString("%1x").arg(speed);
    ui->pushButton_speed->setText(cmd);

    //关联信号
    connect(ui->pushButton_exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(play,SIGNAL(readyRead()),this,SLOT(read_all_data()));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
    connect(ui->progressBar,SIGNAL(valueChanged(int)),ui->horizontalSlider_2,SLOT(setValue(int)));
    connect(t,SIGNAL(timeout()),this,SLOT(get_time()));
}

Video::~Video()
{
    delete ui;
}

//开始
void Video::on_pushButton_start_clicked()
{
    QString mv;
    mv = QString("mplayer -slave -quiet -zoom -x 600 -y 380 %1").arg(name);
    qDebug()<<mv;
    play->start(mv);
    QString cmd = QString("volume %1 1\n").arg(begin);//控制音量
    play->write(cmd.toUtf8());
    ui->horizontalSlider->setValue(begin);
}

//快退
void Video::on_pushButton_down_clicked()
{
    QString cmd = "seek -5 0\n";
    play->write(cmd.toUtf8());
    cmd = "get_percent_pos\n";
    play->write(cmd.toUtf8());
}

//暂停
void Video::on_pushButton_pause_clicked()
{
    QString cmd = "pause\n";
    play->write(cmd.toUtf8());
    if(swit)
    {
        t->stop();
        swit=false;
    }
    else
    {
        t->start();
        swit=true;
    }
}

//快进
void Video::on_pushButton_up_clicked()
{
    QString cmd = "seek +5 0\n";
    play->write(cmd.toUtf8());
    cmd = "get_percent_pos\n";
    play->write(cmd.toUtf8());
}

//结束
void Video::on_pushButton_end_clicked()
{
    play->kill();

    if(play->waitForFinished())
        qDebug()<<"wait ok";
    else
        qDebug()<<"wait fail";
}

//滑动条
void Video::on_horizontalSlider_2_valueChanged(int value)
{
    QString cmd = QString("seek %1% 1\n").arg(value);  //快进
    play->write(cmd.toUtf8());
}

//进度条
void Video::on_progressBar_valueChanged(int value)
{
    cur_time = value;
    ui->horizontalSlider_2->setValue(cur_time);
}

//音量
void Video::on_horizontalSlider_valueChanged(int value)
{
    begin = value;
    QString cmd = QString("volume %1 1\n").arg(begin);//控制音量
    play->write(cmd.toUtf8());
}

//读取返回的数据
void Video::read_all_data()
{
    QString msg = play->readAll();
    QString str = msg;
    str = str.remove(0,str.indexOf("="));
    str = str.remove("=");
    cur_time = str.toInt();
    ui->progressBar->setValue(cur_time);
    ui->horizontalSlider_2->setValue(cur_time);
}

//获取时间
void Video::get_time()
{
    QString cmd = "get_percent_pos\n";
    play->write(cmd.toUtf8());
}

void Video::on_pushButton_speed_clicked()
{
    QString cmd;
    if(speed==1)
    {
        speed=1.25;
        cmd = QString("%1x").arg(speed);
        ui->pushButton_speed->setText(cmd);
        QString cmd = QString("speed_set %1\n").arg(speed);//控制速度
        play->write(cmd.toUtf8());
    }
    else if(speed==1.25)
    {
        speed=1.5;
        cmd = QString("%1x").arg(speed);
        ui->pushButton_speed->setText(cmd);
        QString cmd = QString("speed_set %1\n").arg(speed);//控制速度
        play->write(cmd.toUtf8());
    }
    else if(speed==1.5)
    {
        speed=1.75;
        cmd = QString("%1x").arg(speed);
        ui->pushButton_speed->setText(cmd);
        QString cmd = QString("speed_set %1\n").arg(speed);//控制速度
        play->write(cmd.toUtf8());
    }
    else if(speed==1.75)
    {
        speed=2;
        cmd = QString("%1x").arg(speed);
        ui->pushButton_speed->setText(cmd);
        QString cmd = QString("speed_set %1\n").arg(speed);//控制速度
        play->write(cmd.toUtf8());
    }
    else if(speed==2)
    {
        speed=1;
        cmd = QString("%1x").arg(speed);
        ui->pushButton_speed->setText(cmd);
        QString cmd = QString("speed_set %1\n").arg(speed);//控制速度
        play->write(cmd.toUtf8());
    }
}

void Video::on_listWidget_clicked(const QModelIndex &index)
{
    QString msg = index.data().toString();
    name = msg;
    play->kill();
    if(play->waitForFinished())
    {
        QString mv = QString("mplayer -slave -quiet -zoom -x 600 -y 380 /IOT/tmp/fourth_process/video/%1").arg(name);
        qDebug()<<mv;
        play->start(mv);
        QString cmd = QString("volume %1 1\n").arg(begin);//控制音量
        play->write(cmd.toUtf8());
    }

}
