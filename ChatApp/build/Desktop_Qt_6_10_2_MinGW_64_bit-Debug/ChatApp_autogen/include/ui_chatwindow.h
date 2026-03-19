/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *fiendUsernameLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *profileButton;
    QListWidget *messageArea;
    QHBoxLayout *horizontalLayout;
    QPushButton *emojiButton;
    QLineEdit *inputLine;
    QPushButton *sendButton;

    void setupUi(QWidget *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(524, 496);
        layoutWidget = new QWidget(ChatWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 10, 511, 471));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        fiendUsernameLabel = new QLabel(layoutWidget);
        fiendUsernameLabel->setObjectName("fiendUsernameLabel");

        horizontalLayout_2->addWidget(fiendUsernameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        profileButton = new QPushButton(layoutWidget);
        profileButton->setObjectName("profileButton");

        horizontalLayout_2->addWidget(profileButton);


        verticalLayout->addLayout(horizontalLayout_2);

        messageArea = new QListWidget(layoutWidget);
        messageArea->setObjectName("messageArea");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(messageArea->sizePolicy().hasHeightForWidth());
        messageArea->setSizePolicy(sizePolicy);
        messageArea->setMaximumSize(QSize(16777215, 10000));

        verticalLayout->addWidget(messageArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        emojiButton = new QPushButton(layoutWidget);
        emojiButton->setObjectName("emojiButton");

        horizontalLayout->addWidget(emojiButton);

        inputLine = new QLineEdit(layoutWidget);
        inputLine->setObjectName("inputLine");

        horizontalLayout->addWidget(inputLine);

        sendButton = new QPushButton(layoutWidget);
        sendButton->setObjectName("sendButton");

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QWidget *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "Form", nullptr));
        fiendUsernameLabel->setText(QCoreApplication::translate("ChatWindow", "TextLabel", nullptr));
        profileButton->setText(QCoreApplication::translate("ChatWindow", "Profile", nullptr));
        emojiButton->setText(QCoreApplication::translate("ChatWindow", "emoji", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWindow", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
