#include "ContainRule.h"

ContainRule::ContainRule() {
    tag = "";
}

ContainRule::ContainRule(QString tag) {
    this->tag = tag;
}

ContainRule::ContainRule(const ContainRule& copy) {
    this->tag = copy.tag;
}

ContainRule::~ContainRule() {
    // DO NOTHING
}

bool ContainRule::isAppropriate(Tags* tags) {
    return tags->contains(tag);
}

void ContainRule::setTag(QString tag) { this->tag = tag; }

QString ContainRule::getTag() { return tag; }
