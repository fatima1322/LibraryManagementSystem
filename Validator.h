#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <memory>
#include <regex>
#include "Resource.h"
#include "User.h"

class Validator {
public:
    static bool validateResource(const std::shared_ptr<Resource>& resource);
    static bool validateUser(const std::shared_ptr<User>& user);
    static bool isValidEmail(const std::string& email);
};

#endif