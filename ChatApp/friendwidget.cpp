// FriendWidget.cpp
#include "friendwidget.h"
#include "ui_friendwidget.h"

FriendWidget::FriendWidget(QWidget *parent) :
    QWidget(parent),
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
}

void FriendWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked();
}
