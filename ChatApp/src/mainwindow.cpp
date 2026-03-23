#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "friendmanage.h"
#include "loginwindow.h"
#include "serverconnection.h"
#include <QVBoxLayout>
#include "friendwidget.h"
#include "chatwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusbar->showMessage("Logged in as " + ServerConnection::instance().getCurrentUsername() );


    ui->MainContainerWidget->setLayout(new QVBoxLayout());


    connect(&ServerConnection::instance(), &ServerConnection::friendsReceived,this, &MainWindow::loadFriends);

    connect(&ServerConnection::instance(), &ServerConnection::loginResult,
            this, [this](bool success, const QString &message){
                if(success) {

                    ServerConnection::instance().getFriends();
                }
            });

    if (ServerConnection::instance().isUserLoggedIn()) {

        ServerConnection::instance().getFriends();
    }

    connect(ui->searchFrLE, &QLineEdit::textChanged, this, &MainWindow::filterFrList);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void clearLayout(QLayout *layout) {
    if (!layout) return;
    while (QLayoutItem *item = layout->takeAt(0)) {
        if (QWidget *widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
}


void MainWindow::on_btnFriends_clicked()
{
    if (!ui->MainContainerWidget->layout()) {
        ui->MainContainerWidget->setLayout(new QVBoxLayout());
    }

    clearLayout(ui->MainContainerWidget->layout());

    FriendManage *friendManage = new FriendManage(this);
    ui->MainContainerWidget->layout()->addWidget(friendManage);
}


void MainWindow::filterFrList(const QString &text)
{
    for (int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem *item = ui->listWidget->item(i);
        QWidget *widget = ui->listWidget->itemWidget(item);

        QLabel *label = widget->findChild<QLabel*>("friendUsLabel");
        if (!label) continue;

        bool match = label->text().contains(text, Qt::CaseInsensitive);
        item->setHidden(!match);
    }


}

void MainWindow::loadFriends(QStringList friends)
{
    ui->listWidget->clear();

    for (const QString &username : friends) {
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        FriendWidget *friendWidget = new FriendWidget();
        friendWidget->setUsername(username);

        connect(friendWidget, &FriendWidget::clicked, this, [this, username]() {


            QLayout *layout = ui->MainContainerWidget->layout();
            if(layout) {
                QLayoutItem *item;
                while((item = layout->takeAt(0)) != nullptr) {
                    delete item->widget();
                    delete item;
                }
            }

            ChatWindow *chat = new ChatWindow(username, this);
            layout->addWidget(chat);
        });

        item->setSizeHint(friendWidget->sizeHint());
        ui->listWidget->setItemWidget(item, friendWidget);
    }
}


void MainWindow::on_logoutBtn_clicked()
{
    ServerConnection::instance().logout();

    this->close();

    loginWindow* login = new loginWindow();
    login->show();
}
