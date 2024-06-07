#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QList>
#include "chatroom.h"
#include "friend.h"
#include "user.h"

class ChatClient : public QObject
{
    Q_OBJECT
public:
    explicit ChatClient(QObject *parent = nullptr);
    void setUser(const User &user);
    User getUser() const;
    void createChat(const QString &friendName);
    void createGroupChat(const QString &groupName, const QStringList &users, const QString &creator);
    void sendMessage(const QString &roomName, const QString &content);
    void sendGroupChatMessage(const QString &roomName, const QString &content); // Новий метод для групових чатів
    void deleteChat(const QString &roomName);
    QList<ChatRoom> getChatRooms() const;
    void saveChatRooms() const;
    void loadChatRooms();
    void addFriend(const QString &friendName);
    void removeFriend(const QString &friendName);
    QList<Friend> getFriends() const;
    void saveFriends(const QString &username) const;
    void loadFriends(const QString &username);
    QList<QString> getRegisteredUsers() const;
    void loadRegisteredUsers();
    void createUserFiles() const;
    QString generateChatFilename(const QString &friendName) const;
    void saveChatToFile(const QString &roomName) const;
    void loadChatFromFile(const QString &roomName);
    void appendChatToUserChatRooms(const QString &username, const QString &roomName) const;
    void removeChatFromUserChatRooms(const QString &username, const QString &roomName) const;
    void addUserToGroup(const QString &groupName, const QString &username);

signals:
    void messageReceived(const Message &message);

private:
    User user;
    QList<ChatRoom> chatRooms;
    QList<Friend> friends;
    QList<QString> registeredUsers;

    void createGroupChatFiles(const QString &username, const QString &groupName, const QStringList &users) const;
};

#endif // CHATCLIENT_H
