#ifndef THESIS_H
#define THESIS_H

#include <iostream>
#include "Resource.h"
#include <string>
using namespace std;

class Thesis : public Resource
{
private:
    string university;
    string degree;

public:
    Thesis(const string &, const string &, int, const string &, const string &,
           const string &, bool = true);

    virtual void displayDetails() const override;
    string getResourceType() const override;

    string getUniversity() const;
    string getDegree() const;
};

#endif