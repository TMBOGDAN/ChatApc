#include "friendrequestitem.h"
#include "ui_friendrequestitem.h"
#include "serverconnection.h"
#include "user.h"

FriendRequestItem::FriendRequestItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FriendRequestItem)
{
    ui->setupUi(this);
    connect(ui->acceptButton, &QPushButton::clicked, this, [this]() {
        emit accepted(requesterId);
    });

    connect(ui->declineButton, &QPushButton::clicked, this, [this]() {
        emit declined(requesterId);
    });
}

FriendRequestItem::~FriendRequestItem()
{
    delete ui;
}

void FriendRequestItem::setUsername(const QString &username)
{
    ui->usernameLabel->setText(username);
}

void FriendRequestItem::setRequesterId(int id)
{
    requesterId = id;
}


void FriendRequestItem::on_acceptButton_clicked()
{
    QString responder=ServerConnection::instance().getCurrentUsername();
    QString requester=ui->usernameLabel->text();

    ServerConnection::instance().respondFriendRequest(requester,responder,true);
}

