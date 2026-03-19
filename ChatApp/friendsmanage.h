#ifndef FRIENDSMANAGE_H
#define FRIENDSMANAGE_H

#include <QWidget>

namespace Ui {
class FriendsManage;
}

class FriendsManage : public QWidget
{
    Q_OBJECT

public:
    explicit FriendsManage(QWidget *parent = nullptr);
    ~FriendsManage();

private:
    Ui::FriendsManage *ui;
};

#endif // FRIENDSMANAGE_H
