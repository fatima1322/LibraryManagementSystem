#ifndef LIBRARYSTATS_H
#define LIBRARYSTATS_H

#include <vector>
#include<algorithm>
#include <memory>
#include "Resource.h"
#include "User.h"
#include "LoanReservation.h"
class LibraryStats
{
public:
    static size_t getTotalResources(const std::vector<std::shared_ptr<Resource>> &resources);
    static size_t getAvailableResources(const std::vector<std::shared_ptr<Resource>> &resources);
    static size_t getActiveLoans(const std::vector<std::shared_ptr<Loan>> &loans);
    static size_t getActiveReservations(const std::vector<std::shared_ptr<Reservation>> &reservations);
    static size_t getTotalUsers(const std::vector<std::shared_ptr<User>> &users);
};

#endif