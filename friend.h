#ifndef FRIEND_H
#define FRIEND_H

#include <QString>

class Friend {
public:
    Friend(const QString &name);

    QString getName() const;

private:
    QString name;
};

#endif // FRIEND_H
