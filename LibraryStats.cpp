#include "LibraryStats.h"

size_t LibraryStats::getTotalResources(const std::vector<std::shared_ptr<Resource>>& resources) {
    return resources.size();
}

size_t LibraryStats::getAvailableResources(const std::vector<std::shared_ptr<Resource>>& resources) {
    return std::count_if(resources.begin(), resources.end(), [](const auto& r) {
        return r && r->getAvailability();
    });
}

size_t LibraryStats::getActiveLoans(const std::vector<std::shared_ptr<Loan>>& loans) {
    return std::count_if(loans.begin(), loans.end(), [](const auto& l) {
        return l && l->getReturnDate().empty();
    });
}

size_t LibraryStats::getActiveReservations(const std::vector<std::shared_ptr<Reservation>>& reservations) {
    return std::count_if(reservations.begin(), reservations.end(), [](const auto& r) {
        return r && r->getIsActive();
    });
}

size_t LibraryStats::getTotalUsers(const std::vector<std::shared_ptr<User>>& users) {
    return users.size();
}
