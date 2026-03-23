#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QDebug>

#include "serverconnection.h"

loginWindow::loginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    auto &conn = ServerConnection::instance();
    conn.connectToServer();

    connect(&conn,&ServerConnection::loginResult,this,&loginWindow::onLoginResult);

    connect(&conn,&ServerConnection::registerResult,this,&loginWindow::onRegisterResult);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::onLoginResult(bool success, const QString &message)
{
    qDebug() << "Login result:" << success << message;

    if (success) {
        QMessageBox::information(this, "Login reușit", message);

        MainWindow *mw = new MainWindow();
        mw->show();

        this->hide();
    } else {
        QMessageBox::warning(this, "Login eșuat", message);
        ui->p_LineEdit->clear();
    }
}

void loginWindow::onRegisterResult(bool success, const QString &message)
{
    qDebug() << "Register result:" << success << message;

    if (success) {
        QMessageBox::information(this, "Succes", message);

        ui->AccountTabWidget->setCurrentIndex(0);

        ui->eRegLineEdit->clear();
        ui->pasRegLineEdit->clear();
        ui->pas2RegLineEdit->clear();
        ui->userRegLineEdit->clear();
    } else {
        QMessageBox::warning(this, "Eroare", message);

        ui->pasRegLineEdit->clear();
        ui->pas2RegLineEdit->clear();
    }
}

void loginWindow::on_logButton_clicked()
{
    QString email = ui->e_LineEdit->text();
    QString password = ui->p_LineEdit->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Completează email și parola!");
        return;
    }

    ServerConnection::instance().sendLogin(email, password);
}

void loginWindow::on_crAcButton_clicked()
{
    QString email = ui->eRegLineEdit->text();
    QString password = ui->pasRegLineEdit->text();
    QString password2 = ui->pas2RegLineEdit->text();
    QString username = ui->userRegLineEdit->text();

    if (email.isEmpty() || password.isEmpty() ||
        password2.isEmpty() || username.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Complete all information");
        return;
    }

    if (password != password2) {
        QMessageBox::warning(this, "Eroare", "Passwords are different");
        return;
    }

    ServerConnection::instance().sendRegister(email, password, username);
}
