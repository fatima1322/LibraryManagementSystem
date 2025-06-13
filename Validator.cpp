#include "Validator.h"

bool Validator::validateResource(const std::shared_ptr<Resource>& resource) {
    if (!resource) return false;
    return !resource->getTitle().empty() &&
           !resource->getAuthor().empty() &&
           !resource->getResourceID().empty() &&
           resource->getPublicationYear() > 0 &&
           resource->getPublicationYear() <= 2024;
}

bool Validator::validateUser(const std::shared_ptr<User>& user) {
    if (!user) return false;
    return !user->getName().empty() &&
           !user->getUserID().empty() &&
           isValidEmail(user->getEmail());
}

bool Validator::isValidEmail(const std::string& email) {
    const std::regex pattern(R"(^[\w\.-]+@[\w\.-]+\.\w+$)");
    return std::regex_match(email, pattern);
}
