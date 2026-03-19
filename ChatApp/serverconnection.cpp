#include "serverconnection.h"
#include <QDebug>
#include <QJsonDocument>
#include <QDateTime>

////////////////////////////////////////////////////////
/// SINGLETON
////////////////////////////////////////////////////////
ServerConnection& ServerConnection::instance()
{
    static ServerConnection instance;
    return instance;
}

////////////////////////////////////////////////////////
/// CONSTRUCTOR
////////////////////////////////////////////////////////
ServerConnection::ServerConnection(QObject *parent)
    : QObject(parent)
{
    connect(&socket, &QWebSocket::connected,
            this, &ServerConnection::onConnected);

    connect(&socket, &QWebSocket::textMessageReceived,
            this, &ServerConnection::onTextMessageReceived);
}

////////////////////////////////////////////////////////
/// CONNECT
////////////////////////////////////////////////////////
void ServerConnection::connectToServer()
{
    if (socket.state() != QAbstractSocket::ConnectedState)
        socket.open(QUrl("ws://localhost:8080"));
}

////////////////////////////////////////////////////////
/// CONNECTED (🔥 FIX)
////////////////////////////////////////////////////////
void ServerConnection::onConnected()
{
    qDebug() << "Connected to server!";
}

////////////////////////////////////////////////////////
/// LOGIN
////////////////////////////////////////////////////////
void ServerConnection::sendLogin(const QString &email, const QString &password)
{
    QJsonObject json;
    json["type"] = "login";
    json["email"] = email;
    json["password"] = password;

    socket.sendTextMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

////////////////////////////////////////////////////////
/// REGISTER (🔥 FIX)
////////////////////////////////////////////////////////
void ServerConnection::sendRegister(const QString &email,
                                    const QString &password,
                                    const QString &username)
{
    QJsonObject json;
    json["type"] = "register";
    json["email"] = email;
    json["password"] = password;
    json["username"] = username;

    socket.sendTextMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

////////////////////////////////////////////////////////
/// SEND MESSAGE
////////////////////////////////////////////////////////
void ServerConnection::sendMessage(const QString &text,
                                   const QString &receiver_user)
{
    if (!isLoggedIn) return;

    QJsonObject json;
    json["type"] = "message";
    json["sender_username"] = currentUser.getUsername();
    json["receiver_username"] = receiver_user;
    json["text"] = text;

    socket.sendTextMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

////////////////////////////////////////////////////////
/// GET MESSAGES (🔥 FIX)
////////////////////////////////////////////////////////
void ServerConnection::getMessages(const QString &myUser,
                                   const QString &friendUser)
{
    if (!isLoggedIn) return;

    QJsonObject json;
    json["type"] = "get_messages";
    json["myUser"] = myUser;
    json["friendUser"] = friendUser;

    socket.sendTextMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

////////////////////////////////////////////////////////
/// GET FRIENDS
////////////////////////////////////////////////////////
void ServerConnection::getFriends()
{
    if (!isLoggedIn) return;

    QJsonObject json;
    json["type"] = "get_friends";
    json["userId"] = currentUser.getId();
    qDebug() << "se apeleaza get friends ";
    socket.sendTextMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

////////////////////////////////////////////////////////
/// GET FRIEND REQUESTS
////////////////////////////////////////////////////////
void ServerConnection::getFriendRequests()
{
    if (!isLoggedIn) return;

    QJsonObject json;
    json["type"] = "get_friend_requests";
    json["username"] = currentUser.getUsername();

    socket.sendTextMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

////////////////////////////////////////////////////////
/// SEND FRIEND REQUEST
////////////////////////////////////////////////////////
void ServerConnection::sendFriendRequest(const QString &sender,
                                         const QString &receiver)
{
    QJsonObject json;
    json["type"] = "send_friend_request";
    json["sender"] = sender;
    json["receiver"] = receiver;

    socket.sendTextMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

////////////////////////////////////////////////////////
/// RESPOND FRIEND REQUEST
////////////////////////////////////////////////////////
void ServerConnection::respondFriendRequest(const QString &requester,
                                            const QString &responder,
                                            bool response)
{
    QJsonObject json;
    json["type"] = "respond_friend_request";
    json["requester"] = requester;
    json["responder"] = responder;
    json["response"] = response;

    socket.sendTextMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

////////////////////////////////////////////////////////
/// RECEIVE MESSAGES
////////////////////////////////////////////////////////
void ServerConnection::onTextMessageReceived(const QString &message)
{
    QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
    if (!doc.isObject()) return;

    QJsonObject obj = doc.object();
    QString type = obj["type"].toString();

    qDebug() << "TYPE:" << type;
    qDebug() << "FULL:" << obj;

    ////////////////////////////////////////
    /// LOGIN
    ////////////////////////////////////////
    if (type == "login_result")
    {
        bool success = obj["success"].toBool();

        if (success)
        {
            QJsonObject u = obj["user"].toObject();
            currentUser = User(u["username"].toString(),
                               u["id"].toInt(),
                               u["email"].toString(),
                               "online");

            isLoggedIn = true;
        }

        emit loginResult(success, obj["message"].toString());
    }

    ////////////////////////////////////////
    /// FRIENDS LIST
    ////////////////////////////////////////
    else if (type == "get_friends_result")
    {
        QJsonArray friends = obj["friends"].toArray();
        QStringList list;

        qDebug() << "Am primit lista de prieteni:";

        for (const QJsonValue &val : friends)
        {
            if (val.isObject()){
                QString username = val.toObject()["username"].toString();
                qDebug() << "Friend (object):" << username;
                list.append(username);
            }
            else if (val.isString()) {
                QString username = val.toString();
                qDebug() << "Friend (string):" << username;
                list.append(username);
            }
            else {
                qDebug() << "Valoare necunoscuta in friends array:" << val;
            }
        }

        qDebug() << "Lista finala:" << list;

        emit friendsReceived(list);
    }

    ////////////////////////////////////////
    /// FRIEND REQUESTS
    ////////////////////////////////////////
    else if (type == "friend_requests_list")
    {
        emit friendRequestsReceived(obj["requests"].toArray());
    }

    ////////////////////////////////////////
    /// SINGLE MESSAGE
    ////////////////////////////////////////
    else if (type == "message")
    {
        QJsonObject m;
        m["sender_user"] = obj["sender_username"].toString();
        m["content"] = obj["text"].toString();
        m["sent_at"] = QDateTime::currentDateTime().toString(Qt::ISODate);

        emit messageReceived(m);
    }

    ////////////////////////////////////////
    /// MESSAGE HISTORY
    ////////////////////////////////////////
    else if (type == "messages_list")
    {
        emit messagesReceived(obj["messages"].toArray());
    }
}
