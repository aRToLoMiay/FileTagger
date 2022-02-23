#include "TagDBManager.h"

#include "ErrorHandler.h"
#include "XmlTagDBReader.h"

#include <qdir.h>
#include <qfileinfo.h>

TagDBManager::TagDBManager() {
    // DO NOTHING
}

TagDBManager::TagDBManager(QString path) {
    this->path = path;
}

TagDBManager::~TagDBManager() {
    // DO NOTHING
}

QString TagDBManager::getFilename() {
    return "_index_.xml";
}

void TagDBManager::add(QString filename) {
    TagDB* db = readFromFile(filename);
    dbs.insert(db->getName(), filename);
}

void TagDBManager::add(QString name, QString filename) {
    dbs.insert(name, filename);
}

void TagDBManager::remove(QString name) {
    dbs.remove(name);
}

void TagDBManager::rescan() {
    clear();
    XmlTagDBReader* reader = new XmlTagDBReader();
    QFileInfo info(path);
    QDir dir(info.path());
    dir.setFilter(QDir::Files);
    QFileInfoList list = dir.entryInfoList();
    foreach(QFileInfo finfo, list) {
        if (!finfo.isFile()) {
            continue;
        }
        if (finfo.suffix() != "xml") {
            continue;
        }

        reader->setup(finfo.absoluteFilePath());
        TagDB* db = reader->read();

        if (db != NULL) {
            add(db->getName(), finfo.fileName());
        }
        delete db;
    }
}

QString TagDBManager::getFilename(QString name) {
    return dbs.value(name);
}

TagDB* TagDBManager::getTagDB(QString name) {
    return readFromFile(dbs.value(name));
}

QList<QString> TagDBManager::elements() {
    return dbs.keys();
}

void TagDBManager::clear() {
    dbs.clear();
}

TagDB* TagDBManager::readFromFile(QString path) {
    XmlTagDBReader* reader = new XmlTagDBReader(QFileInfo(path).path());
    TagDB* db = reader->read();
    if (db == NULL) {
        ErrorHandler::error("База данных не существует " + path);
    }
    return db;
}
