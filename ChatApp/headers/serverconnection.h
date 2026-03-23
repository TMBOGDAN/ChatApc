#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include <QObject>
#include <QWebSocket>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrl>
#include "user.h"

class ServerConnection : public QObject
{
    Q_OBJECT

public:
    static ServerConnection &instance();

    void connectToServer();
    void sendLogin(const QString &email, const QString &password);
    void sendRegister(const QString &email, const QString &password, const QString &username);
    void sendMessage(const QString &text, const QString &receiver_user);

    void sendFriendRequest(const QString &sender, const QString &receiver);
    void respondFriendRequest(const QString &requester, const QString &responder, bool response);
    void getFriendRequests();
    void getFriends();
    void getMessages(const QString &myUser, const QString &friendUser);
    void saveSession(const QString &myUser, const QString &friendUser);

    void logout();

    QString getCurrentUsername() const { return currentUser.getUsername(); }
    bool isUserLoggedIn() const { return isLoggedIn; }

signals:
    void loginResult(bool success, const QString& message);
    void registerResult(bool success, const QString& message);

    void messageReceived(const QJsonObject &message);
    void messagesReceived(const QJsonArray &messages);

    void friendRequestResult(bool success, const QString &message);
    void friendRequestResponseResult(bool success, const QString &message);
    void friendRequestsReceived(const QJsonArray &requests);

    void friendsReceived(QStringList friends);

private slots:
    void onConnected();
    void onTextMessageReceived(const QString& message);

private:
    explicit ServerConnection(QObject *parent = nullptr);

    QWebSocket socket;
    User currentUser;
    bool isLoggedIn = false;
};

#endif // SERVERCONNECTION_H
