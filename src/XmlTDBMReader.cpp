#include "XmlTDBMReader.h"

#include "ErrorHandler.h"
#include "XmlTagDBReader.h"

#include <qdir.h>
#include <qfile.h>
#include <qfileinfo.h>

XmlTDBMReader::XmlTDBMReader() {
    // DO NOTHING
}

XmlTDBMReader::XmlTDBMReader(QString path) {
    setup(path);
}

XmlTDBMReader::~XmlTDBMReader() {
    // DO NOTHING
}

TagDBManager* XmlTDBMReader::read() {
    if (!isValid()) {
        return NULL;
    }

    TagDBManager* result = new TagDBManager();
    QDomElement e = xml->documentElement();
    if (e.tagName() == "TagDBManager") {
        result = readManager(e);
    }

    return result;
}

void XmlTDBMReader::write(TagDBManager* manager) {
    QDomElement root = xml->documentElement();
    xml->removeChild(root);
    root = managerToXml(manager);
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

QDomElement XmlTDBMReader::toXml(TagDBManager* manager) {
    XmlTDBMReader* reader = new XmlTDBMReader();
    return reader->managerToXml(manager);
}

TagDBManager* XmlTDBMReader::fromXml(QDomElement& e) {
    XmlTDBMReader* reader = new XmlTDBMReader();
    return reader->readManager(e);
}

TagDBManager* XmlTDBMReader::readManager(QDomElement& e) {
    TagDBManager* result = new TagDBManager(path);

    QDomNodeList nodes = e.childNodes();
    for (int i = 0; i < nodes.size(); i++) {
        QDomElement el = nodes.at(i).toElement();
        if (el.tagName() == "TagDBMask") {
            QString name = el.attribute("name");
            QString path = el.attribute("filename");
            result->add(name, path);
        }
    }

    return result;
}

QDomElement XmlTDBMReader::managerToXml(TagDBManager* manager) {
    QDomElement e = xml->createElement("TagDBManager");

    foreach(QString name, manager->elements()) {
        QDomElement dbEl = xml->createElement("TagDBMask");
        dbEl.setAttribute("name", name);
        dbEl.setAttribute("filename", manager->getFilename(name));
        e.appendChild(dbEl);
    }

    return e;
}

TagDB* XmlTDBMReader::readTagDB(QDomElement& e) {
    QString path = e.attribute("path");
    QString name = e.attribute("name");

    XmlTagDBReader* reader = new XmlTagDBReader();
    reader->setup(path);
    TagDB* result = reader->read();

    if ((result != NULL) && (result->getName() != name)) {
        ErrorHandler::error(QObject::tr("Обнаружена несоответствующая база тегов ") + path);
    }

    return result;
}
