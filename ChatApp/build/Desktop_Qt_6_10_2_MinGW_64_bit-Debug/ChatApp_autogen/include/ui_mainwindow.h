/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *MainContainerWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *btnFriends;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainContainerWidget = new QWidget(centralwidget);
        MainContainerWidget->setObjectName("MainContainerWidget");
        MainContainerWidget->setGeometry(QRect(240, 10, 541, 541));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 10, 231, 541));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);

        btnFriends = new QPushButton(layoutWidget);
        btnFriends->setObjectName("btnFriends");

        verticalLayout_2->addWidget(btnFriends);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        listWidget = new QListWidget(layoutWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout_2->addWidget(pushButton_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Profile", nullptr));
        btnFriends->setText(QCoreApplication::translate("MainWindow", "Friends", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "New Item", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Setings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
