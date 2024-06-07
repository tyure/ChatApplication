#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QDateTime>

class Message {
public:
    Message(const QString &sender, const QString &content, const QDateTime &timestamp, const QString &chatRoomName);

    QString getSender() const;
    QString getContent() const;
    QDateTime getTimestamp() const;
    QString getChatRoomName() const;

private:
    QString sender;
    QString content;
    QDateTime timestamp;
    QString chatRoomName;
};

#endif // MESSAGE_H
