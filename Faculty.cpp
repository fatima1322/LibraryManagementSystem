#include <iostream>
using namespace std;
#include <string>
#include "Faculty.h"

Faculty::Faculty(const string &uID, const string &n, const string &e, const string &passwd,
                 const string &fID, const string &d)
    : User(uID, n, e, passwd), facultyID(fID), department(d)
{
    if (facultyID.empty())
        throw std::invalid_argument("Faculty ID cannot be empty.");
    if (department.empty())
        throw std::invalid_argument("Department cannot be empty.");
}

void Faculty::displayDetails() const
{
    cout << "=== FACULTY DETAILS ===" << std::endl;
    cout << "User ID: " << userID << std::endl;
    cout << "Name: " << name << std::endl;
    cout << "Email: " << email << std::endl;
    cout << "Faculty ID: " << facultyID << std::endl;
    cout << "Department: " << department << std::endl;
    cout << "=======================" << std::endl;
}

string Faculty::getUserType() const
{
    return "Faculty";
}

string Faculty::getFacultyID() const { return facultyID; }
string Faculty::getDepartment() const { return department; }
