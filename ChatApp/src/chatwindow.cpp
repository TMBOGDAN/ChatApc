#include "chatwindow.h"
#include "ui_chatwindow.h"
#include "serverconnection.h"
#include "message.h"
#include <QDebug>
#include <QDateTime>

ChatWindow::ChatWindow(const QString &friendUsername, QWidget *parent)
    : QWidget(parent), ui(new Ui::ChatWindow), friendUser(friendUsername)
{
    ui->setupUi(this);

    ui->messageArea->setSpacing(4);
    ui->fiendUsernameLabel->setText(friendUser);

    connect(&ServerConnection::instance(), &ServerConnection::messagesReceived,
            this, &ChatWindow::loadMessages);

    connect(&ServerConnection::instance(), &ServerConnection::messageReceived,
            this, &ChatWindow::addMessage);

    ServerConnection::instance().getMessages(ServerConnection::instance().getCurrentUsername(),
                                             friendUser);
}

ChatWindow::~ChatWindow()
{
    ServerConnection::instance().saveSession(ServerConnection::instance().getCurrentUsername(),
                                             friendUser);
    delete ui;
}

void ChatWindow::addMessage(const QJsonObject &msg)
{
    QString sender = msg["sender_user"].toString();
    QString receiver = msg["receiver_user"].toString();
    QString text = msg["content"].toString();
    QString timeStr = msg["sent_at"].toString();

    QString myUser = ServerConnection::instance().getCurrentUsername();

    bool isChatMessage = (sender == friendUser && receiver == myUser) ||
                         (sender == myUser && receiver == friendUser);

    if (!isChatMessage) {
        return;
    }

    if (sender == myUser && msg["from_server"].toBool(false)) {
        return;
    }

    QDateTime messageTime = QDateTime::fromString(timeStr, Qt::ISODate);
    QString displayTime;
    if (messageTime.date() == QDate::currentDate())
        displayTime = messageTime.toString("hh:mm");
    else
        displayTime = messageTime.toString("dd.MM.yyyy hh:mm");

    QListWidgetItem *item = new QListWidgetItem(ui->messageArea);
    Message *messageWidget = new Message();

    if (text.trimmed().isEmpty()) {
        qDebug() << "ChatWindow::addMessage: mesaj gol, ignorat";
        return;
    }

    bool isMine = (sender == myUser);
    messageWidget->setIsMe(isMine);
    messageWidget->setMessage(text);
    messageWidget->setTime(displayTime);
    messageWidget->adjustSize();

    item->setSizeHint(messageWidget->sizeHint());
    ui->messageArea->setItemWidget(item, messageWidget);
    ui->messageArea->scrollToBottom();
}

void ChatWindow::loadMessages(const QJsonArray &messages)
{
    ui->messageArea->clear();

    for (const QJsonValue &value : messages) {
        addMessage(value.toObject());
    }
}

void ChatWindow::on_sendButton_clicked()
{
    QString text = ui->inputLine->text();
    if (text.isEmpty())
        return;

    ServerConnection::instance().sendMessage(text, friendUser);

    QJsonObject msg;
    msg["sender_user"] = ServerConnection::instance().getCurrentUsername();
    msg["receiver_user"] = friendUser;
    msg["content"] = text;
    msg["sent_at"] = QDateTime::currentDateTime().toString(Qt::ISODate);

    addMessage(msg);
    ui->inputLine->clear();
}
