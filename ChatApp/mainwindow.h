#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

#include "user.h" // for User type

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // constructor accepts logged-in user info
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

   void loadFriends(QStringList friends);
    void on_btnFriends_clicked();

private:
    Ui::MainWindow *ui;
    User currentUser; // copy of the authenticated user
};
#endif // MAINWINDOW_H
