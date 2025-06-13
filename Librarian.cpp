#include "Librarian.h"
#include <iostream>
using namespace std;
#include <string>

Librarian::Librarian(const string &uID, const string &n, const string &em, const string &passwd,
                     const string &sID, const string &r)
    : User(uID, n, em, passwd), staffID(sID), role(r)
{
    if (staffID.empty())
        throw std::invalid_argument("Staff ID cannot be empty.");

    // Optional: only allow "Administrator" or "Employee"
    if (role != "Administrator" && role != "Employee")
    {
        throw std::invalid_argument("Role must be 'Administrator' or 'Employee'.");
    }
}

void Librarian::displayDetails() const
{
    cout << "=== LIBRARIAN DETAILS ===" << std::endl;
    cout << "User ID: " << userID << std::endl;
    cout << "Name: " << name << std::endl;
    cout << "Email: " << email << std::endl;
    cout << "Staff ID: " << staffID << std::endl;
    cout << "Role: " << role << std::endl;
    cout << "=========================" << std::endl;
}

std::string Librarian::getUserType() const
{
    return "Librarian";
}

string Librarian::getStaffID() const { return staffID; }
string Librarian::getRole() const { return role; }

void Librarian::manageUsers() const
{
    if (!library) {
        std::cerr << "Error: Library system not connected.\n";
        return;
    }

    if (!isAdministrator()) {
        std::cout << "Access Denied: Only administrators can manage users.\n";
        return;
    }

    int choice;
    do {
        std::cout << "\n=== USER MANAGEMENT ===\n"
                  << "1. Add User\n"
                  << "2. Remove User\n"
                  << "3. List Users\n"
                  << "0. Back\n"
                  << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                library->addUser(); break;
            case 2:
                library->removeUser(); break;
            case 3:
                library->listUsers(); break;
            case 0:
                std::cout << "Returning to main menu.\n"; break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 0);

}

void Librarian::manageResources() const {
    if (!library) {
        std::cerr << "Error: Library system not connected.\n";
        return;
    }

    int choice;
    do {
        std::cout << "\n=== RESOURCE MANAGEMENT ===\n"
                  << "1. Add Resource\n"
                  << "2. Remove Resource\n"
                  << "3. Edit Resource\n"
                  << "4. List Resources\n"
                  << "0. Back\n"
                  << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
            case 2:
            case 3:
                if (!isAdministrator()) {
                    std::cout << "Access Denied: Only administrators can add/remove/edit resources.\n";
                } else {
                    if (choice == 1) library->addResource();
                    else if (choice == 2) library->removeResource();
                    else if (choice == 3) library->editResource();
                }
                break;
            case 4:
                library->listResources(); // Open to all librarians
                break;
            case 0:
                std::cout << "Returning to main menu.\n"; break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 0);
}


bool Librarian::isAdministrator() const
{
    return role == "Administrator";
}