/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include "graphicwidget.h"
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QWidget *centralwidget;
    QWidget *MainWidget;
    GraphicWidget *graphicsView;
    QWidget *settingwidget;
    QGroupBox *groupBox_2;
    QDoubleSpinBox *spinBoxA;
    QDoubleSpinBox *spinBoxB;
    QLabel *labelA;
    QLabel *labelB;
    QGroupBox *groupBox_3;
    QSpinBox *NbCible;
    QSpinBox *TailleMini;
    QSpinBox *TailleMaxi;
    QLabel *nbcibles;
    QLabel *taillemin;
    QLabel *taillemax;
    QGroupBox *groupBox;
    QLabel *nombrecible;
    QLabel *nbciblesr;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1354, 799);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWidget = new QWidget(centralwidget);
        MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->setGeometry(QRect(0, 0, 1051, 801));
        graphicsView = new GraphicWidget(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1051, 751));
        settingwidget = new QWidget(centralwidget);
        settingwidget->setObjectName(QString::fromUtf8("settingwidget"));
        settingwidget->setGeometry(QRect(1050, 0, 411, 801));
        groupBox_2 = new QGroupBox(settingwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 20, 291, 121));
        spinBoxA = new QDoubleSpinBox(groupBox_2);
        spinBoxA->setObjectName(QString::fromUtf8("spinBoxA"));
        spinBoxA->setGeometry(QRect(90, 40, 42, 22));
        spinBoxB = new QDoubleSpinBox(groupBox_2);
        spinBoxB->setObjectName(QString::fromUtf8("spinBoxB"));
        spinBoxB->setGeometry(QRect(90, 80, 42, 22));
        labelA = new QLabel(groupBox_2);
        labelA->setObjectName(QString::fromUtf8("labelA"));
        labelA->setGeometry(QRect(60, 40, 16, 21));
        labelB = new QLabel(groupBox_2);
        labelB->setObjectName(QString::fromUtf8("labelB"));
        labelB->setGeometry(QRect(60, 80, 16, 21));
        groupBox_3 = new QGroupBox(settingwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 210, 291, 501));
        NbCible = new QSpinBox(groupBox_3);
        NbCible->setObjectName(QString::fromUtf8("NbCible"));
        NbCible->setGeometry(QRect(170, 50, 42, 22));
        TailleMini = new QSpinBox(groupBox_3);
        TailleMini->setObjectName(QString::fromUtf8("TailleMini"));
        TailleMini->setGeometry(QRect(170, 90, 42, 22));
        TailleMaxi = new QSpinBox(groupBox_3);
        TailleMaxi->setObjectName(QString::fromUtf8("TailleMaxi"));
        TailleMaxi->setGeometry(QRect(170, 140, 42, 22));
        nbcibles = new QLabel(groupBox_3);
        nbcibles->setObjectName(QString::fromUtf8("nbcibles"));
        nbcibles->setGeometry(QRect(75, 50, 91, 21));
        taillemin = new QLabel(groupBox_3);
        taillemin->setObjectName(QString::fromUtf8("taillemin"));
        taillemin->setGeometry(QRect(45, 90, 121, 21));
        taillemax = new QLabel(groupBox_3);
        taillemax->setObjectName(QString::fromUtf8("taillemax"));
        taillemax->setGeometry(QRect(45, 140, 121, 21));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 180, 291, 151));
        nombrecible = new QLabel(groupBox);
        nombrecible->setObjectName(QString::fromUtf8("nombrecible"));
        nombrecible->setGeometry(QRect(20, 100, 141, 21));
        nbciblesr = new QLabel(groupBox);
        nbciblesr->setObjectName(QString::fromUtf8("nbciblesr"));
        nbciblesr->setGeometry(QRect(170, 100, 51, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1354, 20));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionQuitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Choix de A et B ", nullptr));
        labelA->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        labelB->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Choix des Param\303\250tres", nullptr));
        nbcibles->setText(QCoreApplication::translate("MainWindow", "Nombre de cibles", nullptr));
        taillemin->setText(QCoreApplication::translate("MainWindow", "Taille minimale de cibles", nullptr));
        taillemax->setText(QCoreApplication::translate("MainWindow", "Taille maximale des cibles", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "En cours", nullptr));
        nombrecible->setText(QCoreApplication::translate("MainWindow", "Nombre de cibles restantes ", nullptr));
        nbciblesr->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
