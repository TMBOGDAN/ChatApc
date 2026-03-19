#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "friendmanage.h"
#include "serverconnection.h"
#include <QVBoxLayout>
#include "friendwidget.h"
#include "chatwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusbar->showMessage(
        "Logged in as " + ServerConnection::instance().getCurrentUsername()
        );


    ui->MainContainerWidget->setLayout(new QVBoxLayout());

    // 🔹 Conectează semnalul friendsReceived la loadFriends
    connect(&ServerConnection::instance(), &ServerConnection::friendsReceived,
            this, &MainWindow::loadFriends);

    // 🔹 Conectează semnalul loginResult
    connect(&ServerConnection::instance(), &ServerConnection::loginResult,
            this, [this](bool success, const QString &message){
                if(success) {
                    qDebug() << "Login success → cer prieteni";

                    // ✅ Apelează getFriends imediat
                    ServerConnection::instance().getFriends();
                }
            });

    // 🔹 Dacă deja suntem logați
    if (ServerConnection::instance().isUserLoggedIn()) {
        qDebug() << "Deja logat → cer prieteni";
        ServerConnection::instance().getFriends();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Funcție utilitară pentru curățarea unui layout (poate fi pusă în MainWindow)
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
    // 1. Asigură-te că MainContainerWidget are un layout
    if (!ui->MainContainerWidget->layout()) {
        ui->MainContainerWidget->setLayout(new QVBoxLayout());
    }

    // 2. Curăță conținutul vechi din layout
    clearLayout(ui->MainContainerWidget->layout());

    // 3. Creează și adaugă noul widget de management al prietenilor
    FriendManage *friendManage = new FriendManage(this);
    ui->MainContainerWidget->layout()->addWidget(friendManage);
}

void MainWindow::loadFriends(QStringList friends)
{
    // curățăm lista veche
    ui->listWidget->clear();

    for(const QString &username : friends)
    {
        // creăm item-ul pentru QListWidget
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);

        // creăm FriendWidget pentru prieten
        FriendWidget *friendWidget = new FriendWidget();
        friendWidget->setUsername(username);

        // conectăm semnalul clicked pentru fiecare widget
        connect(friendWidget, &FriendWidget::clicked, this, [this, username]() {

            qDebug() << "Clicked on friend:" << username;

            // ștergem chatul vechi
            QLayout *layout = ui->MainContainerWidget->layout();
            if(layout)
            {
                QLayoutItem *item;
                while((item = layout->takeAt(0)) != nullptr)
                {
                    delete item->widget();
                    delete item;
                }
            }

            // creăm chatul
            ChatWindow *chat = new ChatWindow(username, this);

            // îl adăugăm în container
            layout->addWidget(chat);
        });

        // setăm dimensiunea widgetului
        item->setSizeHint(friendWidget->sizeHint());

        // punem widgetul în item
        ui->listWidget->setItemWidget(item, friendWidget);
    }
}
