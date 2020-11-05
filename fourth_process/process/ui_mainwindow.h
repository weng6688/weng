/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_weather;
    QPushButton *pushButton_video;
    QPushButton *pushButton_music;
    QPushButton *pushButton_exit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QStringLiteral("QMainWindow:{ url(:/pic/p.jpg)};"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_weather = new QPushButton(centralwidget);
        pushButton_weather->setObjectName(QStringLiteral("pushButton_weather"));
        pushButton_weather->setGeometry(QRect(10, 110, 250, 200));
        pushButton_weather->setStyleSheet(QStringLiteral("border-image: url(:/pic/weather.jpg);"));
        pushButton_video = new QPushButton(centralwidget);
        pushButton_video->setObjectName(QStringLiteral("pushButton_video"));
        pushButton_video->setGeometry(QRect(270, 110, 250, 200));
        pushButton_video->setStyleSheet(QStringLiteral("border-image: url(:/pic/video.jpg);"));
        pushButton_music = new QPushButton(centralwidget);
        pushButton_music->setObjectName(QStringLiteral("pushButton_music"));
        pushButton_music->setGeometry(QRect(530, 110, 250, 200));
        pushButton_music->setStyleSheet(QStringLiteral("border-image: url(:/pic/music.jpg);"));
        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(340, 400, 101, 61));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_weather->setText(QString());
        pushButton_video->setText(QString());
        pushButton_music->setText(QString());
        pushButton_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
