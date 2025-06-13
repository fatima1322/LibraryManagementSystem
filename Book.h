#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "Resource.h"
#include <string>
using namespace std;

class Book : public Resource
{
    friend class JsonFileHandler;
private:
    string ISBN;
    string publisher;

public:
    Book(const string &, const string &, int,
         const string &, const string &, const string &, bool = true);

    virtual void displayDetails() const override;
    string getResourceType() const override;

    string getISBN() const;
    string getPublisher() const;
};

#endif