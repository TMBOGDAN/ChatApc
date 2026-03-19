/********************************************************************************
** Form generated from reading UI file 'friendrequestitem.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDREQUESTITEM_H
#define UI_FRIENDREQUESTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendRequestItem
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLabel;
    QPushButton *acceptButton;
    QPushButton *declineButton;

    void setupUi(QWidget *FriendRequestItem)
    {
        if (FriendRequestItem->objectName().isEmpty())
            FriendRequestItem->setObjectName("FriendRequestItem");
        FriendRequestItem->resize(337, 50);
        FriendRequestItem->setMinimumSize(QSize(100, 50));
        layoutWidget = new QWidget(FriendRequestItem);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 321, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(layoutWidget);
        usernameLabel->setObjectName("usernameLabel");

        horizontalLayout->addWidget(usernameLabel);

        acceptButton = new QPushButton(layoutWidget);
        acceptButton->setObjectName("acceptButton");

        horizontalLayout->addWidget(acceptButton);

        declineButton = new QPushButton(layoutWidget);
        declineButton->setObjectName("declineButton");

        horizontalLayout->addWidget(declineButton);


        retranslateUi(FriendRequestItem);

        QMetaObject::connectSlotsByName(FriendRequestItem);
    } // setupUi

    void retranslateUi(QWidget *FriendRequestItem)
    {
        FriendRequestItem->setWindowTitle(QCoreApplication::translate("FriendRequestItem", "Form", nullptr));
        usernameLabel->setText(QCoreApplication::translate("FriendRequestItem", "TextLabel", nullptr));
        acceptButton->setText(QCoreApplication::translate("FriendRequestItem", "Accept", nullptr));
        declineButton->setText(QCoreApplication::translate("FriendRequestItem", "Decline", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendRequestItem: public Ui_FriendRequestItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDREQUESTITEM_H
