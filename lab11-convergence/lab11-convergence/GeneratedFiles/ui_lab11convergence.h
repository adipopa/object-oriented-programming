/********************************************************************************
** Form generated from reading UI file 'lab11convergence.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB11CONVERGENCE_H
#define UI_LAB11CONVERGENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab11convergenceClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab11convergenceClass)
    {
        if (lab11convergenceClass->objectName().isEmpty())
            lab11convergenceClass->setObjectName(QString::fromUtf8("lab11convergenceClass"));
        lab11convergenceClass->resize(600, 400);
        menuBar = new QMenuBar(lab11convergenceClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        lab11convergenceClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lab11convergenceClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        lab11convergenceClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(lab11convergenceClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lab11convergenceClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lab11convergenceClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        lab11convergenceClass->setStatusBar(statusBar);

        retranslateUi(lab11convergenceClass);

        QMetaObject::connectSlotsByName(lab11convergenceClass);
    } // setupUi

    void retranslateUi(QMainWindow *lab11convergenceClass)
    {
        lab11convergenceClass->setWindowTitle(QApplication::translate("lab11convergenceClass", "lab11convergence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab11convergenceClass: public Ui_lab11convergenceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB11CONVERGENCE_H
