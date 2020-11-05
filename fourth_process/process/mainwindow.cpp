#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weather.h"
#include "video.h"
#include "music.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("车载系统");

    connect(ui->pushButton_exit,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_weather_clicked()
{
    Weather weather;
    weather.exec();
}

void MainWindow::on_pushButton_video_clicked()
{
    Video video;
    video.exec();
}

void MainWindow::on_pushButton_music_clicked()
{
    Music music;
    music.exec();
}
