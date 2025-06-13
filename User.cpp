#include <iostream>
using namespace std;
#include <string>
#include "User.h"
#include <regex>
#include <stdexcept>

User::User(const string &uID, const string &n, const string &em, const string &passwd)
    : userID(uID), name(n), email(em), password(passwd)
{
    if (userID.empty())
        throw std::invalid_argument("User ID cannot be empty.");

    if (name.empty())
        throw std::invalid_argument("Name cannot be empty.");

    // Basic email format check
    std::regex emailPattern(R"(^\w+([.-]?\w+)*@\w+([.-]?\w+)*(\.\w{2,3})+$)");
    if (!std::regex_match(email, emailPattern))
        throw std::invalid_argument("Invalid email format.");

    if (password.length() < 6)
        throw std::invalid_argument("Password must be at least 6 characters long.");
}

string User::getUserID() const { return userID; }
string User::getName() const { return name; }
string User::getEmail() const { return email; }

bool User::verifyPassword(const string &enteredPassword) const
{
    return password == enteredPassword;
}

void User::changePassword(const string &newPassword)
{
    password = newPassword;
}

bool User::operator==(const User &other) const
{
    return userID == other.userID;
}

ostream &operator<<(ostream &output, const User &user)
{
    output << "User ID: " << user.userID << ", Name: " << user.name
           << ", Email: " << user.email;
    return output;
}
