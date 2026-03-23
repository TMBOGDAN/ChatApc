#ifndef FRIENDREQUESTITEM_H
#define FRIENDREQUESTITEM_H

#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class FriendRequestItem;
}
QT_END_NAMESPACE

class FriendRequestItem : public QWidget
{
    Q_OBJECT

public:
    explicit FriendRequestItem(QWidget *parent = nullptr);
    ~FriendRequestItem();

    void setUsername(const QString &username);
    void setRequesterId(int id);

signals:
    void accepted(int requesterId);
    void declined(int requesterId);

private slots:
    void on_acceptButton_clicked();

private:
    Ui::FriendRequestItem *ui;
    int requesterId = -1;
};

#endif // FRIENDREQUESTITEM_H
