#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>
#include "Resource.h"
#include <string>
using namespace std;

class Article : public Resource
{
private:
    string journalName;
    int volume;
    int issue;

public:
    Article(const string &, const string &, int,
            const string &, const string &,
            int, int, bool = true);

    virtual void displayDetails() const override;
    string getResourceType() const override;

    string getJournalName() const;
    int getVolume() const;
    int getIssue() const;
};

#endif