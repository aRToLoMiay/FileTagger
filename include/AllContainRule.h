#pragma once

#include "ISearchRule.h"

class AllContainRule :
    public ISearchRule
{
public:
    AllContainRule();
    AllContainRule(const AllContainRule& copy);
    ~AllContainRule();

    virtual bool isAppropriate(Tags* tags) override;
};

