#include "SearchRuleFabric.h"

#include "AllContainRule.h"
#include "ContainRule.h"
#include "NothingContainRule.h"
#include "UncontainRule.h"

ISearchRule* SearchRuleFabric::get(TypeRule type) {
    return SearchRuleFabric::get(type, "");
}

ISearchRule* SearchRuleFabric::get(TypeRule type, QString parameter) {
    if (type == SearchRuleFabric::CONTAIN) {
        return new ContainRule(parameter);
    }
    if (type == SearchRuleFabric::UNCONTAIN) {
        return new UncontainRule(parameter);
    }
    if (type == SearchRuleFabric::ALL_CONTAIN) {
        return new AllContainRule();
    }
    if (type == SearchRuleFabric::NOTHING_CONTAIN) {
        return new NothingContainRule();
    }
    return NULL;
}
