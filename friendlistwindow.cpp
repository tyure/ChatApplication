#include "friendlistwindow.h"
#include "ui_friendlistwindow.h"
#include <QInputDialog>
#include <QMessageBox>

FriendListWindow::FriendListWindow(ChatClient *chatClient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendListWindow),
    chatClient(chatClient) {
    ui->setupUi(this);

    connect(ui->addFriendButton, &QPushButton::clicked, this, &FriendListWindow::addFriend);
    connect(ui->removeFriendButton, &QPushButton::clicked, this, &FriendListWindow::removeFriend);

    loadFriends();
}

FriendListWindow::~FriendListWindow() {
    delete ui;
}

void FriendListWindow::addFriend() {
    bool ok;
    QString friendName = QInputDialog::getText(this, "Add Friend", "Enter friend's name:", QLineEdit::Normal, "", &ok);
    if (ok && !friendName.isEmpty()) {

        QList<QString> registeredUsers = chatClient->getRegisteredUsers();
        if (!registeredUsers.contains(friendName)) {
            QMessageBox::warning(this, "Add Friend", "User with this name does not exist.");
            return;
        }


        for (int i = 0; i < ui->friendListWidget->count(); ++i) {
            if (ui->friendListWidget->item(i)->text() == friendName) {
                QMessageBox::warning(this, "Add Friend", "Friend with this name already exists.");
                return;
            }
        }
        ui->friendListWidget->addItem(friendName);
        chatClient->addFriend(friendName);
        saveFriends();
    }
}

void FriendListWindow::removeFriend() {
    QListWidgetItem *selectedItem = ui->friendListWidget->currentItem();
    if (selectedItem) {
        QString friendName = selectedItem->text();
        delete selectedItem;
        chatClient->removeFriend(friendName);
        saveFriends();
    } else {
        QMessageBox::warning(this, "Remove Friend", "Please select a friend to remove.");
    }
}

void FriendListWindow::loadFriends() {
    ui->friendListWidget->clear();
    chatClient->loadFriends(chatClient->getUser().getUsername());
    for (const Friend &friendObj : chatClient->getFriends()) {
        ui->friendListWidget->addItem(friendObj.getName());
    }
}

void FriendListWindow::saveFriends() {
    chatClient->saveFriends(chatClient->getUser().getUsername());
}
