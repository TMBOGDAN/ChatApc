/********************************************************************************
** Form generated from reading UI file 'profilewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEWIDGET_H
#define UI_PROFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileWidget
{
public:
    QLabel *ProfilePicLAbel;
    QPushButton *PicChButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *UsernameLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *EmailLabel;
    QPushButton *EmailButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *DisplayedNameLabe;
    QPushButton *ChangeNameButton;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *PasswordLabel;
    QPushButton *PasswordChButton;

    void setupUi(QWidget *ProfileWidget)
    {
        if (ProfileWidget->objectName().isEmpty())
            ProfileWidget->setObjectName("ProfileWidget");
        ProfileWidget->resize(411, 333);
        ProfilePicLAbel = new QLabel(ProfileWidget);
        ProfilePicLAbel->setObjectName("ProfilePicLAbel");
        ProfilePicLAbel->setGeometry(QRect(40, 30, 91, 81));
        PicChButton = new QPushButton(ProfileWidget);
        PicChButton->setObjectName("PicChButton");
        PicChButton->setGeometry(QRect(260, 50, 80, 24));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PicChButton->sizePolicy().hasHeightForWidth());
        PicChButton->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(ProfileWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 120, 331, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        UsernameLabel = new QLabel(layoutWidget);
        UsernameLabel->setObjectName("UsernameLabel");

        verticalLayout->addWidget(UsernameLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        EmailLabel = new QLabel(layoutWidget);
        EmailLabel->setObjectName("EmailLabel");

        horizontalLayout_3->addWidget(EmailLabel);

        EmailButton = new QPushButton(layoutWidget);
        EmailButton->setObjectName("EmailButton");
        sizePolicy.setHeightForWidth(EmailButton->sizePolicy().hasHeightForWidth());
        EmailButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(EmailButton);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        DisplayedNameLabe = new QLabel(layoutWidget);
        DisplayedNameLabe->setObjectName("DisplayedNameLabe");

        horizontalLayout_2->addWidget(DisplayedNameLabe);

        ChangeNameButton = new QPushButton(layoutWidget);
        ChangeNameButton->setObjectName("ChangeNameButton");
        sizePolicy.setHeightForWidth(ChangeNameButton->sizePolicy().hasHeightForWidth());
        ChangeNameButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(ChangeNameButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        PasswordLabel = new QLabel(layoutWidget);
        PasswordLabel->setObjectName("PasswordLabel");

        horizontalLayout->addWidget(PasswordLabel);

        PasswordChButton = new QPushButton(layoutWidget);
        PasswordChButton->setObjectName("PasswordChButton");
        sizePolicy.setHeightForWidth(PasswordChButton->sizePolicy().hasHeightForWidth());
        PasswordChButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(PasswordChButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ProfileWidget);

        QMetaObject::connectSlotsByName(ProfileWidget);
    } // setupUi

    void retranslateUi(QWidget *ProfileWidget)
    {
        ProfileWidget->setWindowTitle(QCoreApplication::translate("ProfileWidget", "Form", nullptr));
        ProfilePicLAbel->setText(QCoreApplication::translate("ProfileWidget", "TextLabel", nullptr));
        PicChButton->setText(QCoreApplication::translate("ProfileWidget", "Edit", nullptr));
        UsernameLabel->setText(QCoreApplication::translate("ProfileWidget", "Username:", nullptr));
        EmailLabel->setText(QCoreApplication::translate("ProfileWidget", "Email:", nullptr));
        EmailButton->setText(QCoreApplication::translate("ProfileWidget", "Edit", nullptr));
        DisplayedNameLabe->setText(QCoreApplication::translate("ProfileWidget", "Displayed Name:", nullptr));
        ChangeNameButton->setText(QCoreApplication::translate("ProfileWidget", "Edit", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("ProfileWidget", "Change Password", nullptr));
        PasswordChButton->setText(QCoreApplication::translate("ProfileWidget", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileWidget: public Ui_ProfileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWIDGET_H
