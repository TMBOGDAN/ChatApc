#include "friendwidget.h"
#include "ui_friendwidget.h"
#include <QString>

FriendWidget::FriendWidget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::FriendWidget)
{
    ui->setupUi(this);
}

FriendWidget::~FriendWidget()
{
    delete ui;
}

void FriendWidget::setUsername(const QString &username)
{
    ui->friendUsLabel->setText(username);
    this->username = username;
}

void FriendWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked();
}

QString FriendWidget::getUsername() const
{
    return this->username;
}
