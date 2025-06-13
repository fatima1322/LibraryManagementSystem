#include "LoanReservation.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <stdexcept> // for std::runtime_error

// Static member initialization
int Loan::loanCounter = 1000;
int Reservation::reservationCounter = 2000;

// Loan class implementation
Loan::Loan(const std::string &lID, const std::string &rID,
           const std::string &uID, const std::string &bDate,
           const std::string &dDate)
    : loanID(lID), resourceID(rID), userID(uID),
      borrowDate(bDate), dueDate(dDate), returnDate(""), isOverdue(false)
{
    updateOverdueStatus();
}

Loan::Loan() : loanID(""), resourceID(""), userID(""), borrowDate(""),
               dueDate(""), returnDate(""), isOverdue(false) {}

Loan::Loan(const Loan &other)
    : loanID(other.loanID), resourceID(other.resourceID), userID(other.userID),
      borrowDate(other.borrowDate), dueDate(other.dueDate),
      returnDate(other.returnDate), isOverdue(other.isOverdue) {}

Loan &Loan::operator=(const Loan &other)
{
    if (this != &other)
    {
        loanID = other.loanID;
        resourceID = other.resourceID;
        userID = other.userID;
        borrowDate = other.borrowDate;
        dueDate = other.dueDate;
        returnDate = other.returnDate;
        isOverdue = other.isOverdue;
    }
    return *this;
}

std::string Loan::getLoanID() const
{
    return loanID;
}

std::string Loan::getResourceID() const
{
    return resourceID;
}

std::string Loan::getUserID() const
{
    return userID;
}

std::string Loan::getBorrowDate() const
{
    return borrowDate;
}

std::string Loan::getDueDate() const
{
    return dueDate;
}

std::string Loan::getReturnDate() const
{
    return returnDate;
}

bool Loan::getIsOverdue() const
{
    return isOverdue;
}

void Loan::setReturnDate(const std::string &date)
{
    returnDate = date;
    updateOverdueStatus(); // Update overdue status after setting return date}
}

void Loan::updateOverdueStatus()
{
    if (returnDate.empty())
    { // Only check if not returned
        std::string currentDate = DateUtils::getCurrentDate();
        isOverdue = (currentDate > dueDate);
    }
    else
    {
        isOverdue = false; // If returned, cannot be overdue
    }
}

bool Loan::renewLoan(int daysToAdd)
{
    if (isReturned())
    {
        throw LoanException("Cannot renew a returned loan");
    }

    if (isOverdue)
    {
        throw LoanException("Cannot renew an overdue loan");
    }

    try
    {
        dueDate = DateUtils::addDaysToDate(dueDate, daysToAdd);
        updateOverdueStatus();
        return true;
    }
    catch (const std::exception &e)
    {
        throw LoanException("Failed to renew loan: " + std::string(e.what()));
    }
}

int Loan::calculateOverdueDays() const
{
    if (!isOverdue || !returnDate.empty())
    {
        return 0; // If not overdue or already returned, no overdue days
    }

    std::string currentDate = DateUtils::getCurrentDate();
    return DateUtils::daysBetweenDates(dueDate, currentDate);
}

std::string Loan::generateLoanID()
{
    return "L" + std::to_string(++loanCounter);
}

bool Loan::isReturned() const
{
    return !returnDate.empty();
}

void Loan::displayLoanInfo() const
{
    std::cout << "=== LOAN INFORMATION ===" << std::endl;
    std::cout << "Loan ID: " << loanID << std::endl;
    std::cout << "Resource ID: " << resourceID << std::endl;
    std::cout << "User ID: " << userID << std::endl;
    std::cout << "Borrow Date: " << borrowDate << std::endl;
    std::cout << "Due Date: " << dueDate << std::endl;
    std::cout << "Return Date: " << (returnDate.empty() ? "Not Returned" : returnDate) << std::endl;
    std::cout << "Status: " << (isOverdue ? "OVERDUE" : "ACTIVE") << std::endl;
    if (isOverdue && returnDate.empty())
    {
        std::cout << "Overdue Days: " << calculateOverdueDays() << std::endl;
    }
    std::cout << "========================" << std::endl;
}

bool Loan::operator==(const Loan &other) const
{
    return loanID == other.loanID;
}

bool Loan::operator<(const Loan &other) const
{
    return borrowDate < other.borrowDate;
}

std::ostream &operator<<(std::ostream &os, const Loan &loan)
{
    os << "Loan ID: " << loan.loanID << ", Resource: " << loan.resourceID
       << ", User: " << loan.userID << ", Due: " << loan.dueDate
       << ", Status: " << (loan.isOverdue ? "OVERDUE" : "ACTIVE");
    return os;
}

// Reservation class implementation
Reservation::Reservation(const std::string &reservationID, const std::string &resourceID,
                         const std::string &userID, const std::string &reservationDate)
    : reservationID(reservationID), resourceID(resourceID), userID(userID),
      reservationDate(reservationDate), isActive(true) {}

Reservation::Reservation()
    : reservationID(""), resourceID(""), userID(""), reservationDate(""), isActive(false) {}

