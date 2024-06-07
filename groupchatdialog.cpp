#include "groupchatdialog.h"
#include "ui_groupchatdialog.h"
#include <QInputDialog>
#include <QMessageBox>

GroupChatDialog::GroupChatDialog(ChatClient *chatClient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupChatDialog),
    chatClient(chatClient)
{
    ui->setupUi(this);


    for (const Friend &friendObj : chatClient->getFriends()) {
        QListWidgetItem *item = new QListWidgetItem(friendObj.getName());
        ui->userListWidget->addItem(item);
    }

    connect(ui->saveButton, &QPushButton::clicked, this, &GroupChatDialog::on_saveButton_clicked);
}

GroupChatDialog::~GroupChatDialog()
{
    delete ui;
}

QStringList GroupChatDialog::getSelectedUsers() const
{
    QStringList selectedUsers;
    for (int i = 0; i < ui->selectedUserListWidget->count(); ++i) {
        QListWidgetItem *item = ui->selectedUserListWidget->item(i);
        selectedUsers.append(item->text());
    }
    return selectedUsers;
}

QString GroupChatDialog::getGroupName() const {
    return ui->groupNameEdit->text();
}

void GroupChatDialog::on_addUserButton_clicked()
{
    QListWidgetItem *selectedItem = ui->userListWidget->currentItem();
    if (selectedItem) {
        bool alreadyExists = false;
        for (int i = 0; i < ui->selectedUserListWidget->count(); ++i) {
            if (ui->selectedUserListWidget->item(i)->text() == selectedItem->text()) {
                alreadyExists = true;
                break;
            }
        }
        if (!alreadyExists) {
            QListWidgetItem *newItem = new QListWidgetItem(selectedItem->text());
            ui->selectedUserListWidget->addItem(newItem);
            delete selectedItem;
        }
    }
}

void GroupChatDialog::on_removeUserButton_clicked()
{
    QListWidgetItem *selectedItem = ui->selectedUserListWidget->currentItem();
    if (selectedItem) {
        QListWidgetItem *newItem = new QListWidgetItem(selectedItem->text());
        ui->userListWidget->addItem(newItem);
        delete selectedItem;
    }
}

void GroupChatDialog::on_saveButton_clicked()
{
    if (ui->groupNameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Save Group Chat", "Please enter a group name.");
    } else {
        accept();
    }
}
