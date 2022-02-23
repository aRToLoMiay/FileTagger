#include "TagDB.h"

#include "ErrorHandler.h"
#include "FilesLoader.h"

#include <qdir.h>
#include <qdebug.h>

TagDB::TagDB() {
    tm = NULL;
}

TagDB::~TagDB() {
    if (tm != NULL) {
        delete tm;
    }
}

QString TagDB::getName() { return name; }

void TagDB::setName(QString name) { this->name = name; }

QString TagDB::getPath() { return path; }

void TagDB::setPath(QString path) {
    this->path = path;
}

TagMap<QString>* TagDB::getTM() { return tm; }

void TagDB::setTM(TagMap<QString>* tm) { this->tm = tm; }

QStringList TagDB::getExtra() { return extra; }

QStringList TagDB::getMissing() { return missing; }

bool TagDB::hasExtra() { return ! extra.empty(); }

bool TagDB::hasMissing() { return !missing.empty(); }

bool TagDB::isCorrect() { return !(hasExtra() || hasMissing()); }

void TagDB::rescan() {
    readFiles();
}

void TagDB::readFiles() {
    FilesLoader loader(path);
    QStringList list(tm->map.keys());
    extra = loader.getMissing(list);
    missing = loader.getExtra(list);
}
