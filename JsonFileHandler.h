#ifndef JSONFILEHANDLER_H
#define JSONFILEHANDLER_H

#include "FileHandler.h"
#include <string>

class JsonFileHandler : public FileHandler {
private:
    std::string resourcesFilePath;
    std::string usersFilePath;
    std::string loansFilePath;
    std::string reservationsFilePath;

public:
    JsonFileHandler(const std::string& resPath,
                    const std::string& userPath,
                    const std::string& loanPath,
                    const std::string& resvPath);

    void saveResources(const std::vector<std::unique_ptr<Resource>>& resources) override;
    std::vector<std::unique_ptr<Resource>> loadResources() override;

    void saveUsers(const std::vector<std::unique_ptr<User>>& users) override;
    std::vector<std::unique_ptr<User>> loadUsers() override;

    void saveLoans(const std::vector<Loan>& loans) override;
    std::vector<Loan> loadLoans() override;

    void saveReservations(const std::vector<Reservation>& reservations) override;
    std::vector<Reservation> loadReservations() override;
};

#endif // JSONFILEHANDLER_H
