#include "NothingContainRule.h"

NothingContainRule::NothingContainRule() {
    // DO NOTHING
}

NothingContainRule::NothingContainRule(const NothingContainRule& copy) {
    // DO NOTHING
}

NothingContainRule::~NothingContainRule() {
    // DO NOTHING
}

bool NothingContainRule::isAppropriate(Tags* element) {
    return false;
}
