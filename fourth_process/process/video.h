#ifndef VIDEO_H
#define VIDEO_H

#include <QDialog>
#include <QProcess>
#include<QTimer>

namespace Ui {
class Video;
}

class Video : public QDialog
{
    Q_OBJECT

public:
    explicit Video(QWidget *parent = nullptr);
    ~Video();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_down_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_up_clicked();

    void on_pushButton_end_clicked();

    void on_horizontalSlider_2_valueChanged(int value);

    void on_progressBar_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void read_all_data();

    void get_time();

    void on_pushButton_speed_clicked();

    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::Video *ui;
    QProcess *play;
    QTimer *t;
    int begin;
    int num;
    int cur_time;
    bool swit;
    QString name;
    double speed;
};

#endif // VIDEO_H
