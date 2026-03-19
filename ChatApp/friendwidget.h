// FriendWidget.h
#ifndef FRIENDWIDGET_H
#define FRIENDWIDGET_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class FriendWidget;
}

class FriendWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FriendWidget(QWidget *parent = nullptr);
    ~FriendWidget();

    void setUsername(const QString &username);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::FriendWidget *ui;
};

#endif // FRIENDWIDGET_H
