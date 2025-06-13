#ifndef DIGITALCONTENT_H
#define DIGITALCONTENT_H

#include <iostream>
#include "Resource.h"
#include <string>
using namespace std;

class DigitalContent : public Resource
{
private:
    string fileFormat;
    string accessPath;
    long fileSizeKB;

public:
    DigitalContent(const string &, const string &, int, const string &, const string &,
                   const string &, long, bool = true);

    virtual void displayDetails() const override;
    string getResourceType() const override;

    string getFileFormat() const;
    string getAccessPath() const;
    long getFileSizeKB() const;
};

#endif