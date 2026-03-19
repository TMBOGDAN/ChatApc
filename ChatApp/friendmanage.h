#ifndef FRIENDMANAGE_H
#define FRIENDMANAGE_H

#include <QWidget>
#include <QShowEvent>
#include <QJsonArray>

namespace Ui {
class FriendManage;
}

// Structura simplă pentru FriendRequest (opțional, doar ca referință)
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

    // adaugă cerere în listWidget
    void addFriendRequest(int requesterId, const QString &username);

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    // buton add friend
    void on_btnAddFriend_clicked();

    // raspuns pentru add friend
    void onFriendRequestResult(bool success, const QString &message);

    // primire lista cereri de prietenie de la server
    void onFriendRequestsReceived(const QJsonArray &requests);  // << slotul pentru QJsonArray

private:
    Ui::FriendManage *ui;

    // functie helper pentru curatare lista
    void clearRequests();
};

#endif // FRIENDMANAGE_H
