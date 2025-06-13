#include <iostream>
#include "Thesis.h"
#include <string>
using namespace std;

Thesis::Thesis(const string &t, const string &a, int py, const string &rID,
               const string &uni, const string &deg, bool ava = true)
    : Resource(t, a, py, rID, ava),
      university(uni), degree(deg)
{
  if (university.empty())
    throw std::invalid_argument("University cannot be empty.");
  if (degree.empty())
    throw std::invalid_argument("Degree cannot be empty.");
}

void Thesis::displayDetails() const
{
  cout << "=== THESIS  DETAILS ===\n"
       << "Title: " << getTitle << "\n"
       << "Author: " << getAuthor << "\n"
       << "Publication Year: " << getPublicationYear << "\n"
       << "Resource ID: " << getResourceID << "\n"
       << "University: " << university << "\n"
       << "Degree: " << degree << "\n"
       << "Available: " << (getAvailability ? "Yes" : "No")
       << "=====================" << "\n";
}

string Thesis::getUniversity() const { return university; }
string Thesis::getDegree() const { return degree; }
string Thesis::getResourceType() const
{
  return "Thesis";
}