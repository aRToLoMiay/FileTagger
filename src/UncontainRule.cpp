#include "UncontainRule.h"

UncontainRule::UncontainRule() {
    tag = "";
}

UncontainRule::UncontainRule(QString tag) {
    this->tag = tag;
}

UncontainRule::UncontainRule(const UncontainRule& copy) {
    this->tag = copy.tag;
}

UncontainRule::~UncontainRule() {
    // DO NOTHING
}

bool UncontainRule::isAppropriate(Tags* tags) {
    return !tags->contains(tag);
}

void UncontainRule::setTag(QString tag) { this->tag = tag; }

QString UncontainRule::getTag() { return tag; }
