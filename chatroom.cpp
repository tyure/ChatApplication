#include "chatroom.h"
#include <QFile>
#include <QTextStream>

ChatRoom::ChatRoom(const QString &name) : name(name) {}

QString ChatRoom::getName() const {
    return name;
}

QList<Message> ChatRoom::getMessages() const {
    return messages;
}

void ChatRoom::addMessage(const Message &message) {
    messages.append(message);
}

void ChatRoom::loadMessages(const QString &filename) {
    messages.clear();
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split("|");
            if (parts.size() == 3) {
                messages.append(Message(parts[0], parts[1], QDateTime::fromString(parts[2], Qt::ISODate), name));
            }
        }
        file.close();
    }
}

void ChatRoom::saveMessages(const QString &filename) const {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const Message &message : messages) {
            out << message.getSender() << "|" << message.getContent() << "|" << message.getTimestamp().toString(Qt::ISODate) << "\n";
        }
        file.close();
    }
}

bool ChatRoom::operator==(const ChatRoom &other) const {
    return name == other.name;
}
void ChatRoom::addParticipant(const QString &participant) {
    if (!participants.contains(participant)) {
        participants.append(participant);
    }
}

QStringList ChatRoom::getParticipants() const {
    return participants;
}
