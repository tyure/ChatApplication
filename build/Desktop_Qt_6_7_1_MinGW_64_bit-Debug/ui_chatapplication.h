/********************************************************************************
** Form generated from reading UI file 'chatapplication.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATAPPLICATION_H
#define UI_CHATAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatApplication
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatApplication)
    {
        if (ChatApplication->objectName().isEmpty())
            ChatApplication->setObjectName("ChatApplication");
        ChatApplication->resize(800, 600);
        centralwidget = new QWidget(ChatApplication);
        centralwidget->setObjectName("centralwidget");
        ChatApplication->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatApplication);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ChatApplication->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatApplication);
        statusbar->setObjectName("statusbar");
        ChatApplication->setStatusBar(statusbar);

        retranslateUi(ChatApplication);

        QMetaObject::connectSlotsByName(ChatApplication);
    } // setupUi

    void retranslateUi(QMainWindow *ChatApplication)
    {
        ChatApplication->setWindowTitle(QCoreApplication::translate("ChatApplication", "ChatApplication", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatApplication: public Ui_ChatApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATAPPLICATION_H
