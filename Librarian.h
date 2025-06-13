#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <iostream>
using namespace std;
#include <string>
#include "User.h"

class Librarian : public User
{
private:
    string staffID;
    string role;
    Library* library = nullptr; // pointer to the central system

public:
    Librarian(const string &, const string &, const string &, const string &,
              const string &, const string &);

    virtual void displayDetails() const override;
    virtual string getUserType() const override;
    string getStaffID() const;
    string getRole() const;

    // Librarian-specific methods
    void manageUsers() const;
    void manageResources() const;
    bool isAdministrator() const;
};

#endif
