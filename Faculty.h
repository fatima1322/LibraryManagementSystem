#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
using namespace std;
#include <string>
#include "User.h"

class Faculty : public User
{
private:
    string facultyID;
    string department;

public:
    Faculty(const string &, const string &, const string &, const string &,
            const string &, const string &);

    virtual void displayDetails() const override;
    virtual string getUserType() const override;

    string getFacultyID() const;
    string getDepartment() const;
};

#endif
