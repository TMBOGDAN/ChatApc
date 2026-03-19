#include "friendsmanage.h"
#include "ui_friendsmanage.h"

FriendsManage::FriendsManage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FriendsManage)
{
    ui->setupUi(this);
}

FriendsManage::~FriendsManage()
{
    delete ui;
}
