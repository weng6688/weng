/********************************************************************************
** Form generated from reading UI file 'music.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSIC_H
#define UI_MUSIC_H

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

class Ui_Music
{
public:
    QPushButton *pushButton_exit;
    QPushButton *pushButton_up;
    QPushButton *pushButton_start_stop;
    QPushButton *pushButton_next;
    QSlider *horizontalSlider;
    QPushButton *pushButton_minu;
    QPushButton *pushButton_add;
    QProgressBar *progressBar;
    QLabel *label_2;
    QLabel *label_1;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QListWidget *listWidget;

    void setupUi(QDialog *Music)
    {
        if (Music->objectName().isEmpty())
            Music->setObjectName(QStringLiteral("Music"));
        Music->resize(800, 480);
        pushButton_exit = new QPushButton(Music);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(720, 10, 71, 41));
        pushButton_up = new QPushButton(Music);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));
        pushButton_up->setGeometry(QRect(130, 420, 99, 51));
        pushButton_start_stop = new QPushButton(Music);
        pushButton_start_stop->setObjectName(QStringLiteral("pushButton_start_stop"));
        pushButton_start_stop->setGeometry(QRect(260, 420, 99, 51));
        pushButton_next = new QPushButton(Music);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));
        pushButton_next->setGeometry(QRect(390, 420, 99, 51));
        horizontalSlider = new QSlider(Music);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(630, 430, 160, 40));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setPageStep(2);
        horizontalSlider->setValue(2);
        horizontalSlider->setSliderPosition(2);
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_minu = new QPushButton(Music);
        pushButton_minu->setObjectName(QStringLiteral("pushButton_minu"));
        pushButton_minu->setGeometry(QRect(30, 420, 81, 51));
        pushButton_add = new QPushButton(Music);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(510, 420, 81, 51));
        progressBar = new QProgressBar(Music);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 390, 561, 23));
        progressBar->setValue(0);
        label_2 = new QLabel(Music);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 110, 550, 50));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_1 = new QLabel(Music);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(50, 50, 550, 50));
        label_1->setFont(font);
        label_4 = new QLabel(Music);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 230, 550, 50));
        label_4->setFont(font);
        label_3 = new QLabel(Music);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 160, 550, 60));
        QFont font1;
        font1.setPointSize(18);
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 85, 127);"));
        label_5 = new QLabel(Music);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 290, 550, 50));
        label_5->setFont(font);
        listWidget = new QListWidget(Music);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(655, 60, 141, 291));

        retranslateUi(Music);

        QMetaObject::connectSlotsByName(Music);
    } // setupUi

    void retranslateUi(QDialog *Music)
    {
        Music->setWindowTitle(QApplication::translate("Music", "Dialog", 0));
        pushButton_exit->setText(QApplication::translate("Music", "\351\200\200\345\207\272", 0));
        pushButton_up->setText(QApplication::translate("Music", "\344\270\212\344\270\200\351\246\226", 0));
        pushButton_start_stop->setText(QApplication::translate("Music", "\346\222\255\346\224\276/\346\232\202\345\201\234", 0));
        pushButton_next->setText(QApplication::translate("Music", "\344\270\213\344\270\200\351\246\226", 0));
        pushButton_minu->setText(QApplication::translate("Music", "\345\277\253\351\200\200", 0));
        pushButton_add->setText(QApplication::translate("Music", "\345\277\253\350\277\233", 0));
        label_2->setText(QString());
        label_1->setText(QString());
        label_4->setText(QString());
        label_3->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Music: public Ui_Music {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSIC_H
