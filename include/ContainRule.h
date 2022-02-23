#pragma once

#include "ISearchRule.h"

#include <qstring.h>

class ContainRule :
    public ISearchRule
{
public:
    ContainRule();
    ContainRule(QString tag);
    ContainRule(const ContainRule& copy);
    ~ContainRule();

    virtual bool isAppropriate(Tags* tags) override;

    void setTag(QString tag);
    QString getTag();

protected:
private:
    QString tag;
};

