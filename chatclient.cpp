#include "chatclient.h"
#include "message.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

ChatClient::ChatClient(QObject *parent)
    : QObject(parent) {
    loadRegisteredUsers();
}

void ChatClient::setUser(const User &user) {
    this->user = user;
    createUserFiles();
}

User ChatClient::getUser() const {
    return user;
}

void ChatClient::createChat(const QString &friendName) {
    QString roomName = generateChatFilename(friendName);
    chatRooms.append(ChatRoom(roomName));


    QStringList participants = roomName.split("_");
    if (participants.size() == 2) {
        QString user1 = participants[0];
        QString user2 = participants[1];

        QDir dir1("users/" + user1);
        QDir dir2("users/" + user2);

        QFile file1(dir1.filePath(roomName + ".txt"));
        QFile file2(dir2.filePath(roomName + ".txt"));

        if (!file1.exists()) {
            file1.open(QIODevice::WriteOnly);
            file1.close();
        }

        if (!file2.exists()) {
            file2.open(QIODevice::WriteOnly);
            file2.close();
        }


        appendChatToUserChatRooms(user1, roomName);
        appendChatToUserChatRooms(user2, roomName);
    }
}

void ChatClient::createGroupChat(const QString &groupName, const QStringList &users, const QString &creator) {
    chatRooms.append(ChatRoom(groupName));
    for (const QString &user : users) {
        createGroupChatFiles(user, groupName, users);
        appendChatToUserChatRooms(user, groupName);
    }
    createGroupChatFiles(creator, groupName, users);
    appendChatToUserChatRooms(creator, groupName);
    saveChatToFile(groupName);
}

void ChatClient::createGroupChatFiles(const QString &username, const QString &groupName, const QStringList &users) const {
    QDir dir("users/" + username + "/" + groupName);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QFile participantsFile(dir.filePath("participants.txt"));
    if (participantsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&participantsFile);
        for (const QString &user : users) {
            out << user << "\n";
        }
        if (!users.contains(username)) {
            out << username << "\n";
        }
        participantsFile.close();
    }

    QFile messagesFile(dir.filePath("messages.txt"));
    if (!messagesFile.exists()) {
        messagesFile.open(QIODevice::WriteOnly);
        messagesFile.close();
    }
}

void ChatClient::sendMessage(const QString &roomName, const QString &content) {
    QDateTime timestamp = QDateTime::currentDateTime();
    Message message(user.getUsername(), content, timestamp, roomName);
    qDebug() << "Sending message to room:" << roomName;
    for (ChatRoom &room : chatRooms) {
        if (room.getName() == roomName) {
            room.addMessage(message);
            qDebug() << "Message added to room:" << roomName;


            if (roomName.startsWith("group_")) {
                sendGroupChatMessage(roomName, content);
            } else {

            }
        }
    }
    emit messageReceived(message);
}

void ChatClient::sendGroupChatMessage(const QString &roomName, const QString &content) {
    QDateTime timestamp = QDateTime::currentDateTime();
    Message message(user.getUsername(), content, timestamp, roomName);
    qDebug() << "Sending group chat message to room:" << roomName;


    QStringList participants;
    QFile participantsFile("users/" + user.getUsername() + "/" + roomName + "/participants.txt");
    if (participantsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&participantsFile);
        while (!in.atEnd()) {
            participants.append(in.readLine().trimmed());
        }
        participantsFile.close();
    } else {
        qDebug() << "Failed to open participants file for room:" << roomName;
        return;
    }

    qDebug() << "Participants in group chat:" << participants;

    foreach (const QString &participant, participants) {
        QString dirPath = "users/" + participant + "/" + roomName;
        QDir dir(dirPath);
        if (!dir.exists()) {
            qDebug() << "Directory does not exist, creating:" << dirPath;
            if (!dir.mkpath(".")) {
                qDebug() << "Failed to create directory:" << dirPath;
                continue;
            }
        }

        QString filePath = dir.filePath("messages.txt");
        QFile file(filePath);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << message.getSender() << ": " << message.getContent() << "\n";
            file.close();
            qDebug() << "Group chat message saved to file for participant:" << participant << "at" << filePath;
        } else {
            qDebug() << "Failed to open file for participant:" << participant << "at" << filePath;
        }
    }
}

void ChatClient::deleteChat(const QString &roomName) {
    QStringList participants = roomName.split("_");
    if (participants.size() == 2) {
        QString user1 = participants[0];
        QString user2 = participants[1];

        QDir dir1("users/" + user1);
        QDir dir2("users/" + user2);

        QFile file1(dir1.filePath(roomName + ".txt"));
        QFile file2(dir2.filePath(roomName + ".txt"));

        if (file1.exists()) {
            file1.remove();
        }

        if (file2.exists()) {
            file2.remove();
        }


        removeChatFromUserChatRooms(user1, roomName);
        removeChatFromUserChatRooms(user2, roomName);

        QString content = "Собеседник покинул чат";
        sendMessage(roomName, content);
    }


    for (int i = 0; i < chatRooms.size(); ++i) {
        if (chatRooms[i].getName() == roomName) {
            chatRooms.removeAt(i);
            break;
        }
    }
}

QList<ChatRoom> ChatClient::getChatRooms() const {
    return chatRooms;
}

void ChatClient::saveChatRooms() const {
    QDir dir("users/" + user.getUsername());
    QFile file(dir.filePath("chatrooms.txt"));
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const ChatRoom &room : chatRooms) {
            out << room.getName() << "\n";
        }
        file.close();
    }
}

