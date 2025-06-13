#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <memory>
#include <string>

class Resource;
class User;
class Loan;
class Reservation;

class FileHandler {
public:
    virtual ~FileHandler() = default;

    virtual void saveResources(const std::vector<std::unique_ptr<Resource>>& resources) = 0;
    virtual std::vector<std::unique_ptr<Resource>> loadResources() = 0;

    virtual void saveUsers(const std::vector<std::unique_ptr<User>>& users) = 0;
    virtual std::vector<std::unique_ptr<User>> loadUsers() = 0;

    virtual void saveLoans(const std::vector<Loan>& loans) = 0;
    virtual std::vector<Loan> loadLoans() = 0;

    virtual void saveReservations(const std::vector<Reservation>& reservations) = 0;
    virtual std::vector<Reservation> loadReservations() = 0;
};

#endif // FILEHANDLER_H
