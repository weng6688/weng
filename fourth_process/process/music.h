#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>
#include <QProcess>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QStringList>

namespace Ui {
class Music;
}

class Music : public QDialog
{
    Q_OBJECT

public:
    explicit Music(QWidget *parent = nullptr);
    ~Music();

private slots:

    void on_pushButton_up_clicked();

    void on_pushButton_start_stop_clicked();

    void on_pushButton_next_clicked();

    void read_something();

    void on_horizontalSlider_valueChanged(int value);

    void get_sec_time();

    void get_pos_time();

    void display_lrc();

    void on_pushButton_exit_clicked();

    void on_pushButton_minu_clicked();

    void on_pushButton_add_clicked();

    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::Music *ui;
    QProcess *play;
    QTimer *t;
    QString mv;
    QString cmd;
    QString name;
    QFileInfo fileInfo, fileInfo1;
    QFileInfoList list, list1;
    QStringList list_msg;

    int vol;
    double cur_time;
    double next_time;

    bool swit;
    bool swit1;
    int n;
    int number;
    int count;
    int now;
    int one,two,three,four,five;
};

#endif // MUSIC_H