void ChatClient::loadChatRooms() {
    chatRooms.clear();
    QFile file("users/" + user.getUsername() + "/chatrooms.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString roomName = in.readLine();
            ChatRoom chatRoom(roomName);
            chatRooms.append(chatRoom);
            loadChatFromFile(roomName);
        }
        file.close();
    }
}

void ChatClient::addFriend(const QString &friendName) {
    for (const Friend &friendObj : friends) {
        if (friendObj.getName() == friendName) {
            return;
        }
    }


    if (!registeredUsers.contains(friendName)) {
        qDebug() << "User with this name does not exist.";
        return;
    }

    friends.append(Friend(friendName));


    QDir dir("users/" + friendName);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    QFile file(dir.filePath("friends.txt"));
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << user.getUsername() << "\n";
        file.close();
    }


    saveFriends(user.getUsername());
}

void ChatClient::removeFriend(const QString &friendName) {
    for (int i = 0; i < friends.size(); ++i) {
        if (friends[i].getName() == friendName) {
            friends.removeAt(i);
            break;
        }
    }


    QDir dir("users/" + friendName);
    if (dir.exists()) {
        QFile file(dir.filePath("friends.txt"));
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QString content;
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                if (line != user.getUsername()) {
                    content += line + "\n";
                }
            }
            file.resize(0);
            QTextStream out(&file);
            out << content;
            file.close();
        }
    }


    saveFriends(user.getUsername());
}

QList<Friend> ChatClient::getFriends() const {
    return friends;
}

void ChatClient::saveFriends(const QString &username) const {
    QDir dir("users/" + username);
    QFile file(dir.filePath("friends.txt"));
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const Friend &friendObj : friends) {
            out << friendObj.getName() << "\n";
        }
        file.close();
    }
}

void ChatClient::loadFriends(const QString &username) {
    friends.clear();
    QFile file("users/" + username + "/friends.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString friendName = in.readLine();
            friends.append(Friend(friendName));
        }
        file.close();
    }
}

QList<QString> ChatClient::getRegisteredUsers() const {
    return registeredUsers;
}

void ChatClient::loadRegisteredUsers() {
    registeredUsers.clear();
    QFile file("users/registered_users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString username = in.readLine();
            registeredUsers.append(username);
        }
        file.close();
    }
}

QString ChatClient::generateChatFilename(const QString &friendName) const {
    QString username1 = user.getUsername();
    QString username2 = friendName;
    if (username1 < username2) {
        return username1 + "_" + username2;
    } else {
        return username2 + "_" + username1;
    }
}

void ChatClient::saveChatToFile(const QString &roomName) const {
    for (const ChatRoom &room : chatRooms) {
        if (room.getName() == roomName) {
            QStringList participants = room.getParticipants();
            foreach (const QString &participant, participants) {
                QDir dir("users/" + participant + "/" + roomName);
                QFile file(dir.filePath("messages.txt"));
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);
                    for (const Message &message : room.getMessages()) {
                        out << message.getSender() << ": " << message.getContent() << "\n";
                    }
                    file.close();
                }
            }
        }
    }
}

void ChatClient::loadChatFromFile(const QString &roomName) {
    QString chatFilename = "users/" + user.getUsername() + "/" + roomName + "/messages.txt";

    QFile file(chatFilename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList messageData = line.split(":", Qt::SkipEmptyParts);
            if (messageData.size() >= 2) {
                QString sender = messageData[0].trimmed();
                QString content = line.section(':', 1).trimmed();
                QDateTime timestamp = QDateTime::currentDateTime();
                Message message(sender, content, timestamp, roomName);
                for (ChatRoom &room : chatRooms) {
                    if (room.getName() == roomName) {
                        room.addMessage(message);
                    }
                }
            }
        }
        file.close();
        qDebug() << "Chat loaded from file:" << chatFilename;
    } else {
        qDebug() << "Failed to load chat from file:" << chatFilename;
    }
}

void ChatClient::createUserFiles() const {
    QDir dir("users/" + user.getUsername());
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QFile chatroomsFile(dir.filePath("chatrooms.txt"));
    if (!chatroomsFile.exists()) {
        chatroomsFile.open(QIODevice::WriteOnly);
        chatroomsFile.close();
    }

    QFile friendsFile(dir.filePath("friends.txt"));
    if (!friendsFile.exists()) {
        friendsFile.open(QIODevice::WriteOnly);
        friendsFile.close();
    }
}

void ChatClient::appendChatToUserChatRooms(const QString &username, const QString &roomName) const {
    QDir dir("users/" + username);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    QFile file(dir.filePath("chatrooms.txt"));
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << roomName << "\n";
        file.close();
    }
}

void ChatClient::removeChatFromUserChatRooms(const QString &username, const QString &roomName) const {
    QDir dir("users/" + username);
    QFile file(dir.filePath("chatrooms.txt"));
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QString content;
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line != roomName) {
                content += line + "\n";
            }
        }
        file.resize(0);
        QTextStream out(&file);
        out << content;
        file.close();
    }


    QFile chatFile(dir.filePath(roomName + ".txt"));
    if (chatFile.exists()) {
        chatFile.remove();
    }
}

void ChatClient::addUserToGroup(const QString &groupName, const QString &username) {

    QStringList participants;
    foreach (const ChatRoom &room, chatRooms) {
        if (room.getName() == groupName) {
            participants = room.getParticipants();
            break;
        }
    }


    foreach (const QString &participant, participants) {
        QDir dir("users/" + participant + "/" + groupName);
        QFile participantsFile(dir.filePath("participants.txt"));
        if (participantsFile.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&participantsFile);
            out << username << "\n";
            participantsFile.close();
        }
    }


    createGroupChatFiles(username, groupName, participants);


    appendChatToUserChatRooms(username, groupName);


    saveChatToFile(groupName);
}
