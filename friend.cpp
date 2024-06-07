#include "friend.h"

Friend::Friend(const QString &name) : name(name) {}

QString Friend::getName() const {
    return name;
}
