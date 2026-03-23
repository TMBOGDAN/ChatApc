#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>

namespace Ui {
class Message;
}

class Message : public QWidget
{
    Q_OBJECT

public:
    explicit Message(QWidget *parent = nullptr);
    ~Message();

    void setMessage(const QString &text);
    void setTime(const QString &time);

    void setIsMe(bool isMe);

private:
    Ui::Message *ui;
    bool m_isMe;
};

#endif // MESSAGE_H
