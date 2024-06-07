/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *chatListWidget;
    QPushButton *openChatButton;
    QPushButton *deleteChatButton;
    QPushButton *createChatButton;
    QPushButton *openFriendListButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 600);
        MainWindow->setMinimumSize(QSize(500, 600));
        MainWindow->setMaximumSize(QSize(500, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        chatListWidget = new QListWidget(centralwidget);
        chatListWidget->setObjectName("chatListWidget");
        chatListWidget->setGeometry(QRect(40, 20, 361, 421));
        openChatButton = new QPushButton(centralwidget);
        openChatButton->setObjectName("openChatButton");
        openChatButton->setGeometry(QRect(310, 450, 80, 24));
        deleteChatButton = new QPushButton(centralwidget);
        deleteChatButton->setObjectName("deleteChatButton");
        deleteChatButton->setGeometry(QRect(130, 450, 80, 24));
        createChatButton = new QPushButton(centralwidget);
        createChatButton->setObjectName("createChatButton");
        createChatButton->setGeometry(QRect(40, 450, 80, 24));
        openFriendListButton = new QPushButton(centralwidget);
        openFriendListButton->setObjectName("openFriendListButton");
        openFriendListButton->setGeometry(QRect(410, 30, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openChatButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        deleteChatButton->setText(QCoreApplication::translate("MainWindow", "Delete Chat", nullptr));
        createChatButton->setText(QCoreApplication::translate("MainWindow", "Create Chat", nullptr));
        openFriendListButton->setText(QCoreApplication::translate("MainWindow", "Friends", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
