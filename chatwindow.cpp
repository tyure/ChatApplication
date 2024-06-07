#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(ChatClient *client, const QString &roomName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatWindow),
    chatClient(client),
    chatRoomName(roomName) {
    ui->setupUi(this);

    connect(ui->sendMessageButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
    connect(chatClient, &ChatClient::messageReceived, this, &ChatWindow::receiveMessage);

    loadChatHistory();
}

ChatWindow::~ChatWindow() {
    delete ui;
}

void ChatWindow::sendMessage() {
    QString content = ui->messageInput->text();
    if (!content.isEmpty()) {
        chatClient->sendMessage(chatRoomName, content);
        ui->messageInput->clear();
    }
}

void ChatWindow::receiveMessage(const Message &message) {
    if (message.getChatRoomName() == chatRoomName) {
        ui->messageListWidget->addItem(message.getSender() + ": " + message.getContent());
    }
}

void ChatWindow::loadChatHistory() {
    ui->messageListWidget->clear();
    for (const ChatRoom &room : chatClient->getChatRooms()) {
        if (room.getName() == chatRoomName) {
            for (const Message &message : room.getMessages()) {
                ui->messageListWidget->addItem(message.getSender() + ": " + message.getContent());
            }
            break;
        }
    }
}
