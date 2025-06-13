#include "IDGenerator.h"

std::string IDGenerator::generateResourceID() {
    return RESOURCE_PREFIX + std::to_string(nextResourceId++);
}

std::string IDGenerator::generateUserID() {
    return USER_PREFIX + std::to_string(nextUserId++);
}

std::string IDGenerator::generateLoanID() {
    return LOAN_PREFIX + std::to_string(nextLoanId++);
}

std::string IDGenerator::generateReservationID() {
    return RES_PREFIX + std::to_string(nextReservationId++);
}

void IDGenerator::setCounters(int r, int u, int l, int rs) {
    nextResourceId = r;
    nextUserId = u;
    nextLoanId = l;
    nextReservationId = rs;
}