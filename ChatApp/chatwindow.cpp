#include "chatwindow.h"
#include "ui_chatwindow.h"
#include "serverconnection.h"
#include "message.h"
#include <QDebug>
#include <QDateTime>

ChatWindow::ChatWindow(const QString &friendUsername, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::ChatWindow),
    friendUser(friendUsername)
{
    ui->setupUi(this);

    // Spacing mai strâns pentru QListWidget
    ui->messageArea->setSpacing(4);

    // Nume prieten în header
    ui->fiendUsernameLabel->setText(friendUser);

    // Conectează semnale la sloturi
    connect(&ServerConnection::instance(),
            &ServerConnection::messagesReceived,
            this,
            &ChatWindow::loadMessages);

    connect(&ServerConnection::instance(),
            &ServerConnection::messageReceived,
            this,
            &ChatWindow::addMessage);

    // Încarcă conversația istorică
    ServerConnection::instance().getMessages(
        ServerConnection::instance().getCurrentUsername(),
        friendUser
        );
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

////////////////////////////////////////////////////////
/// ADD MESSAGE (LIVE SAU LOCAL)
////////////////////////////////////////////////////////
void ChatWindow::addMessage(const QJsonObject &msg)
{
    QString sender = msg["sender_user"].toString();
    QString text = msg["content"].toString();
    QString timeStr = msg["sent_at"].toString();

    // Convertim timpul mesajului
    QDateTime messageTime = QDateTime::fromString(timeStr, Qt::ISODate);

    QString displayTime;
    if (messageTime.date() == QDate::currentDate())
        displayTime = messageTime.toString("hh:mm");           // Azi -> doar ora:minut
    else
        displayTime = messageTime.toString("dd.MM.yyyy hh:mm"); // Altă zi -> data+ora

    // Creează QListWidgetItem și Message widget
    QListWidgetItem *item = new QListWidgetItem(ui->messageArea);
    Message *messageWidget = new Message();

    bool isMine = (sender == ServerConnection::instance().getCurrentUsername());
    messageWidget->setIsMe(isMine);
    messageWidget->setMessage(text);
    messageWidget->setTime(displayTime);

    messageWidget->adjustSize();
    item->setSizeHint(messageWidget->sizeHint());

    ui->messageArea->setItemWidget(item, messageWidget);

    // Scroll la final
    ui->messageArea->scrollToBottom();
}

////////////////////////////////////////////////////////
/// LOAD HISTORY
////////////////////////////////////////////////////////
void ChatWindow::loadMessages(const QJsonArray &messages)
{
    ui->messageArea->clear();

    for(const QJsonValue &value : messages)
    {
        addMessage(value.toObject());
    }
}

////////////////////////////////////////////////////////
/// SEND MESSAGE
////////////////////////////////////////////////////////
void ChatWindow::on_sendButton_clicked()
{
    QString text = ui->inputLine->text();
    if(text.isEmpty())
        return;

    // Trimite mesajul la server
    ServerConnection::instance().sendMessage(text, friendUser);

    // Creează mesajul local și îl afișează imediat
    QJsonObject msg;
    msg["sender_user"] = ServerConnection::instance().getCurrentUsername();
    msg["content"] = text;
    msg["sent_at"] = QDateTime::currentDateTime().toString(Qt::ISODate);

    addMessage(msg);

    ui->inputLine->clear();
}
