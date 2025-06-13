#include <iostream>
#include "Book.h"
#include <string>
using namespace std;

Book::Book(const string &t, const string &a,
           int py, const string &rID, const string &isbn, const string &p, bool ava = true)
    : Resource(t, a, py, rID, ava), ISBN(isbn), publisher(p)
{
    if (ISBN.empty())
        throw std::invalid_argument("ISBN cannot be empty.");
    if (publisher.empty())
        throw std::invalid_argument("Publisher cannot be empty.");
}
void Book::displayDetails() const
{
    cout << "=== BOOK DETAILS ===\n"
         << "Title: " << getTitle << "\n"
         << "Author: " << getAuthor << "\n"
         << "Publication Year: " << getPublicationYear << "\n"
         << "Resource ID: " << getResourceID << "\n"
         << "ISBN: " << ISBN << "\n"
         << "Publisher: " << publisher << "\n"
         << "Available: " << (getAvailability ? "Yes" : "No")
         << "===================" << "\n";
}

string Book::getISBN() const { return ISBN; }
string Book::getPublisher() const { return publisher; }
string Book::getResourceType() const
{
    return "Book";
}