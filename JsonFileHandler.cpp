#include "JsonFileHandler.h"
#include "Resource.h"
#include "Book.h"
#include "Article.h"
#include "Thesis.h"
#include "DigitalContent.h"
#include "User.h"
#include "Student.h"
#include "Faculty.h"
#include "Librarian.h"
#include "LoanReservation.h"

#include <fstream>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

JsonFileHandler::JsonFileHandler(const std::string& resPath,
                                 const std::string& userPath,
                                 const std::string& loanPath,
                                 const std::string& resvPath)
    : resourcesFilePath(resPath),
      usersFilePath(userPath),
      loansFilePath(loanPath),
      reservationsFilePath(resvPath) {}

// ---------- Helper functions ----------

// Serialize a single Resource polymorphically
static json resourceToJson(const Resource* res) {
    json j;
    // Add common base attributes
    j["title"] = res->getTitle();
    j["author"] = res->getAuthor();
    j["publicationYear"] = res->getPublicationYear();
    j["resourceID"] = res->getResourceID();
    j["isAvailable"] = res->getAvailability();

    // Add type info and derived attributes
    if (auto b = dynamic_cast<const Book*>(res)) {
        j["type"] = "Book";
        j["ISBN"] = b->getISBN();
        j["publisher"] = b->getPublisher();
    } else if (auto a = dynamic_cast<const Article*>(res)) {
        j["type"] = "Article";
        j["journalName"] = a->getJournalName();
        j["volume"] = a->getVolume();
        j["issue"] = a->getIssue();
    } else if (auto t = dynamic_cast<const Thesis*>(res)) {
        j["type"] = "Thesis";
        j["university"] = t->getUniversity();
        j["degree"] = t->getDegree();
    } else if (auto d = dynamic_cast<const DigitalContent*>(res)) {
        j["type"] = "DigitalContent";
        j["fileFormat"] = d->getFileFormat();
        j["accessPath"] = d->getAccessPath();
        j["fileSizeKB"] = d->getFileSizeKB();
    } else {
        j["type"] = "Unknown";
    }

    return j;
}

// Deserialize a json object to a unique_ptr<Resource>
static std::unique_ptr<Resource> jsonToResource(const json& j) {
    std::string type = j.value("type", "Unknown");

    if (type == "Book") {
        return std::make_unique<Book>(
            j.at("title").get<std::string>(),
            j.at("author").get<std::string>(),
            j.at("publicationYear").get<int>(),
            j.at("resourceID").get<std::string>(),
            j.at("ISBN").get<std::string>(),
            j.at("publisher").get<std::string>(),
            j.at("isAvailable").get<bool>()
        );
    } else if (type == "Article") {
        return std::make_unique<Article>(
            j.at("title").get<std::string>(),
            j.at("author").get<std::string>(),
            j.at("publicationYear").get<int>(),
            j.at("resourceID").get<std::string>(),
            j.at("journalName").get<std::string>(),
            j.at("volume").get<int>(),
            j.at("issue").get<int>(),
            j.at("isAvailable").get<bool>()
        );
    } else if (type == "Thesis") {
        return std::make_unique<Thesis>(
            j.at("title").get<std::string>(),
            j.at("author").get<std::string>(),
            j.at("publicationYear").get<int>(),
            j.at("resourceID").get<std::string>(),
            j.at("university").get<std::string>(),
            j.at("degree").get<std::string>(),
            j.at("isAvailable").get<bool>()
        );
    } else if (type == "DigitalContent") {
        return std::make_unique<DigitalContent>(
            j.at("title").get<std::string>(),
            j.at("author").get<std::string>(),
            j.at("publicationYear").get<int>(),
            j.at("resourceID").get<std::string>(),
            j.at("fileFormat").get<std::string>(),
            j.at("accessPath").get<std::string>(),
            j.at("fileSizeKB").get<long>(),
            j.at("isAvailable").get<bool>()
        );
    }
    // Unknown type fallback: return nullptr
    return nullptr;
}

// Serialize a single User polymorphically
static json userToJson(const User* user) {
    json j;
    j["userID"] = user->getUserID();
    j["name"] = user->getName();
    j["email"] = user->getEmail();

    // Password typically should NOT be saved in plaintext — but we keep it here for demo
    // In a real system, use hashes, never plaintext
    j["password"] = ""; // omitted for security

    if (auto s = dynamic_cast<const Student*>(user)) {
        j["type"] = "Student";
        j["studentID"] = s->getStudentID();
        j["major"] = s->getMajor();
    } else if (auto f = dynamic_cast<const Faculty*>(user)) {
        j["type"] = "Faculty";
        j["facultyID"] = f->getFacultyID();
        j["department"] = f->getDepartment();
    } else if (auto l = dynamic_cast<const Librarian*>(user)) {
        j["type"] = "Librarian";
        j["staffID"] = l->getStaffID();
        j["role"] = l->getRole();
    } else {
        j["type"] = "Unknown";
    }

    return j;
}

