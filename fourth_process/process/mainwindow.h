#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QProcess>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class Video;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_weather_clicked();

    void on_pushButton_video_clicked();

    void on_pushButton_music_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
