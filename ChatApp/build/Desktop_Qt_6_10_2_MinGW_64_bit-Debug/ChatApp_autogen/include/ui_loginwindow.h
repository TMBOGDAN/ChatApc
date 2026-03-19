/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QTabWidget *AccountTabWidget;
    QWidget *loginTab;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *e_LineEdit;
    QLineEdit *p_LineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *logButton;
    QPushButton *regButton;
    QPushButton *helpButton;
    QWidget *registerTab;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *eRegLineEdit;
    QLineEdit *userRegLineEdit;
    QLineEdit *pasRegLineEdit;
    QLineEdit *pas2RegLineEdit;
    QPushButton *crAcButton;
    QWidget *registerTab_2;
    QPushButton *sentMButton;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_7;

    void setupUi(QWidget *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName("loginWindow");
        loginWindow->resize(583, 335);
        AccountTabWidget = new QTabWidget(loginWindow);
        AccountTabWidget->setObjectName("AccountTabWidget");
        AccountTabWidget->setGeometry(QRect(10, 20, 441, 261));
        loginTab = new QWidget();
        loginTab->setObjectName("loginTab");
        label = new QLabel(loginTab);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 121, 21));
        layoutWidget = new QWidget(loginTab);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 40, 371, 90));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        e_LineEdit = new QLineEdit(layoutWidget);
        e_LineEdit->setObjectName("e_LineEdit");

        verticalLayout->addWidget(e_LineEdit);

        p_LineEdit = new QLineEdit(layoutWidget);
        p_LineEdit->setObjectName("p_LineEdit");

        verticalLayout->addWidget(p_LineEdit);


        horizontalLayout->addLayout(verticalLayout);

        layoutWidget1 = new QWidget(loginTab);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 140, 254, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        logButton = new QPushButton(layoutWidget1);
        logButton->setObjectName("logButton");

        horizontalLayout_2->addWidget(logButton);

        regButton = new QPushButton(layoutWidget1);
        regButton->setObjectName("regButton");

        horizontalLayout_2->addWidget(regButton);

        helpButton = new QPushButton(layoutWidget1);
        helpButton->setObjectName("helpButton");

        horizontalLayout_2->addWidget(helpButton);

        AccountTabWidget->addTab(loginTab, QString());
        registerTab = new QWidget();
        registerTab->setObjectName("registerTab");
        layoutWidget2 = new QWidget(registerTab);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 20, 421, 118));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName("label_8");

        verticalLayout_3->addWidget(label_8);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName("label_9");

        verticalLayout_3->addWidget(label_9);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName("label_7");

        verticalLayout_3->addWidget(label_7);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName("label_6");

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        eRegLineEdit = new QLineEdit(layoutWidget2);
        eRegLineEdit->setObjectName("eRegLineEdit");

        verticalLayout_4->addWidget(eRegLineEdit);

        userRegLineEdit = new QLineEdit(layoutWidget2);
        userRegLineEdit->setObjectName("userRegLineEdit");

        verticalLayout_4->addWidget(userRegLineEdit);

        pasRegLineEdit = new QLineEdit(layoutWidget2);
        pasRegLineEdit->setObjectName("pasRegLineEdit");

        verticalLayout_4->addWidget(pasRegLineEdit);

        pas2RegLineEdit = new QLineEdit(layoutWidget2);
        pas2RegLineEdit->setObjectName("pas2RegLineEdit");

        verticalLayout_4->addWidget(pas2RegLineEdit);


        horizontalLayout_3->addLayout(verticalLayout_4);

        crAcButton = new QPushButton(registerTab);
        crAcButton->setObjectName("crAcButton");
        crAcButton->setGeometry(QRect(10, 150, 101, 24));
        AccountTabWidget->addTab(registerTab, QString());
        registerTab_2 = new QWidget();
        registerTab_2->setObjectName("registerTab_2");
        sentMButton = new QPushButton(registerTab_2);
        sentMButton->setObjectName("sentMButton");
        sentMButton->setGeometry(QRect(10, 60, 80, 24));
        layoutWidget3 = new QWidget(registerTab_2);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 20, 341, 26));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        lineEdit_7 = new QLineEdit(layoutWidget3);
        lineEdit_7->setObjectName("lineEdit_7");

        horizontalLayout_4->addWidget(lineEdit_7);

        AccountTabWidget->addTab(registerTab_2, QString());

        retranslateUi(loginWindow);

        AccountTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QWidget *loginWindow)
    {
        loginWindow->setWindowTitle(QCoreApplication::translate("loginWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("loginWindow", "Welcome back!", nullptr));
        label_2->setText(QCoreApplication::translate("loginWindow", "Email:", nullptr));
        label_3->setText(QCoreApplication::translate("loginWindow", "Password:", nullptr));
        logButton->setText(QCoreApplication::translate("loginWindow", "Login", nullptr));
        regButton->setText(QCoreApplication::translate("loginWindow", "Register", nullptr));
        helpButton->setText(QCoreApplication::translate("loginWindow", "Help", nullptr));
        AccountTabWidget->setTabText(AccountTabWidget->indexOf(loginTab), QCoreApplication::translate("loginWindow", "Login", nullptr));
        label_8->setText(QCoreApplication::translate("loginWindow", "Email", nullptr));
        label_9->setText(QCoreApplication::translate("loginWindow", "Username", nullptr));
        label_7->setText(QCoreApplication::translate("loginWindow", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("loginWindow", "Reentere password", nullptr));
        crAcButton->setText(QCoreApplication::translate("loginWindow", "Create account", nullptr));
        AccountTabWidget->setTabText(AccountTabWidget->indexOf(registerTab), QCoreApplication::translate("loginWindow", "Register", nullptr));
        sentMButton->setText(QCoreApplication::translate("loginWindow", "Sent Email", nullptr));
        label_4->setText(QCoreApplication::translate("loginWindow", "Email", nullptr));
        AccountTabWidget->setTabText(AccountTabWidget->indexOf(registerTab_2), QCoreApplication::translate("loginWindow", "Recover", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
