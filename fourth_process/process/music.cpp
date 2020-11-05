#include "music.h"
#include "ui_music.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonValue>
#include <QFileDialog>
#include <QByteArray>
#include <QTextStream>

double old_next_time[1000];

Music::Music(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Music)
{
    ui->setupUi(this);

    play = new QProcess(this);
    t = new QTimer(this);
    t->start(100);

    vol=35;			//初始音量
    swit=true;		//暂停/播放控制
    swit1=true;		//开始键设置
    n=0;  			//歌词控制
    number=3;		//第3首歌
    cur_time=0;		//初始化当前时间
    old_next_time[0] = next_time=100;	//初始化下一句歌词的时间
    now=0;			//当前歌词是第一句

    cmd = QString("volume %1 1\n").arg(vol);//控制音量

    //遍历制定文件夹下的歌曲和歌词
    QDir dir("/IOT/tmp/fourth_process/mp3/");
    QDir dir1("/IOT/tmp/fourth_process/lrc/");
    QStringList filters("*.mp3");
    QStringList filters1("*.lrc");
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    dir.setNameFilters(filters);
    dir1.setFilter(QDir::Files | QDir::NoSymLinks);
    dir1.setNameFilters(filters1);
    count = dir.count();
    list = dir.entryInfoList();
    list1 = dir1.entryInfoList();
    fileInfo = list.at(number);
    fileInfo1 = list1.at(number);
    name = fileInfo.fileName();
    name = name.remove(".mp3");

    //窗口显示列表
    QStringList file_list=dir.entryList(filters,QDir::Files|QDir::Readable, QDir::Name);
    ui->listWidget->addItems(file_list);

    mv = QString("mplayer -slave -quiet /IOT/tmp/fourth_process/mp3/%1.mp3").arg(name);
    qDebug()<<mv;
    play->start(mv);
    play->write(cmd.toUtf8());
    QString cmd = QString("volume %1 1\n").arg(vol);//控制音量
    play->write(cmd.toUtf8());//设置mplayer音量
    ui->horizontalSlider->setValue(vol);//音量条设置

    connect(t,SIGNAL(timeout()),this,SLOT(get_sec_time()));//定时获取当前的进度的时间
    connect(t,SIGNAL(timeout()),this,SLOT(get_pos_time()));//定时获取当前的进度
    connect(t,SIGNAL(timeout()),this,SLOT(display_lrc()));//定时获取歌词
    connect(ui->pushButton_exit,SIGNAL(clicked()),this,SLOT(close()));//退出键
    connect(play,SIGNAL(readyRead()),this,SLOT(read_something()));//读取信息
}

Music::~Music()
{
    delete ui;
}

