#include "message.h"
#include "ui_message.h"
#include <QSizePolicy>

Message::Message(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Message),
    m_isMe(false)
{
    ui->setupUi(this);


    ui->messageLabel->setWordWrap(true);
    ui->messageLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->timeLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    ui->timeLabel->setStyleSheet("color: rgba(255, 255, 255, 0.7); font-size: 10px;");
    ui->bubbleFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->bubbleFrame->setMaximumWidth(380);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setMinimumHeight(0);
}

Message::~Message()
{
    delete ui;
}

void Message::setMessage(const QString &text)
{
    ui->messageLabel->setText(text);
}

void Message::setTime(const QString &time)
{
    ui->timeLabel->setText(time);
}

void Message::setIsMe(bool isMe)
{
    m_isMe = isMe;

    ui->messageLabel->setStyleSheet("color: white;");

    if (m_isMe)
    {
        ui->bubbleFrame->setStyleSheet(
            "QFrame {"
            "background-color: #5865F2;"
            "border-radius: 10px;"
            "padding: 5px;"
            "}"
            );

        ui->horizontalLayout->setAlignment(Qt::AlignRight);
    }
    else
    {
        ui->bubbleFrame->setStyleSheet(
            "QFrame {"
            "background-color: #2B2D31;"
            "border-radius: 10px;"
            "padding: 5px;"
            "}"
            );

        ui->horizontalLayout->setAlignment(Qt::AlignLeft);
    }
}
