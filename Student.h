#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;
#include <string>
#include "User.h"

class Student : public User
{
private:
    string studentID;
    string major;

public:
    Student(const string &, const string &, const string &, const string &,
            const string &, const string &);

    virtual void displayDetails() const override;
    virtual string getUserType() const override;

    string getStudentID() const;
    string getMajor() const;
};

#endif
