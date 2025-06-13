#include "DigitalContent.h"
#include <iostream>
#include <string>
using namespace std;

DigitalContent::DigitalContent(const string &t, const string &a, int py, const string &rID,
                               const string &fileF, const string &Apath, long fileS, bool ava = true)
    : Resource(t, a, py, rID, ava),
      fileFormat(fileF), accessPath(Apath), fileSizeKB(fileS)
{
  if (fileFormat.empty())
    throw std::invalid_argument("File format cannot be empty.");
  if (accessPath.empty())
    throw std::invalid_argument("Access path cannot be empty.");
  if (fileSizeKB <= 0)
    throw std::invalid_argument("File size must be positive.");
}

void DigitalContent::displayDetails() const
{
  cout << "=== DIGITAL CONTENT DETAILS ===\n"
       << "Title: " << getTitle << "\n"
       << "Author: " << getAuthor << "\n"
       << "Publication Year: " << getPublicationYear << "\n"
       << "Resource ID: " << getResourceID << "\n"
       << "File Format: " << fileFormat << "\n"
       << "Access Path: " << accessPath << "\n"
       << "File Size: " << fileSizeKB << " KB" << "\n"
       << "Available: " << (getAvailability ? "Yes" : "No")
       << "===============================" << "\n";
}

string DigitalContent::getFileFormat() const { return fileFormat; }
string DigitalContent::getAccessPath() const { return accessPath; }
long DigitalContent::getFileSizeKB() const { return fileSizeKB; }
string DigitalContent::getResourceType() const
{
  return "Digital Content";
}