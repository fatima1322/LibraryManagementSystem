#include <iostream>
#include "Article.h"
#include <string>
using namespace std;

Article::Article(const string &t, const string &a, int py,
                 const string &rID, const string &jName,
                 int v, int i, bool ava = true)
    : Resource(t, a, py, rID, ava),
      journalName(jName), volume(v), issue(i)
{
  if (journalName.empty())
    throw std::invalid_argument("Journal name cannot be empty.");
  if (volume <= 0)
    throw std::invalid_argument("Volume must be positive.");
  if (issue <= 0)
    throw std::invalid_argument("Issue must be positive.");
}

void Article::displayDetails() const
{
  cout << "Article [ID: " << getResourceID << "]\n"
       << "Title: " << getTitle << "\n"
       << "Author: " << getAuthor << "\n"
       << "Year: " << getPublicationYear << "\n"

       << "Available: " << (getAvailability ? "Yes" : "No") << "\n";
  cout << "=== ARTICLE  DETAILS ===\n"
       << "Title: " << getTitle << "\n"
       << "Author: " << getAuthor << "\n"
       << "Publication Year: " << getPublicationYear << "\n"
       << "Resource ID: " << getResourceID << "\n"
       << "Journal: " << journalName << "\n"
       << "Volume: " << volume << "\n"
       << "Issue: " << issue << "\n"
       << "Available: " << (getAvailability ? "Yes" : "No")
       << "======================" << "\n";
}

string Article::getJournalName() const { return journalName; }
int Article::getVolume() const { return volume; }
int Article::getIssue() const { return issue; }
string Article::getResourceType() const
{
  return "Article";
}