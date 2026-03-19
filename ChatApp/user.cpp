#include "user.h"
#include <iostream>
//
// Constructor
//
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

//
// Getters
//
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

//
// Setter
//
void User::setStatus(const QString& status) {
    userStatus = status;
}

//
// Verificare daca deja e prieten
//
bool User::isFriend(User* other) {
    if (!other) return false;

    return friendList.find(other->getUsername().toStdString()) != friendList.end();
}

//
// Adaugare prieten
//
void User::addFriend(const std::string& usernameToAdd) {

    // evitam duplicatele
    if (friendList.find(usernameToAdd) != friendList.end())
        return;

    User* foundUser = findUserByUsername(usernameToAdd);

    if (foundUser) {
        friendList[usernameToAdd] = foundUser;

        // optional: salvare în DB
        insertFriendToDB(this->id, foundUser->getId());
    }
}

//
// Simulare insert DB (stub)
//
bool User::insertFriendToDB(int userId, int friendId) {

    // aici vei pune cod real DB mai târziu
    // momentan returnam true ca simulare

    std::cout << "Inserted friendship in DB: "
              << userId << " -> " << friendId << std::endl;

    return true;
}



//
// Global function to find user by username
//
User* findUserByUsername(const std::string& username) {
    // TODO: Implement actual user lookup from user database/storage
    // For now, returning nullptr as a placeholder
    return nullptr;
}
