/********************************************************************************
** Form generated from reading UI file 'friendmanage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDMANAGE_H
#define UI_FRIENDMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendManage
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditUsername;
    QPushButton *btnAddFriend;
    QListWidget *listWidget;

    void setupUi(QWidget *FriendManage)
    {
        if (FriendManage->objectName().isEmpty())
            FriendManage->setObjectName("FriendManage");
        FriendManage->resize(542, 567);
        layoutWidget = new QWidget(FriendManage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 30, 491, 501));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEditUsername = new QLineEdit(layoutWidget);
        lineEditUsername->setObjectName("lineEditUsername");

        horizontalLayout->addWidget(lineEditUsername);

        btnAddFriend = new QPushButton(layoutWidget);
        btnAddFriend->setObjectName("btnAddFriend");

        horizontalLayout->addWidget(btnAddFriend);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setSpacing(0);
        listWidget->setGridSize(QSize(0, 0));
        listWidget->setBatchSize(50);

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);


        retranslateUi(FriendManage);

        QMetaObject::connectSlotsByName(FriendManage);
    } // setupUi

    void retranslateUi(QWidget *FriendManage)
    {
        FriendManage->setWindowTitle(QCoreApplication::translate("FriendManage", "Form", nullptr));
        btnAddFriend->setText(QCoreApplication::translate("FriendManage", "ADD FRIEND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendManage: public Ui_FriendManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDMANAGE_H
