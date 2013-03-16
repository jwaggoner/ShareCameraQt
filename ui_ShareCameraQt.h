/********************************************************************************
** Form generated from reading UI file 'ShareCameraQt.ui'
**
** Created: Sat Mar 16 14:46:23 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHARECAMERAQT_H
#define UI_SHARECAMERAQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ShareCameraQt
{
public:
    QAction *actionOpenFile;
    QAction *actionExit;
    QAction *actionPrint;
    QAction *actionHelp;
    QAction *actionSave;
    QWidget *centralwidget;
    QVTKWidget *qvtkWidgetLeft;
    QVTKWidget *qvtkWidgetRight;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *ShareCameraQt)
    {
        if (ShareCameraQt->objectName().isEmpty())
            ShareCameraQt->setObjectName(QString::fromUtf8("ShareCameraQt"));
        ShareCameraQt->resize(990, 659);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        ShareCameraQt->setWindowIcon(icon);
        ShareCameraQt->setIconSize(QSize(22, 22));
        actionOpenFile = new QAction(ShareCameraQt);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionOpenFile->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFile->setIcon(icon1);
        actionExit = new QAction(ShareCameraQt);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionPrint = new QAction(ShareCameraQt);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        actionHelp = new QAction(ShareCameraQt);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionHelp->setIcon(icon);
        actionSave = new QAction(ShareCameraQt);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        centralwidget = new QWidget(ShareCameraQt);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        qvtkWidgetLeft = new QVTKWidget(centralwidget);
        qvtkWidgetLeft->setObjectName(QString::fromUtf8("qvtkWidgetLeft"));
        qvtkWidgetLeft->setGeometry(QRect(10, 20, 511, 541));
        qvtkWidgetRight = new QVTKWidget(centralwidget);
        qvtkWidgetRight->setObjectName(QString::fromUtf8("qvtkWidgetRight"));
        qvtkWidgetRight->setGeometry(QRect(540, 20, 441, 541));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 610, 114, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 610, 114, 32));
        ShareCameraQt->setCentralWidget(centralwidget);

        retranslateUi(ShareCameraQt);

        QMetaObject::connectSlotsByName(ShareCameraQt);
    } // setupUi

    void retranslateUi(QMainWindow *ShareCameraQt)
    {
        ShareCameraQt->setWindowTitle(QApplication::translate("ShareCameraQt", "ShareCameraQt", 0, QApplication::UnicodeUTF8));
        actionOpenFile->setText(QApplication::translate("ShareCameraQt", "Open File...", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("ShareCameraQt", "Exit", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("ShareCameraQt", "Print", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("ShareCameraQt", "Help", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("ShareCameraQt", "Save", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ShareCameraQt", "Browse", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ShareCameraQt", "Reset", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShareCameraQt: public Ui_ShareCameraQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHARECAMERAQT_H
