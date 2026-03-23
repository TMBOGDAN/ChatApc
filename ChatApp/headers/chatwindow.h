#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonObject>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindow(const QString &friendUsername, QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void loadMessages(const QJsonArray &messages);
    void on_sendButton_clicked();
    void addMessage(const QJsonObject &msg);

private:
    Ui::ChatWindow *ui;
    QString friendUser;
};

#endif
