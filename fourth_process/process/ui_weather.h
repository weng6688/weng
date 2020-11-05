/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Weather
{
public:
    QPushButton *pushButton_exit;
    QPushButton *pushButton;
    QLabel *label_msg;
    QLabel *label_now_3;
    QLabel *label_2_3;
    QLabel *label_3_3;
    QLabel *label_4_3;
    QLabel *label_5_3;
    QLabel *label_6_3;
    QLabel *label_now_2;
    QLabel *label_2_2;
    QLabel *label_3_2;
    QLabel *label_4_2;
    QLabel *label_5_2;
    QLabel *label_6_2;
    QLabel *label_6_1;
    QLabel *label_now_1;
    QLabel *label_2_1;
    QLabel *label_3_1;
    QLabel *label_4_1;
    QLabel *label_5_1;

    void setupUi(QDialog *Weather)
    {
        if (Weather->objectName().isEmpty())
            Weather->setObjectName(QStringLiteral("Weather"));
        Weather->resize(800, 480);
        Weather->setStyleSheet(QStringLiteral(""));
        pushButton_exit = new QPushButton(Weather);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(720, 10, 71, 28));
        pushButton = new QPushButton(Weather);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 430, 781, 41));
        label_msg = new QLabel(Weather);
        label_msg->setObjectName(QStringLiteral("label_msg"));
        label_msg->setGeometry(QRect(20, 10, 691, 101));
        label_now_3 = new QLabel(Weather);
        label_now_3->setObjectName(QStringLiteral("label_now_3"));
        label_now_3->setGeometry(QRect(0, 289, 125, 131));
        label_2_3 = new QLabel(Weather);
        label_2_3->setObjectName(QStringLiteral("label_2_3"));
        label_2_3->setGeometry(QRect(125, 289, 125, 131));
        label_3_3 = new QLabel(Weather);
        label_3_3->setObjectName(QStringLiteral("label_3_3"));
        label_3_3->setGeometry(QRect(250, 289, 125, 131));
        label_4_3 = new QLabel(Weather);
        label_4_3->setObjectName(QStringLiteral("label_4_3"));
        label_4_3->setGeometry(QRect(375, 289, 125, 131));
        label_5_3 = new QLabel(Weather);
        label_5_3->setObjectName(QStringLiteral("label_5_3"));
        label_5_3->setGeometry(QRect(500, 289, 125, 131));
        label_6_3 = new QLabel(Weather);
        label_6_3->setObjectName(QStringLiteral("label_6_3"));
        label_6_3->setGeometry(QRect(625, 289, 125, 131));
        label_now_2 = new QLabel(Weather);
        label_now_2->setObjectName(QStringLiteral("label_now_2"));
        label_now_2->setGeometry(QRect(0, 225, 125, 61));
        label_2_2 = new QLabel(Weather);
        label_2_2->setObjectName(QStringLiteral("label_2_2"));
        label_2_2->setGeometry(QRect(125, 225, 125, 61));
        label_3_2 = new QLabel(Weather);
        label_3_2->setObjectName(QStringLiteral("label_3_2"));
        label_3_2->setGeometry(QRect(250, 225, 125, 61));
        label_4_2 = new QLabel(Weather);
        label_4_2->setObjectName(QStringLiteral("label_4_2"));
        label_4_2->setGeometry(QRect(375, 225, 125, 61));
        label_5_2 = new QLabel(Weather);
        label_5_2->setObjectName(QStringLiteral("label_5_2"));
        label_5_2->setGeometry(QRect(500, 225, 125, 61));
        label_6_2 = new QLabel(Weather);
        label_6_2->setObjectName(QStringLiteral("label_6_2"));
        label_6_2->setGeometry(QRect(625, 225, 125, 61));
        label_6_1 = new QLabel(Weather);
        label_6_1->setObjectName(QStringLiteral("label_6_1"));
        label_6_1->setGeometry(QRect(625, 125, 125, 100));
        label_now_1 = new QLabel(Weather);
        label_now_1->setObjectName(QStringLiteral("label_now_1"));
        label_now_1->setGeometry(QRect(0, 125, 125, 91));
        label_2_1 = new QLabel(Weather);
        label_2_1->setObjectName(QStringLiteral("label_2_1"));
        label_2_1->setGeometry(QRect(125, 125, 125, 100));
        label_3_1 = new QLabel(Weather);
        label_3_1->setObjectName(QStringLiteral("label_3_1"));
        label_3_1->setGeometry(QRect(250, 125, 125, 100));
        label_4_1 = new QLabel(Weather);
        label_4_1->setObjectName(QStringLiteral("label_4_1"));
        label_4_1->setGeometry(QRect(375, 125, 125, 100));
        label_5_1 = new QLabel(Weather);
        label_5_1->setObjectName(QStringLiteral("label_5_1"));
        label_5_1->setGeometry(QRect(500, 125, 125, 100));

        retranslateUi(Weather);

        QMetaObject::connectSlotsByName(Weather);
    } // setupUi

    void retranslateUi(QDialog *Weather)
    {
        Weather->setWindowTitle(QApplication::translate("Weather", "Dialog", 0));
        pushButton_exit->setText(QApplication::translate("Weather", "\351\200\200\345\207\272", 0));
        pushButton->setText(QApplication::translate("Weather", "\346\233\264\346\226\260", 0));
        label_msg->setText(QString());
        label_now_3->setText(QString());
        label_2_3->setText(QString());
        label_3_3->setText(QString());
        label_4_3->setText(QString());
        label_5_3->setText(QString());
        label_6_3->setText(QString());
        label_now_2->setText(QString());
        label_2_2->setText(QString());
        label_3_2->setText(QString());
        label_4_2->setText(QString());
        label_5_2->setText(QString());
        label_6_2->setText(QString());
        label_6_1->setText(QString());
        label_now_1->setText(QString());
        label_2_1->setText(QString());
        label_3_1->setText(QString());
        label_4_1->setText(QString());
        label_5_1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Weather: public Ui_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
