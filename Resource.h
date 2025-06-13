#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
using namespace std;
#include <string>

class Resource
{
protected:
    string title;
    string resourceID;
    string author;
    int publicationyear;
    bool isAvailable;

public:
    // Constructor
    Resource(const string &, const string &, int, const string &, bool = true);
    // Virtual destructor
    virtual ~Resource() = default;
    // Pure virtual function: must be implemented by derived classes
    virtual void displayDetails() const = 0;
    virtual string getResourceType() const = 0;
    // Getters
    string getTitle() const;
    string getAuthor() const;
    string getResourceID() const;
    int getPublicationYear() const;
    bool getAvailability() const;
    // Setter
    void setAvailability(bool);
    // Operator overloading for comparison
    bool operator==(const Resource &) const;
    bool operator<(const Resource &) const;
    // Friend function for output stream
    friend std::ostream &operator<<(std::ostream &, const Resource &);
};
#endif