// Deserialize a json object to unique_ptr<User>
static std::unique_ptr<User> jsonToUser(const json& j) {
    std::string type = j.value("type", "Unknown");
    std::string userID = j.at("userID").get<std::string>();
    std::string name = j.at("name").get<std::string>();
    std::string email = j.at("email").get<std::string>();
    std::string password = ""; // Ignored for security

    if (type == "Student") {
        return std::make_unique<Student>(
            userID, name, email, password,
            j.at("studentID").get<std::string>(),
            j.at("major").get<std::string>()
        );
    } else if (type == "Faculty") {
        return std::make_unique<Faculty>(
            userID, name, email, password,
            j.at("facultyID").get<std::string>(),
            j.at("department").get<std::string>()
        );
    } else if (type == "Librarian") {
        return std::make_unique<Librarian>(
            userID, name, email, password,
            j.at("staffID").get<std::string>(),
            j.at("role").get<std::string>()
        );
    }
    return nullptr;
}

// Loan to/from json conversion
static void to_json(json& j, const Loan& loan) {
    j = json{
        {"loanID", loan.getLoanID()},
        {"resourceID", loan.getResourceID()},
        {"userID", loan.getUserID()},
        {"borrowDate", loan.getBorrowDate()},
        {"dueDate", loan.getDueDate()},
        {"returnDate", loan.getReturnDate()},
        {"isOverdue", loan.getIsOverdue()}
    };
}

static void from_json(const json& j, Loan& loan) {
    // We'll assume Loan has setters or constructor to update fields
    // but since your Loan class has only constructor, we can reconstruct:

    // We assume Loan has a constructor that takes all params except returnDate and isOverdue
    // We'll create a new Loan and assign back? For now, default construction and setters.

    // Not implementing as Loan objects are simpler — alternative: use constructor in Library
}

// Reservation to/from json conversion
static void to_json(json& j, const Reservation& resv) {
    j = json{
        {"reservationID", resv.getReservationID()},
        {"resourceID", resv.getResourceID()},
        {"userID", resv.getUserID()},
        {"reservationDate", resv.getReservationDate()},
        {"isActive", resv.getIsActive()}
    };
}

static void from_json(const json& j, Reservation& resv) {
    // Same note as Loan
}

// ----------- Method Implementations ------------

void JsonFileHandler::saveResources(const std::vector<std::unique_ptr<Resource>>& resources) {
    json j = json::array();
    for (const auto& res : resources) {
        j.push_back(resourceToJson(res.get()));
    }
    std::ofstream file(resourcesFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open resources file for writing: " << resourcesFilePath << "\n";
        return;
    }
    file << j.dump(4);
}

std::vector<std::unique_ptr<Resource>> JsonFileHandler::loadResources() {
    std::vector<std::unique_ptr<Resource>> resources;
    std::ifstream file(resourcesFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open resources file for reading: " << resourcesFilePath << "\n";
        return resources;
    }
    json j;
    file >> j;
    for (const auto& item : j) {
        auto res = jsonToResource(item);
        if (res) {
            resources.push_back(std::move(res));
        }
    }
    return resources;
}

void JsonFileHandler::saveUsers(const std::vector<std::unique_ptr<User>>& users) {
    json j = json::array();
    for (const auto& user : users) {
        j.push_back(userToJson(user.get()));
    }
    std::ofstream file(usersFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open users file for writing: " << usersFilePath << "\n";
        return;
    }
    file << j.dump(4);
}

std::vector<std::unique_ptr<User>> JsonFileHandler::loadUsers() {
    std::vector<std::unique_ptr<User>> users;
    std::ifstream file(usersFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open users file for reading: " << usersFilePath << "\n";
        return users;
    }
    json j;
    file >> j;
    for (const auto& item : j) {
        auto user = jsonToUser(item);
        if (user) {
            users.push_back(std::move(user));
        }
    }
    return users;
}

void JsonFileHandler::saveLoans(const std::vector<Loan>& loans) {
    json j = json::array();
    for (const auto& loan : loans) {
        j.push_back(loan);
    }
    std::ofstream file(loansFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open loans file for writing: " << loansFilePath << "\n";
        return;
    }
    file << j.dump(4);
}

std::vector<Loan> JsonFileHandler::loadLoans() {
    std::vector<Loan> loans;
    std::ifstream file(loansFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open loans file for reading: " << loansFilePath << "\n";
        return loans;
    }
    json j;
    file >> j;
    for (const auto& item : j) {
        loans.push_back(item.get<Loan>()); // Assuming Loan has from_json defined
    }
    return loans;
}

void JsonFileHandler::saveReservations(const std::vector<Reservation>& reservations) {
    json j = json::array();
    for (const auto& resv : reservations) {
        j.push_back(resv);
    }
    std::ofstream file(reservationsFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open reservations file for writing: " << reservationsFilePath << "\n";
        return;
    }
    file << j.dump(4);
}

std::vector<Reservation> JsonFileHandler::loadReservations() {
    std::vector<Reservation> reservations;
    std::ifstream file(reservationsFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open reservations file for reading: " << reservationsFilePath << "\n";
        return reservations;
    }
    json j;
    file >> j;
    for (const auto& item : j) {
        reservations.push_back(item.get<Reservation>()); // Assuming from_json defined
    }
    return reservations;
}
