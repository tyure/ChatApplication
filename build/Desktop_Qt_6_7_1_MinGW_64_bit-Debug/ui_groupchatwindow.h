/********************************************************************************
** Form generated from reading UI file 'groupchatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATWINDOW_H
#define UI_GROUPCHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GroupChatWindow
{
public:
    QListWidget *messageListWidget;
    QLineEdit *messageInput;
    QPushButton *sendMessageButton;
    QPushButton *addUserButton;

    void setupUi(QDialog *GroupChatWindow)
    {
        if (GroupChatWindow->objectName().isEmpty())
            GroupChatWindow->setObjectName("GroupChatWindow");
        GroupChatWindow->resize(400, 520);
        GroupChatWindow->setMinimumSize(QSize(400, 520));
        GroupChatWindow->setMaximumSize(QSize(400, 520));
        messageListWidget = new QListWidget(GroupChatWindow);
        messageListWidget->setObjectName("messageListWidget");
        messageListWidget->setGeometry(QRect(1, 1, 398, 450));
        messageInput = new QLineEdit(GroupChatWindow);
        messageInput->setObjectName("messageInput");
        messageInput->setGeometry(QRect(0, 450, 301, 24));
        sendMessageButton = new QPushButton(GroupChatWindow);
        sendMessageButton->setObjectName("sendMessageButton");
        sendMessageButton->setGeometry(QRect(310, 450, 80, 24));
        addUserButton = new QPushButton(GroupChatWindow);
        addUserButton->setObjectName("addUserButton");
        addUserButton->setGeometry(QRect(360, 480, 21, 21));

        retranslateUi(GroupChatWindow);

        QMetaObject::connectSlotsByName(GroupChatWindow);
    } // setupUi

    void retranslateUi(QDialog *GroupChatWindow)
    {
        GroupChatWindow->setWindowTitle(QCoreApplication::translate("GroupChatWindow", "Dialog", nullptr));
        sendMessageButton->setText(QCoreApplication::translate("GroupChatWindow", "Send", nullptr));
        addUserButton->setText(QCoreApplication::translate("GroupChatWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupChatWindow: public Ui_GroupChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATWINDOW_H
