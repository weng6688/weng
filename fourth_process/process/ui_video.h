/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Video
{
public:
    QSlider *horizontalSlider;
    QLabel *label;
    QProgressBar *progressBar;
    QSlider *horizontalSlider_2;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_start;
    QPushButton *pushButton_down;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_up;
    QPushButton *pushButton_end;
    QPushButton *pushButton_speed;
    QLabel *label_2;
    QListWidget *listWidget;

    void setupUi(QDialog *Video)
    {
        if (Video->objectName().isEmpty())
            Video->setObjectName(QStringLiteral("Video"));
        Video->resize(800, 480);
        Video->setStyleSheet(QStringLiteral("border-image: url(:/pic/xingkong.jpg);"));
        horizontalSlider = new QSlider(Video);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(630, 430, 160, 45));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(Video);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(580, 440, 41, 21));
        progressBar = new QProgressBar(Video);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 385, 631, 15));
        QFont font;
        font.setPointSize(7);
        progressBar->setFont(font);
        progressBar->setValue(0);
        horizontalSlider_2 = new QSlider(Video);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 390, 600, 40));
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setPageStep(1);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        pushButton_exit = new QPushButton(Video);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(680, 5, 100, 40));
        pushButton_start = new QPushButton(Video);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(40, 430, 90, 45));
        pushButton_start->setStyleSheet(QStringLiteral("border-image: url(:/pic/start.jpg);"));
        pushButton_down = new QPushButton(Video);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));
        pushButton_down->setGeometry(QRect(160, 430, 70, 45));
        pushButton_down->setStyleSheet(QStringLiteral("border-image: url(:/pic/down.ai);"));
        pushButton_pause = new QPushButton(Video);
        pushButton_pause->setObjectName(QStringLiteral("pushButton_pause"));
        pushButton_pause->setGeometry(QRect(260, 430, 70, 45));
        pushButton_pause->setStyleSheet(QStringLiteral("border-image: url(:/pic/stop.jpg);"));
        pushButton_up = new QPushButton(Video);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));
        pushButton_up->setGeometry(QRect(360, 430, 70, 45));
        pushButton_up->setStyleSheet(QStringLiteral("border-image: url(:/pic/up.ai);"));
        pushButton_end = new QPushButton(Video);
        pushButton_end->setObjectName(QStringLiteral("pushButton_end"));
        pushButton_end->setGeometry(QRect(460, 430, 90, 45));
        pushButton_end->setStyleSheet(QStringLiteral("border-image: url(:/pic/end.jpg);"));
        pushButton_speed = new QPushButton(Video);
        pushButton_speed->setObjectName(QStringLiteral("pushButton_speed"));
        pushButton_speed->setGeometry(QRect(700, 390, 71, 41));
        label_2 = new QLabel(Video);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(660, 390, 51, 41));
        listWidget = new QListWidget(Video);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(650, 50, 141, 311));

        retranslateUi(Video);

        QMetaObject::connectSlotsByName(Video);
    } // setupUi

    void retranslateUi(QDialog *Video)
    {
        Video->setWindowTitle(QApplication::translate("Video", "Dialog", 0));
        label->setText(QApplication::translate("Video", "\351\237\263\351\207\217", 0));
        pushButton_exit->setText(QApplication::translate("Video", "\351\200\200\345\207\272", 0));
        pushButton_start->setText(QString());
        pushButton_down->setText(QString());
        pushButton_pause->setText(QString());
        pushButton_up->setText(QString());
        pushButton_end->setText(QString());
        pushButton_speed->setText(QString());
        label_2->setText(QApplication::translate("Video", "\345\200\215\351\200\237", 0));
    } // retranslateUi

};

namespace Ui {
    class Video: public Ui_Video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
