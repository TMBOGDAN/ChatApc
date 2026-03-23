#ifndef USER_H
#define USER_H

#include <QString>
#include <unordered_map>
#include <string>

class User {
public:
    // constructor
    User(const QString& username = "",
         int userId = 0,
         const QString& email = "",
         const QString& status = "offline");


    int getId() const;
    QString getUsername() const;
    QString getEmail() const;
    QString getStatus() const;


    void setStatus(const QString& status);

    // friend logic
    bool isFriend(User* other);
    void addFriend(const std::string& usernameToAdd);
    bool insertFriendToDB(int userId, int friendId);


private:
    int id;
    QString username;
    QString email;
    QString userStatus;

    std::unordered_map<std::string, User*> friendList;
};

User* findUserByUsername(const std::string& username);

#endif // USER_H
