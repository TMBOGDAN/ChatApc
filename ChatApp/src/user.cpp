#include "user.h"
#include <iostream>

User::User(const QString& username,
           int userId,
           const QString& email,
           const QString& status)
    : id(userId),
    username(username),
    email(email),
    userStatus(status)
{
}


int User::getId() const {
    return id;
}

QString User::getUsername() const {
    return username;
}

QString User::getEmail() const {
    return email;
}

QString User::getStatus() const {
    return userStatus;
}


void User::setStatus(const QString& status) {
    userStatus = status;
}


bool User::isFriend(User* other) {
    if (!other) return false;

    return friendList.find(other->getUsername().toStdString()) != friendList.end();
}


void User::addFriend(const std::string& usernameToAdd) {


    if (friendList.find(usernameToAdd) != friendList.end())
        return;

    User* foundUser = findUserByUsername(usernameToAdd);

    if (foundUser) {
        friendList[usernameToAdd] = foundUser;

        // optional: salvare în DB
        insertFriendToDB(this->id, foundUser->getId());
    }
}


bool User::insertFriendToDB(int userId, int friendId) {


    std::cout << "Inserted friendship in DB: "
              << userId << " -> " << friendId << std::endl;

    return true;
}

User* findUserByUsername(const std::string& username) {
    // TODO: Implement actual user lookup from user database/storage
    // For now, returning nullptr as a placeholder
    return nullptr;
}