void Music::read_something()
{
    QString name1 = QString("/IOT/tmp/fourth_process/pic/%1.jpg").arg(name);
    QPixmap pixmap = QPixmap(name1).scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

    QString msg = play->readAll();

    if(msg.mid(0,18)=="ANS_TIME_POSITION=")
    {
        QStringList list_time = msg.split("\n");//将接受的内容裁剪放进链表中

        for(int i=0;i<list_time.size();i++)
        {
            msg = list_time.at(0);
            if(msg.mid(0,18)=="ANS_TIME_POSITION=")
            {
                msg = msg.mid(18,20);
                QString cur_t = msg;
                cur_time = cur_t.toDouble()*1000;
            }
            else if(msg.mid(0,21)=="ANS_PERCENT_POSITION=")
            {
                msg = msg.mid(21,22);
//                qDebug()<<"pos_time:"<<msg.toInt();
                ui->progressBar->setValue(msg.toInt());

                if(msg.toInt()==100)
                {
                    if(number==count-1)
                        number=0;
                    else
                        number++;

                    fileInfo = list.at(number);
                    name = fileInfo.fileName();
                    name = name.remove(".mp3");

                    play->kill();
                    if(play->waitForFinished())
                    {
                        mv = QString("mplayer -slave -quiet /IOT/tmp/fourth_process/mp3/%1.mp3").arg(name);
                        qDebug()<<mv;
                        play->start(mv);
                        play->write(cmd.toUtf8());
                        QString cmd = QString("volume %1 1\n").arg(vol);//控制音量
                        play->write(cmd.toUtf8());
                        next_time=100;
                        now=0;

                        ui->label_1->clear();
                        ui->label_2->clear();
                    }
                }
            }
        }
    }
    else
    {
        QStringList list_time = msg.split("\n");
        for(int i=0;i<list_time.size();i++)
        {
            msg = list_time.at(0);
            if(msg.mid(0,18)=="ANS_TIME_POSITION=")
            {
                msg = msg.mid(18,20);
                QString cur_t = msg;
                cur_time = cur_t.toDouble()*1000;
            }
            else if(msg.mid(0,21)=="ANS_PERCENT_POSITION=")
            {
                msg = msg.mid(21,22);
//                qDebug()<<"pos_time:"<<msg.toInt();
                ui->progressBar->setValue(msg.toInt());

                if(msg.toInt()>=97)
                {
                    if(number==count-1)
                        number=0;
                    else
                        number++;

                    fileInfo = list.at(number);
                    name = fileInfo.fileName();
                    name = name.remove(".mp3");

                    play->kill();
                    if(play->waitForFinished())
                    {
                        mv = QString("mplayer -slave -quiet /IOT/tmp/fourth_process/mp3/%1.mp3").arg(name);
                        qDebug()<<mv;
                        play->start(mv);
                        play->write(cmd.toUtf8());
                        QString cmd = QString("volume %1 1\n").arg(vol);//控制音量
                        play->write(cmd.toUtf8());
                        next_time=100;
                        now=0;

                        ui->label_1->clear();
                        ui->label_2->clear();
                    }
                }
            }
        }
    }
}

void Music::on_pushButton_up_clicked()
{
    if(number==0)
        number=count-1;
    else
        number--;

    fileInfo = list.at(number);
    name = fileInfo.fileName();
    name = name.remove(".mp3");

    play->kill();
    if(play->waitForFinished())
    {
        mv = QString("mplayer -slave -quiet /IOT/tmp/fourth_process/mp3/%1.mp3").arg(name);
        qDebug()<<mv;
        play->start(mv);
        play->write(cmd.toUtf8());
        QString cmd = QString("volume %1 1\n").arg(vol);//控制音量
        play->write(cmd.toUtf8());
        next_time=100;
        now=0;

        ui->label_1->clear();
        ui->label_2->clear();
    }
}

void Music::on_pushButton_start_stop_clicked()
{
    if(swit==true)
    {
        QString cmd = "pause\n";
        play->write(cmd.toUtf8());

        t->stop();
        swit=false;
    }
    else if(swit==false)
    {
        t->start();
        swit=true;
    }
}

void Music::on_pushButton_next_clicked()
{
    if(number==count-1)
        number=0;
    else
        number++;

    fileInfo = list.at(number);
    name = fileInfo.fileName();
    name = name.remove(".mp3");

    play->kill();
    if(play->waitForFinished())
    {
        mv = QString("mplayer -slave -quiet /IOT/tmp/fourth_process/mp3/%1.mp3").arg(name);
        qDebug()<<mv;
        play->start(mv);
        play->write(cmd.toUtf8());
        QString cmd = QString("volume %1 1\n").arg(vol);//控制音量
        play->write(cmd.toUtf8());
        next_time=100;
        now=0;

        ui->label_1->clear();
        ui->label_2->clear();
    }
}

//音量
void Music::on_horizontalSlider_valueChanged(int value)
{
    vol=value;
    QString cmd = QString("volume %1 1\n").arg(value);//控制音量
    play->write(cmd.toUtf8());
}

