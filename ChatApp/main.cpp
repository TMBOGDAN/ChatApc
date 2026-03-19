#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    loginWindow logW;
    logW.show();

    return a.exec();

}
