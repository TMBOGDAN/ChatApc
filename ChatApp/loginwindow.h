#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class loginWindow;
}

class loginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private slots:
    void on_logButton_clicked();
    void onLoginResult(bool success, const QString& message);
    void onRegisterResult(bool success, const QString& message);
    void on_crAcButton_clicked();

private:
    Ui::loginWindow *ui;
};

#endif // LOGINWINDOW_H
