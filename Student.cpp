#include "Student.h"
#include <iostream>
using namespace std;
#include <string>

Student::Student(const string &uID, const string &n, const string &em, const string &passwd,
                 const string &sID, const string &m)
    : User(uID, n, em, passwd), studentID(sID), major(m)
{
    if (studentID.empty())
        throw std::invalid_argument("Student ID cannot be empty.");

    if (major.empty())
        throw std::invalid_argument("Major cannot be empty.");
}

void Student::displayDetails() const
{
    cout << "=== STUDENT DETAILS ===" << std::endl;
    cout << "User ID: " << userID << std::endl;
    cout << "Name: " << name << std::endl;
    cout << "Email: " << email << std::endl;
    cout << "Student ID: " << studentID << std::endl;
    cout << "Major: " << major << std::endl;
    cout << "======================" << std::endl;
}
string Student::getStudentID() const { return studentID; }
string Student::getMajor() const { return major; }
string Student::getUserType() const
{
    return "Student";
}
