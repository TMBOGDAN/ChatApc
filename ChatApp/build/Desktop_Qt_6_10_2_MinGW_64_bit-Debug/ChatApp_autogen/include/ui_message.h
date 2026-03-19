/********************************************************************************
** Form generated from reading UI file 'message.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_H
#define UI_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Message
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *hlorizontalyayout;
    QFrame *bubbleFrame;
    QVBoxLayout *bubbleLayout;
    QLabel *messageLabel;
    QLabel *timeLabel;

    void setupUi(QWidget *Message)
    {
        if (Message->objectName().isEmpty())
            Message->setObjectName("Message");
        Message->setEnabled(true);
        Message->resize(569, 89);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Message->sizePolicy().hasHeightForWidth());
        Message->setSizePolicy(sizePolicy);
        Message->setMinimumSize(QSize(0, 40));
        Message->setMaximumSize(QSize(1000, 16777215));
        horizontalLayout = new QHBoxLayout(Message);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 2, 0, 2);
        hlorizontalyayout = new QVBoxLayout();
        hlorizontalyayout->setSpacing(2);
        hlorizontalyayout->setObjectName("hlorizontalyayout");
        hlorizontalyayout->setContentsMargins(6, 0, 6, 0);
        bubbleFrame = new QFrame(Message);
        bubbleFrame->setObjectName("bubbleFrame");
        bubbleFrame->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bubbleFrame->sizePolicy().hasHeightForWidth());
        bubbleFrame->setSizePolicy(sizePolicy1);
        bubbleFrame->setMaximumSize(QSize(1000, 200));
        bubbleFrame->setFrameShape(QFrame::Shape::StyledPanel);
        bubbleFrame->setFrameShadow(QFrame::Shadow::Raised);
        bubbleLayout = new QVBoxLayout(bubbleFrame);
        bubbleLayout->setSpacing(2);
        bubbleLayout->setObjectName("bubbleLayout");
        messageLabel = new QLabel(bubbleFrame);
        messageLabel->setObjectName("messageLabel");
        sizePolicy1.setHeightForWidth(messageLabel->sizePolicy().hasHeightForWidth());
        messageLabel->setSizePolicy(sizePolicy1);
        messageLabel->setMaximumSize(QSize(1000, 50));

        bubbleLayout->addWidget(messageLabel);

        timeLabel = new QLabel(bubbleFrame);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setMaximumSize(QSize(200, 20));

        bubbleLayout->addWidget(timeLabel);


        hlorizontalyayout->addWidget(bubbleFrame);


        horizontalLayout->addLayout(hlorizontalyayout);


        retranslateUi(Message);

        QMetaObject::connectSlotsByName(Message);
    } // setupUi

    void retranslateUi(QWidget *Message)
    {
        Message->setWindowTitle(QCoreApplication::translate("Message", "Form", nullptr));
        messageLabel->setText(QCoreApplication::translate("Message", "TextLabel", nullptr));
        timeLabel->setText(QCoreApplication::translate("Message", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Message: public Ui_Message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H