//歌词
void Music::display_lrc()
{
    QFile file;
    QString file_name = QString("/IOT/tmp/fourth_process/lrc/%1.lrc").arg(name);
    file.setFileName(file_name);

    if(file.open(QIODevice::ReadOnly))
    {
        QString str = file.readAll();
        list_msg = str.split("\n");

        if(cur_time+200 > next_time)
        {
            QString msg = list_msg.at(now);
            msg = msg.remove(0,msg.indexOf("]"));
            msg = msg.remove("]");

            if(now==0)
            {
                one=-1;
                two=-1;
                three=0;
                four=1;
                five=2;
            }
            else if(now==1)
            {
                one=-1;
                two=0;
                three=1;
                four=2;
                five=3;
            }
            else if(now==2)
            {
                one=0;
                two=1;
                three=2;
                four=3;
                five=4;
            }
            else if(now>=3 && now<list_msg.size()-3)
            {
                one+=1;
                two+=1;
                three+=1;
                four+=1;
                five+=1;
            }
            else
            {
                one=list_msg.size()-3;
                two=list_msg.size()-2;
                three=list_msg.size()-1;
            }

            if(now<list_msg.size()-1)
                now++;
            else if(now == list_msg.size()-1)
            {
                ui->label_4->clear();
                ui->label_5->clear();
            }
        }

        if(one>=0)
        {
            QString one_lrc = list_msg.at(one);
            one_lrc = one_lrc.remove(0,one_lrc.indexOf("]"));
            one_lrc = one_lrc.remove("]");
            ui->label_1->setText(one_lrc);
        }
        if(two>=0)
        {
            QString two_lrc = list_msg.at(two);
            two_lrc = two_lrc.remove(0,two_lrc.indexOf("]"));
            two_lrc = two_lrc.remove("]");
            ui->label_2->setText(two_lrc);
        }
        QString three_lrc = list_msg.at(three);
        three_lrc = three_lrc.remove(0,three_lrc.indexOf("]"));
        three_lrc = three_lrc.remove("]");
        QString four_lrc = list_msg.at(four);
        four_lrc = four_lrc.remove(0,four_lrc.indexOf("]"));
        four_lrc = four_lrc.remove("]");
        QString five_lrc = list_msg.at(five);
        five_lrc = five_lrc.remove(0,five_lrc.indexOf("]"));
        five_lrc = five_lrc.remove("]");
        ui->label_3->setText(three_lrc);
        ui->label_4->setText(four_lrc);
        ui->label_5->setText(five_lrc);


        QString msg = list_msg.at(now);
        double min = msg.mid(1,2).toDouble();
        double sec = msg.mid(4,5).toDouble();
        double t = (min*60+sec)*1000;
        if(t>next_time)
        {
            old_next_time[n] = next_time;
            next_time = t;
            n++;
        }
    }
}

void Music::get_pos_time()
{
    play->write("get_percent_pos\n");
}

void Music::get_sec_time()
{
    play->write("get_time_pos\n");
}

void Music::on_pushButton_exit_clicked()
{
    play->write("kill\n");
}

void Music::on_pushButton_minu_clicked()
{
    QString cmd = QString("seek -2 0\n");  //快退
    play->write(cmd.toUtf8());
    for(int i=0; i<n; i++)
    {
        if(cur_time > old_next_time[i] && cur_time < old_next_time[i+1])
        {
            now -= (n-i-1);
            one-=(n-i-1);
            two-=(n-i-1);
            three-=(n-i-1);
            four-=(n-i-1);
            five-=(n-i-1);
            next_time = old_next_time[i+1];
        }
    }
}

void Music::on_pushButton_add_clicked()
{
    QString cmd = QString("seek +2 0\n");  //快进
    play->write(cmd.toUtf8());
}


void Music::on_listWidget_clicked(const QModelIndex &index)
{
    QString msg = index.data().toString();
    name = msg;
    name = name.remove(".mp3");
    mv = QString("loadfile /IOT/tmp/fourth_process/mp3/%1.mp3 0\n").arg(name);
    qDebug()<<mv;
    play->write(mv.toUtf8());
    next_time=100;
    now=0;
}
