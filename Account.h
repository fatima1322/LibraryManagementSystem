#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;
#include <string>

class Account
{
private:
    string userID;
    int noBorrowedBooks;
    int noReturnedBooks;
    int noLostBooks;
    double fineAmount;

public:
    Account(const string &);

    // Getters
    string getUserID() const;
    int getBorrowedBooksCount() const;
    int getReturnedBooksCount() const;
    int getLostBooksCount() const;
    double getFineAmount() const;

    // Book management
    void incrementBorrowedBooks();
    void decrementBorrowedBooks();
    void incrementReturnedBooks();
    void incrementLostBooks();

    // Fine management
    void addFine(double);
    void payFine(double);
    void calculateFine(int);

    // Display account info
    void displayAccountInfo() const;

    // Operator overloading
    Account &operator+=(double);
    Account &operator-=(double);
};

#endif