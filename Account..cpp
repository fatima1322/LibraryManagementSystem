#include <iostream>
using namespace std;
#include <string>
#include "Account.h"
#include <iomanip>

Account::Account(const std::string &usrID)
    : userID(usrID), noBorrowedBooks(0), noReturnedBooks(0),
      noLostBooks(0), fineAmount(0.0) {}

string Account::getUserID() const
{
    return userID;
}

int Account::getBorrowedBooksCount() const
{
    return noBorrowedBooks;
}

int Account::getReturnedBooksCount() const
{
    return noReturnedBooks;
}

int Account::getLostBooksCount() const
{
    return noLostBooks;
}

double Account::getFineAmount() const
{
    return fineAmount;
}

// Modifiers
void Account::incrementBorrowedBooks()
{
    ++noBorrowedBooks;
}

void Account::decrementBorrowedBooks()
{
    if (noBorrowedBooks > 0)
    {
        --noBorrowedBooks;
    }
    else
    {
        std::cerr << "[Warning] Attempted to decrement borrowed books below zero.\n";
    }
}

void Account::incrementReturnedBooks()
{
    ++noReturnedBooks;
}

void Account::incrementLostBooks()
{
    ++noLostBooks;
    decrementBorrowedBooks(); // centralize logic
}

void Account::addFine(double amount)
{
    if (amount > 0.0)
    {
        fineAmount += amount;
    }
    else
    {
        std::cerr << "[Warning] Invalid fine amount. Must be positive.\n";
    }
}

void Account::payFine(double payment)
{
    if (payment <= 0.0)
    {
        std::cerr << "[Warning] Invalid payment amount.\n";
        return;
    }
    if (payment > fineAmount)
    {
        std::cerr << "[Warning] Payment exceeds fine amount. Paying only what is owed.\n";
        fineAmount = 0.0;
    }
    else
    {
        fineAmount -= payment;
    }
}

void Account::calculateFine(int overdueDays)
{
    constexpr double finePerDay = 2.0; // Fine rate (units/day)
    if (overdueDays > 0)
    {
        addFine(overdueDays * finePerDay);
    }
}
void Account::displayAccountInfo() const
{
    std::cout << "\n=== ACCOUNT INFO ===\n"
              << "User ID       : " << userID << "\n"
              << "Borrowed Books: " << noBorrowedBooks << "\n"
              << "Returned Books: " << noReturnedBooks << "\n"
              << "Lost Books    : " << noLostBooks << "\n"
              << "Fine Amount   : $" << std::fixed << std::setprecision(2) << fineAmount << "\n"
              << "=====================\n";
}
// Operator overloads
Account &Account::operator+=(double fine)
{
    addFine(fine);
    return *this;
}

Account &Account::operator-=(double payment)
{
    payFine(payment);
    return *this;
}
