#ifndef FRIENDMANAGE_H
#define FRIENDMANAGE_H

#include <QWidget>
#include <QShowEvent>
#include <QJsonArray>

namespace Ui {
class FriendManage;
}

struct FriendRequest {
    int id;
    QString username;
};

class FriendManage : public QWidget
{
    Q_OBJECT

public:
    explicit FriendManage(QWidget *parent = nullptr);
    ~FriendManage();

    void addFriendRequest(int requesterId, const QString &username);

protected:
    void showEvent(QShowEvent *event) override;

private slots:

    void on_btnAddFriend_clicked();

    void onFriendRequestResult(bool success, const QString &message);

    void onFriendRequestsReceived(const QJsonArray &requests);

private:
    Ui::FriendManage *ui;

    void clearRequests();
};

#endif // FRIENDMANAGE_H
