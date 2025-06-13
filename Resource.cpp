#include <iostream>
#include <string>
#include "Resource.h"
#include <stdexcept>
using namespace std;

Resource::Resource(const string &t, const string &a, int py, const string &rID, bool ava = true)
    : title(t), author(a), publicationyear(py), resourceID(rID), isAvailable(ava)
{
    setAvailability(ava);
    if (title.empty())
        throw std::invalid_argument("Title cannot be empty.");
    if (author.empty())
        throw std::invalid_argument("Author cannot be empty.");
    if (resourceID.empty())
        throw std::invalid_argument("Resource ID cannot be empty.");
    if (publicationyear < 1450 || publicationyear > 2100)
        throw std::invalid_argument("Invalid publication year.");
};

string Resource::getTitle() const { return title; }

string Resource::getAuthor() const { return author; }

string Resource::getResourceID() const { return resourceID; }

int Resource::getPublicationYear() const { return publicationyear; }

bool Resource::getAvailability() const { return isAvailable; }
void Resource::setAvailability(bool status) { isAvailable = status; }

bool Resource::operator==(const Resource &other) const
{
    return resourceID == other.resourceID;
}

bool Resource::operator<(const Resource &other) const
{
    return title < other.title;
}

std::ostream &operator<<(std::ostream &output, const Resource &resource)
{
    output << "ID: " << resource.resourceID << ", Title: " << resource.title
           << ", Author: " << resource.author << ", Year: " << resource.publicationyear
           << ", Available: " << (resource.isAvailable ? "Yes" : "No");
    return output;
}