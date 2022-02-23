#pragma once

#include "ISearchRule.h"

#include <qstring.h>

class SearchRuleFabric
{
public:
    enum TypeRule {
        CONTAIN,
        UNCONTAIN,
        ALL_CONTAIN,
        NOTHING_CONTAIN
    };

    static ISearchRule* get(TypeRule type);
    static ISearchRule* get(TypeRule type, QString parameter);

protected:
private:
    SearchRuleFabric() {};
    ~SearchRuleFabric() {};
};
