#pragma once

#include "ISearchRule.h"

class NothingContainRule :
    public ISearchRule
{
public:
    NothingContainRule();
    NothingContainRule(const NothingContainRule& copy);
    ~NothingContainRule();

    virtual bool isAppropriate(Tags* element) override;
};
