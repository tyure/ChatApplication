/********************************************************************************
** Form generated from reading UI file 'groupchatdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATDIALOG_H
#define UI_GROUPCHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupChatDialog
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout_2;
    QPushButton *addUserButton;
    QPushButton *removeUserButton;
    QWidget *widget;
    QFormLayout *formLayout;
    QListWidget *selectedUserListWidget;
    QListWidget *userListWidget;
    QPushButton *saveButton;
    QLabel *groupNameLabel;
    QLineEdit *groupNameEdit;

    void setupUi(QDialog *GroupChatDialog)
    {
        if (GroupChatDialog->objectName().isEmpty())
            GroupChatDialog->setObjectName("GroupChatDialog");
        GroupChatDialog->resize(573, 659);
        layoutWidget = new QWidget(GroupChatDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(350, 610, 168, 26));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        addUserButton = new QPushButton(layoutWidget);
        addUserButton->setObjectName("addUserButton");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, addUserButton);

        removeUserButton = new QPushButton(layoutWidget);
        removeUserButton->setObjectName("removeUserButton");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, removeUserButton);

        widget = new QWidget(GroupChatDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 100, 519, 429));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        selectedUserListWidget = new QListWidget(widget);
        selectedUserListWidget->setObjectName("selectedUserListWidget");

        formLayout->setWidget(0, QFormLayout::FieldRole, selectedUserListWidget);

        userListWidget = new QListWidget(widget);
        userListWidget->setObjectName("userListWidget");

        formLayout->setWidget(0, QFormLayout::LabelRole, userListWidget);

        saveButton = new QPushButton(GroupChatDialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(460, 20, 80, 24));
        groupNameLabel = new QLabel(GroupChatDialog);
        groupNameLabel->setObjectName("groupNameLabel");
        groupNameLabel->setGeometry(QRect(40, 60, 41, 21));
        groupNameEdit = new QLineEdit(GroupChatDialog);
        groupNameEdit->setObjectName("groupNameEdit");
        groupNameEdit->setGeometry(QRect(80, 60, 191, 24));

        retranslateUi(GroupChatDialog);

        QMetaObject::connectSlotsByName(GroupChatDialog);
    } // setupUi

    void retranslateUi(QDialog *GroupChatDialog)
    {
        GroupChatDialog->setWindowTitle(QCoreApplication::translate("GroupChatDialog", "Dialog", nullptr));
        addUserButton->setText(QCoreApplication::translate("GroupChatDialog", "Add", nullptr));
        removeUserButton->setText(QCoreApplication::translate("GroupChatDialog", "Remove", nullptr));
        saveButton->setText(QCoreApplication::translate("GroupChatDialog", "Save", nullptr));
        groupNameLabel->setText(QCoreApplication::translate("GroupChatDialog", "Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupChatDialog: public Ui_GroupChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATDIALOG_H
