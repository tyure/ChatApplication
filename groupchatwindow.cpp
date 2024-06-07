#include "groupchatwindow.h"
#include "ui_groupchatwindow.h"
#include <QInputDialog>
#include <QMessageBox>

GroupChatWindow::GroupChatWindow(ChatClient *chatClient, const QString &groupName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupChatWindow),
    chatClient(chatClient),
    groupName(groupName)
{
    ui->setupUi(this);

    connect(ui->sendMessageButton, &QPushButton::clicked, this, &GroupChatWindow::sendMessage);
    connect(chatClient, &ChatClient::messageReceived, this, &GroupChatWindow::receiveMessage);
    connect(ui->addUserButton, &QPushButton::clicked, this, &GroupChatWindow::addUser);

    loadChatHistory();
}

GroupChatWindow::~GroupChatWindow() {
    delete ui;
}

void GroupChatWindow::sendMessage() {
    QString content = ui->messageInput->text();
    if (!content.isEmpty()) {
        chatClient->sendMessage(groupName, content);
        ui->messageInput->clear();
    }
}

void GroupChatWindow::receiveMessage(const Message &message) {
    if (message.getChatRoomName() == groupName) {
        ui->messageListWidget->addItem(message.getSender() + ": " + message.getContent());
    }
}

void GroupChatWindow::loadChatHistory() {
    ui->messageListWidget->clear();
    for (const ChatRoom &room : chatClient->getChatRooms()) {
        if (room.getName() == groupName) {
            for (const Message &message : room.getMessages()) {
                ui->messageListWidget->addItem(message.getSender() + ": " + message.getContent());
            }
            break;
        }
    }
}

void GroupChatWindow::addUser() {
    bool ok;
    QString newUser = QInputDialog::getText(this, "Add User", "Enter user's name:", QLineEdit::Normal, "", &ok);
    if (ok && !newUser.isEmpty()) {
        bool alreadyExists = false;
        for (const Friend &friendObj : chatClient->getFriends()) {
            if (friendObj.getName() == newUser) {
                alreadyExists = true;
                break;
            }
        }
        if (!alreadyExists) {
            chatClient->addUserToGroup(groupName, newUser);
        } else {
            QMessageBox::warning(this, "Add User", "This user is already in the group.");
        }
    }
}
