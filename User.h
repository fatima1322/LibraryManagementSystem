#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
#include <string>

class User
{
protected:
    string userID;
    string name;
    string email;
    string password;

public:
    User(const string &, const string &, const string &, const string &);
    virtual ~User() = default;

    virtual void displayDetails() const = 0;
    virtual string getUserType() const = 0;

    string getUserID() const;
    string getName() const;
    string getEmail() const;

    // Password management
    bool verifyPassword(const string &) const;
    void changePassword(const string &);

    // Operator overloading
    bool operator==(const User &) const;

    // Friend function
    friend ostream &operator<<(ostream &, const User &);
};

#endif
