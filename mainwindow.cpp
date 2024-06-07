#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), chatClient(new ChatClient(this)) {
    ui->setupUi(this);

    registerForm = new RegisterForm(this);
    connect(registerForm, &RegisterForm::registrationSuccessful, this, &MainWindow::onRegistrationSuccessful);
    connect(registerForm, &RegisterForm::loginSuccessful, this, &MainWindow::onLoginSuccessful);

    connect(ui->openChatButton, &QPushButton::clicked, this, &MainWindow::openChat);
    connect(ui->createChatButton, &QPushButton::clicked, this, &MainWindow::createChat);
    connect(ui->deleteChatButton, &QPushButton::clicked, this, &MainWindow::deleteChat);
    connect(ui->openFriendListButton, &QPushButton::clicked, this, &MainWindow::openFriendList);

    friendListWindow = nullptr;

    showRegistrationForm();
}

MainWindow::~MainWindow() {
    delete ui;
    delete registerForm;
    delete chatClient;
    if (friendListWindow != nullptr) {
        delete friendListWindow;
    }
    qDeleteAll(openChatWindows);
    qDeleteAll(openGroupChatWindows);
}

void MainWindow::showRegistrationForm() {
    registerForm->exec();
}

void MainWindow::onRegistrationSuccessful(const QString &username) {
    currentUsername = username;
    chatClient->setUser(User(username));
    loadChats();
}

void MainWindow::onLoginSuccessful(const QString &username) {
    currentUsername = username;
    chatClient->setUser(User(username));
    loadChats();
}

void MainWindow::openChat() {
    QListWidgetItem *selectedItem = ui->chatListWidget->currentItem();
    if (selectedItem) {
        QString chatName = selectedItem->text();
        if (chatName.contains("group_")) {
            GroupChatWindow *groupChatWindow = new GroupChatWindow(chatClient, chatName);
            openGroupChatWindows.append(groupChatWindow);
            groupChatWindow->show();
        } else {
            ChatWindow *chatWindow = new ChatWindow(chatClient, chatName);
            openChatWindows.append(chatWindow);
            chatWindow->show();
        }
    } else {
        QMessageBox::warning(this, "Open Chat", "Please select a chat to open.");
    }
}

void MainWindow::createChat() {
    bool ok;
    QStringList chatTypes = {"Chat", "Group Chat"};
    QString chatType = QInputDialog::getItem(this, "Create Chat", "Select chat type:", chatTypes, 0, false, &ok);
    if (ok && !chatType.isEmpty()) {
        if (chatType == "Chat") {
            // Створення звичайного чату
            QString friendName = QInputDialog::getText(this, "Create Chat", "Enter friend's name:", QLineEdit::Normal, "", &ok);
            if (ok && !friendName.isEmpty()) {
                bool friendExists = false;
                for (const Friend &friendObj : chatClient->getFriends()) {
                    if (friendObj.getName() == friendName) {
                        friendExists = true;
                        break;
                    }
                }
                if (!friendExists) {
                    QMessageBox::warning(this, "Create Chat", "Friend with this name does not exist.");
                    return;
                }

                QString chatName = chatClient->generateChatFilename(friendName);
                ui->chatListWidget->addItem(chatName);
                chatClient->createChat(friendName);
                chatClient->saveChatRooms();
            }
        } else if (chatType == "Group Chat") {

            createGroupChat();
        }
    }
}

void MainWindow::createGroupChat() {
    GroupChatDialog dialog(chatClient, this);
    if (dialog.exec() == QDialog::Accepted) {
        QStringList selectedUsers = dialog.getSelectedUsers();
        QString groupName = dialog.getGroupName();
        if (!selectedUsers.isEmpty() && !groupName.isEmpty()) {
            groupName = "group_" + groupName;

            ui->chatListWidget->addItem(groupName);
            chatClient->createGroupChat(groupName, selectedUsers, currentUsername);
            chatClient->saveChatRooms();
        }
    }
}

void MainWindow::deleteChat() {
    QListWidgetItem *selectedItem = ui->chatListWidget->currentItem();
    if (selectedItem) {
        QString chatName = selectedItem->text();
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Delete Chat", "Are you sure you want to delete this chat?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            chatClient->deleteChat(chatName);
            delete selectedItem;
            saveChats();
        }
    } else {
        QMessageBox::warning(this, "Delete Chat", "Please select a chat to delete.");
    }
}

void MainWindow::openFriendList() {
    if (friendListWindow == nullptr) {
        friendListWindow = new FriendListWindow(chatClient, this);
    }
    friendListWindow->show();
    friendListWindow->raise();
    friendListWindow->activateWindow();
}

void MainWindow::loadChats() {
    ui->chatListWidget->clear();
    chatClient->loadChatRooms();
    for (const ChatRoom &room : chatClient->getChatRooms()) {
        ui->chatListWidget->addItem(room.getName());
    }
}

void MainWindow::saveChats() {
    chatClient->saveChatRooms();
}
