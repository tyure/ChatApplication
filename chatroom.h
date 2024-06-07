#ifndef CHATROOM_H
#define CHATROOM_H

#include <QString>
#include <QList>
#include "message.h"

class ChatRoom {
public:
    explicit ChatRoom(const QString &name);
    QString getName() const;
    QList<Message> getMessages() const;
    void addMessage(const Message &message);
    void loadMessages(const QString &filename);
    void saveMessages(const QString &filename) const;
    void addParticipant(const QString &participant);
    QStringList getParticipants() const;

    bool operator==(const ChatRoom &other) const;

private:
    QString name;
    QList<Message> messages;
    QStringList participants;
};

#endif // CHATROOM_H
