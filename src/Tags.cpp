#include "Tags.h"

Tags::Tags() {
    // DO NOTHING
}

Tags::~Tags() {
    // DO NOTHING
}

QStringList Tags::getTags() { return tags; }

void Tags::addTag(QString tag) {
    if (!tags.contains(tag)) {
        tags.append(tag);
    }
}

void Tags::deleteTag(QString tag) { tags.removeAll(tag); }

bool Tags::contains(QString tag) { return tags.contains(tag); }

bool Tags::contains(QStringList tags) {
    foreach(QString tag, tags) {
        if (!tag.contains(tag)) {
            return false;
        }
    }
    return true;
}
