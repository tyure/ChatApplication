#include "message.h"

Message::Message(const QString &sender, const QString &content, const QDateTime &timestamp, const QString &chatRoomName)
    : sender(sender), content(content), timestamp(timestamp), chatRoomName(chatRoomName) {}

QString Message::getSender() const {
    return sender;
}

QString Message::getContent() const {
    return content;
}

QDateTime Message::getTimestamp() const {
    return timestamp;
}

QString Message::getChatRoomName() const {
    return chatRoomName;
}
