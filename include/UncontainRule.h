#pragma once

#include "ISearchRule.h"

#include <qstring.h>

class UncontainRule :
    public ISearchRule
{
public:
    UncontainRule();
    UncontainRule(QString tag);
    UncontainRule(const UncontainRule& copy);
    ~UncontainRule();

    virtual bool isAppropriate(Tags* tags) override;

    void setTag(QString tag);
    QString getTag();

protected:
    QString tag;
};
