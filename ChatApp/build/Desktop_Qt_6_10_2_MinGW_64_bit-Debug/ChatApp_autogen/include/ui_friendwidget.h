/********************************************************************************
** Form generated from reading UI file 'friendwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDWIDGET_H
#define UI_FRIENDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendWidget
{
public:
    QLabel *friendUsLabel;

    void setupUi(QWidget *FriendWidget)
    {
        if (FriendWidget->objectName().isEmpty())
            FriendWidget->setObjectName("FriendWidget");
        FriendWidget->resize(183, 71);
        FriendWidget->setMinimumSize(QSize(100, 40));
        friendUsLabel = new QLabel(FriendWidget);
        friendUsLabel->setObjectName("friendUsLabel");
        friendUsLabel->setGeometry(QRect(0, 0, 120, 50));
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(friendUsLabel->sizePolicy().hasHeightForWidth());
        friendUsLabel->setSizePolicy(sizePolicy);
        friendUsLabel->setMinimumSize(QSize(120, 40));

        retranslateUi(FriendWidget);

        QMetaObject::connectSlotsByName(FriendWidget);
    } // setupUi

    void retranslateUi(QWidget *FriendWidget)
    {
        FriendWidget->setWindowTitle(QCoreApplication::translate("FriendWidget", "Form", nullptr));
        friendUsLabel->setText(QCoreApplication::translate("FriendWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendWidget: public Ui_FriendWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDWIDGET_H
