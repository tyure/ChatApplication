/********************************************************************************
** Form generated from reading UI file 'friendlistwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLISTWINDOW_H
#define UI_FRIENDLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendListWindow
{
public:
    QListWidget *friendListWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addFriendButton;
    QPushButton *removeFriendButton;

    void setupUi(QDialog *FriendListWindow)
    {
        if (FriendListWindow->objectName().isEmpty())
            FriendListWindow->setObjectName("FriendListWindow");
        FriendListWindow->resize(300, 550);
        FriendListWindow->setMinimumSize(QSize(300, 550));
        FriendListWindow->setMaximumSize(QSize(300, 550));
        friendListWidget = new QListWidget(FriendListWindow);
        friendListWidget->setObjectName("friendListWidget");
        friendListWidget->setGeometry(QRect(0, 0, 300, 500));
        widget = new QWidget(FriendListWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 510, 211, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addFriendButton = new QPushButton(widget);
        addFriendButton->setObjectName("addFriendButton");

        horizontalLayout->addWidget(addFriendButton);

        removeFriendButton = new QPushButton(widget);
        removeFriendButton->setObjectName("removeFriendButton");

        horizontalLayout->addWidget(removeFriendButton);


        retranslateUi(FriendListWindow);

        QMetaObject::connectSlotsByName(FriendListWindow);
    } // setupUi

    void retranslateUi(QDialog *FriendListWindow)
    {
        FriendListWindow->setWindowTitle(QCoreApplication::translate("FriendListWindow", "Dialog", nullptr));
        addFriendButton->setText(QCoreApplication::translate("FriendListWindow", "ADD", nullptr));
        removeFriendButton->setText(QCoreApplication::translate("FriendListWindow", "REMOVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendListWindow: public Ui_FriendListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLISTWINDOW_H
