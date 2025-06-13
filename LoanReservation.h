#ifndef LOANRESERVATION_H
#define LOANRESERVATION_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <exception> // Include exception header explicitly
#include <string>

// Custom exception classes for error handling
class LoanException : public std::exception
{
private:
    std::string message;

public:
    explicit LoanException(const std::string &msg) : message(msg) {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class ReservationException : public std::exception
{
private:
    std::string message;

public:
    explicit ReservationException(const std::string &msg) : message(msg) {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

// Loan class - represents a resource being borrowed
class Loan
{
private:
    std::string loanID;
    std::string resourceID;
    std::string userID;
    std::string borrowDate;
    std::string dueDate;
    std::string returnDate;
    bool isOverdue;
    static int loanCounter; // Static member for unique ID generation

public:
    // Constructor
    Loan(const std::string &, const std::string &,
         const std::string &, const std::string &,
         const std::string &);

    // Default constructor
    Loan();

    // Copy constructor
    Loan(const Loan &);

    // Assignment operator
    Loan &operator=(const Loan &);

    // Destructor
    ~Loan() = default;

    // Getters
    std::string getLoanID() const;
    std::string getResourceID() const;
    std::string getUserID() const;
    std::string getBorrowDate() const;
    std::string getDueDate() const;
    std::string getReturnDate() const;
    bool getIsOverdue() const;

    // Setters
    void setReturnDate(const std::string &);
    void updateOverdueStatus();

    // Loan operations
    bool renewLoan(int);
    int calculateOverdueDays() const;

    // Static method for ID generation
    static std::string generateLoanID();

    // Utility methods
    bool isReturned() const;
    void displayLoanInfo() const;

    // Operator overloading
    bool operator==(const Loan &) const;
    bool operator<(const Loan &) const;

    // Friend function
    friend std::ostream &operator<<(std::ostream &, const Loan &);
};

// Reservation class - represents a user reserving a resource
class Reservation
{
private:
    std::string reservationID;
    std::string resourceID;
    std::string userID;
    std::string reservationDate;
    bool isActive;
    static int reservationCounter; // Static member for unique ID generation

public:
    // Constructor
    Reservation(const std::string &, const std::string &,
                const std::string &, const std::string &);

    // Default constructor
    Reservation();

    // Copy constructor
    Reservation(const Reservation &);

    // Assignment operator
    Reservation &operator=(const Reservation &);

    // Destructor
    ~Reservation() = default;

    // Getters
    std::string getReservationID() const;
    std::string getResourceID() const;
    std::string getUserID() const;
    std::string getReservationDate() const;
    bool getIsActive() const;

    // Setters
    void setIsActive(bool);

    // Reservation operations
    void cancelReservation();
    void fulfillReservation();
    void notifyUserOfAvailability() const;

    // Static method for ID generation
    static std::string generateReservationID();

    // Utility methods
    void displayReservationInfo() const;
    int getDaysWaiting() const;

    // Operator overloading
    bool operator==(const Reservation &) const;
    bool operator<(const Reservation &) const;

    // Friend function
    friend std::ostream &operator<<(std::ostream &, const Reservation &);
};

// Utility functions for date operations
namespace DateUtils
{
    std::string getCurrentDate();
    std::string addDaysToDate(const std::string &, int);
    int daysBetweenDates(const std::string &, const std::string &);
    bool isValidDate(const std::string &);
}

#endif // LOANRESERVATION_H