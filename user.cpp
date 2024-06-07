#include "user.h"

User::User() : username("") {}

User::User(const QString &username) : username(username) {}

QString User::getUsername() const {
    return username;
}
