#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "user.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadFriends(QStringList friends);
    void on_btnFriends_clicked();
    void filterFrList(const QString &text);

    void on_logoutBtn_clicked();

private:
    Ui::MainWindow *ui;
    User currentUser;
};

#endif // MAINWINDOW_H
