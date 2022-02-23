#include "XmlTagDBReader.h"

#include "ErrorHandler.h"

#include <qfile.h>

XmlTagDBReader::XmlTagDBReader() {
    init();
}

XmlTagDBReader::XmlTagDBReader(QString path) {
    init();
    setup(path);
}

XmlTagDBReader::~XmlTagDBReader() {
    clear();
}

TagDB* XmlTagDBReader::read() {
    if (!isValid()) {
        return NULL;
    }

    TagDB* result;
    QDomElement e = xml->documentElement();
    if (e.tagName() == "TagDB") {
        result = readTagDB(e);
    }
    else {
        result = NULL;
    }

    return result;
}

void XmlTagDBReader::write(TagDB* db) {
    QDomElement root = xml->documentElement();
    xml->removeChild(root);
    root = tagDBToXml(db);
    xml->appendChild(root);

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ErrorHandler::error(QObject::tr("Невозможно открыть файл для записи ") + path);
        return;
    }

    QByteArray data = xml->toByteArray();
    file.write(data);
    file.close();
}

QDomElement XmlTagDBReader::toXml(TagDB* db) {
    XmlTagDBReader* reader = new XmlTagDBReader();
    return reader->tagDBToXml(db);
}

TagDB* XmlTagDBReader::fromXml(QDomElement& e) {
    XmlTagDBReader* reader = new XmlTagDBReader();
    return reader->readTagDB(e);
}

TagDB* XmlTagDBReader::readTagDB(QDomElement& e) {
    TagDB* result = new TagDB();

    result->setName(e.attribute("name"));
    result->setPath(e.attribute("path"));
    QDomNodeList nodes = e.childNodes();
    for (int i = 0; i < nodes.size(); i++) {
        QDomElement e = nodes.at(i).toElement();
        if (e.tagName() == "TagMap") {
            TagMap<QString>* tm = readTagMap(e);
            result->setTM(tm);
        }
    }

    return result;
}

TagMap<QString>* XmlTagDBReader::readTagMap(QDomElement& e) {
    TagMap<QString>* result = new TagMap<QString>();

    QDomNodeList nodes = e.childNodes();
    for (int i = 0; i < nodes.size(); i++) {
        QDomElement essEl = nodes.at(i).toElement();
        if (essEl.tagName() == "TagsElement") {
            QDomNodeList tagsNodes = essEl.childNodes();
            QDomElement tagsEl = tagsNodes.at(0).toElement();
            Tags* tags = readTags(tagsEl);
            QString path = essEl.attribute("path");
            result->map.insert(path, tags);
        }
    }

    return result;
}

Tags* XmlTagDBReader::readTags(QDomElement& e) {
    Tags* result = new Tags();

    QDomNodeList nodes = e.childNodes();
    for (int i = 0; i < nodes.size(); i++) {
        QDomElement tagE = nodes.at(i).toElement();
        if (tagE.tagName() == "Tag") {
            result->addTag(tagE.attribute("value"));
        }
    }

    return result;
}

QDomElement XmlTagDBReader::tagDBToXml(TagDB* db) {
    QDomElement result = xml->createElement("TagDB");

    result.setAttribute("name", db->getName());
    result.setAttribute("path", db->getPath());
    QDomElement tmEl = tagMapToXml(db->getTM());
    result.appendChild(tmEl);

    return result;
}

QDomElement XmlTagDBReader::tagMapToXml(TagMap<QString>* tm) {
    QDomElement result = xml->createElement("TagMap");

    foreach(QString path, tm->map.keys()) {
        QDomElement essEl = xml->createElement("TagsElement");
        essEl.setAttribute("path", path);
        QDomElement tagsEl = tagsToXml(tm->map.value(path));
        essEl.appendChild(tagsEl);
        result.appendChild(essEl);
    }

    return result;
}

QDomElement XmlTagDBReader::tagsToXml(Tags* tags) {
    QDomElement result = xml->createElement("Tags");

    foreach(QString tag, tags->getTags()) {
        QDomElement tagEl = xml->createElement("Tag");
        tagEl.setAttribute("value", tag);
        result.appendChild(tagEl);
    }

    return result;
}
