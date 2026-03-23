#include "friendmanage.h"
#include "ui_friendmanage.h"
#include "serverconnection.h"
#include "friendrequestitem.h"
#include <QMessageBox>
#include <QListWidgetItem>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QShowEvent>

FriendManage::FriendManage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FriendManage)
{
    ui->setupUi(this);

    connect(&ServerConnection::instance(),
            &ServerConnection::friendRequestResult,
            this,
            &FriendManage::onFriendRequestResult);

    connect(&ServerConnection::instance(),
            &ServerConnection::friendRequestsReceived,
            this,
            &FriendManage::onFriendRequestsReceived);

    if (ServerConnection::instance().isUserLoggedIn()) {
        ServerConnection::instance().getFriendRequests();
    }
}

FriendManage::~FriendManage()
{
    delete ui;
}

void FriendManage::on_btnAddFriend_clicked()
{
    QString friendName = ui->lineEditUsername->text().trimmed();
    if(friendName.isEmpty()) {
        qDebug() << "Nu ai introdus username!";
        return;
    }

    QString currentUser = ServerConnection::instance().getCurrentUsername();
    ServerConnection::instance().sendFriendRequest(currentUser, friendName);
}

void FriendManage::onFriendRequestResult(bool success, const QString &message)
{
    if (success) {
        QMessageBox::information(this, "Cerere trimisa", message);
    } else {
        QMessageBox::warning(this, "Eroare", message);
    }
}

void FriendManage::onFriendRequestsReceived(const QJsonArray &requests)
{
    qDebug() << "FriendManage::onFriendRequestsReceived called with" << requests.size() << "requests";

    clearRequests();

    for (const QJsonValue &val : requests) {
        QJsonObject obj = val.toObject();
        QString username = obj["username"].toString();
        int requester_id = obj["requester_id"].toInt();

        qDebug() << "Adding friend request:" << username << "id:" << requester_id;
        addFriendRequest(requester_id, username);
    }

    qDebug() << "Total items in list after loading:" << ui->listWidget->count();
}

void FriendManage::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    if (ServerConnection::instance().isUserLoggedIn()) {
        ServerConnection::instance().getFriendRequests();
    }
}

void FriendManage::addFriendRequest(int requesterId, const QString &username)
{
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    FriendRequestItem *requestItem = new FriendRequestItem();

    requestItem->setRequesterId(requesterId);
    requestItem->setUsername(username);

    connect(requestItem, &FriendRequestItem::accepted, this, [username](int){
        QString responder = ServerConnection::instance().getCurrentUsername();
        ServerConnection::instance().respondFriendRequest(username, responder, true);
    });

    connect(requestItem, &FriendRequestItem::declined, this, [username](int){
        QString responder = ServerConnection::instance().getCurrentUsername();
        ServerConnection::instance().respondFriendRequest(username, responder, false);
    });

    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, requestItem);
    item->setSizeHint(requestItem->sizeHint());
}

void FriendManage::clearRequests()
{
    ui->listWidget->clear();
}