Reservation::Reservation(const Reservation &other)
    : reservationID(other.reservationID), resourceID(other.resourceID),
      userID(other.userID), reservationDate(other.reservationDate), isActive(other.isActive) {}

Reservation &Reservation::operator=(const Reservation &other)
{
    if (this != &other)
    {
        reservationID = other.reservationID;
        resourceID = other.resourceID;
        userID = other.userID;
        reservationDate = other.reservationDate;
        isActive = other.isActive;
    }
    return *this;
}

std::string Reservation::getReservationID() const
{
    return reservationID;
}

std::string Reservation::getResourceID() const
{
    return resourceID;
}

std::string Reservation::getUserID() const
{
    return userID;
}

std::string Reservation::getReservationDate() const
{
    return reservationDate;
}

bool Reservation::getIsActive() const
{
    return isActive;
}

void Reservation::setIsActive(bool status)
{
    isActive = status;
}

void Reservation::cancelReservation()
{
    if (!isActive)
    {
        throw ReservationException("Reservation is already inactive");
    }
    isActive = false;
    std::cout << "Reservation " << reservationID << " has been cancelled." << std::endl;
}

void Reservation::fulfillReservation()
{
    if (!isActive)
    {
        throw ReservationException("Cannot fulfill an inactive reservation");
    }
    isActive = false;
    std::cout << "Reservation " << reservationID << " has been fulfilled." << std::endl;
}

void Reservation::notifyUserOfAvailability() const
{
    std::cout << "NOTIFICATION: Resource " << resourceID
              << " is now available for user " << userID
              << " (Reservation ID: " << reservationID << ")" << std::endl;
}

std::string Reservation::generateReservationID()
{
    return "R" + std::to_string(++reservationCounter);
}

void Reservation::displayReservationInfo() const
{
    std::cout << "=== RESERVATION INFORMATION ===" << std::endl;
    std::cout << "Reservation ID: " << reservationID << std::endl;
    std::cout << "Resource ID: " << resourceID << std::endl;
    std::cout << "User ID: " << userID << std::endl;
    std::cout << "Reservation Date: " << reservationDate << std::endl;
    std::cout << "Status: " << (isActive ? "ACTIVE" : "INACTIVE") << std::endl;
    std::cout << "Days Waiting: " << getDaysWaiting() << std::endl;
    std::cout << "===============================" << std::endl;
}

int Reservation::getDaysWaiting() const
{
    std::string currentDate = DateUtils::getCurrentDate();
    return DateUtils::daysBetweenDates(reservationDate, currentDate);
}

bool Reservation::operator==(const Reservation &other) const
{
    return reservationID == other.reservationID;
}

bool Reservation::operator<(const Reservation &other) const
{
    return reservationDate < other.reservationDate;
}

std::ostream &operator<<(std::ostream &os, const Reservation &reservation)
{
    os << "Reservation ID: " << reservation.reservationID
       << ", Resource: " << reservation.resourceID
       << ", User: " << reservation.userID
       << ", Date: " << reservation.reservationDate
       << ", Status: " << (reservation.isActive ? "ACTIVE" : "INACTIVE");
    return os;
}

// DateUtils namespace implementation
namespace DateUtils
{
    std::string getCurrentDate()
    {
        auto now = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        auto tm = *std::localtime(&time_t);

        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d");
        return oss.str();
    }

    std::string addDaysToDate(const std::string &date, int days)
    {
        // Simple implementation - in real system, use proper date library
        // This is a simplified version for demonstration
        try
        {
            std::tm tm = {};
            std::istringstream ss(date);
            ss >> std::get_time(&tm, "%Y-%m-%d");

            if (ss.fail())
            {
                throw std::runtime_error("Invalid date format");
            }

            auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
            tp += std::chrono::hours(24 * days);
            auto time_t = std::chrono::system_clock::to_time_t(tp);
            auto new_tm = *std::localtime(&time_t);

            std::ostringstream oss;
            oss << std::put_time(&new_tm, "%Y-%m-%d");
            return oss.str();
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Error adding days to date: " + std::string(e.what()));
        }
    }

    int daysBetweenDates(const std::string &date1, const std::string &date2)
    {
        try
        {
            std::tm tm1 = {}, tm2 = {};
            std::istringstream ss1(date1), ss2(date2);

            ss1 >> std::get_time(&tm1, "%Y-%m-%d");
            ss2 >> std::get_time(&tm2, "%Y-%m-%d");

            if (ss1.fail() || ss2.fail())
            {
                throw std::runtime_error("Invalid date format");
            }

            auto tp1 = std::chrono::system_clock::from_time_t(std::mktime(&tm1));
            auto tp2 = std::chrono::system_clock::from_time_t(std::mktime(&tm2));

            auto duration = tp2 - tp1;
            return std::chrono::duration_cast<std::chrono::hours>(duration).count() / 24;
        }
        catch (const std::exception &e)
        {
            return 0; // Return 0 on error
        }
    }

    bool isValidDate(const std::string &date)
    {
        std::tm tm = {};
        std::istringstream ss(date);
        ss >> std::get_time(&tm, "%Y-%m-%d");
        return !ss.fail();
    }
}