#pragma once

#include "Tags.h"

class ISearchRule {
public:
    virtual bool isAppropriate(Tags* element) = 0;
};

//Возможные правила :
//- содержит теги в соответствии с регулярным выражением
//- не содержит теги в соответствии с регулярным выражением
