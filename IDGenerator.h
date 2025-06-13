#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <string>

class IDGenerator {
private:
    int nextResourceId = 1;
    int nextUserId = 1;
    int nextLoanId = 1;
    int nextReservationId = 1;

    const std::string RESOURCE_PREFIX = "R";
    const std::string USER_PREFIX = "U";
    const std::string LOAN_PREFIX = "L";
    const std::string RES_PREFIX = "RS";

public:
    std::string generateResourceID();
    std::string generateUserID();
    std::string generateLoanID();
    std::string generateReservationID();

    void setCounters(int r, int u, int l, int rs);
};

#endif