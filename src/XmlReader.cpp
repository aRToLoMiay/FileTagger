#include "XmlReader.h"

#include "ErrorHandler.h"

#include <qfile.h>
#include <qfileinfo.h>

XmlReader::XmlReader() {
    init();
}

XmlReader::~XmlReader() {
    clear();
}

bool XmlReader::setup(QString path) {
    clear();

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ErrorHandler::error(QObject::tr("Невозможно открыть файл для чтения: ") + path);
        return false;
    }

    this->path = path;
    xml = new QDomDocument();
    xml->setContent(&file);
    file.close();
    return true;
}

bool XmlReader::isValid() {
    if (xml == NULL) {
        ErrorHandler::error(QObject::tr("Xml-файл не подключен."));
        return false;
    }
    return true;
}

bool XmlReader::copy(QString newPath) {
    QFile file(path);
    if (!file.copy(newPath)) {
        ErrorHandler::error(QObject::tr("Невозможно скопировать файл ") + file.fileName() + QObject::tr(" в путь ") + newPath);
        return false;
    }
    return true;
}

bool XmlReader::move(QString newPath) {
    QFile file(path);
    if (!file.copy(newPath)) {
        ErrorHandler::error(QObject::tr("Невозможно переместить файл ") + file.fileName() + QObject::tr(" в путь ") + newPath);
        return false;
    }
    if (!file.remove()) {
        ErrorHandler::error(QObject::tr("Невозможно удалить старый файл: ") + file.fileName());
        return false;
    }
    return true;
}

bool XmlReader::rename(QString newName) {
    QFile file(path);
    if (!file.rename(newName)) {
        ErrorHandler::error(QObject::tr("Невозможно переименовать файл ") + file.fileName() + QObject::tr(" в имя ") + newName);
        return false;
    }
    return true;
}

bool XmlReader::create() {
    QFile file(path);
    if (! file.exists()) {
        return setup(path);
    }

    return true;
}

bool XmlReader::remove() {
    QFile file(path);
    if (! file.remove()) {
        ErrorHandler::error(QObject::tr("Невозможно удалить файл: ") + file.fileName());
        return false;
    }
    xml = NULL;
    return true;
}

QDomDocument* XmlReader::readXml(QString path) {
    QDomDocument* xml = NULL;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ErrorHandler::error(QObject::tr("Невозможно открыть файл для чтения: ") + file.fileName());
        return xml;
    }

    clear();
    xml = new QDomDocument();
    xml->setContent(&file);
    file.close();
    return xml;
}

bool XmlReader::writeXml(QString path, QDomDocument* xml) {
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ErrorHandler::error(QObject::tr("Невозможно открыть файл для записи: ") + file.fileName());
        return false;
    }

    QByteArray data = xml->toByteArray();
    file.write(data);
    file.close();
    return true;
}

void XmlReader::init() {
    path = "";
    xml = NULL;
}

void XmlReader::clear() {
    if (xml != NULL) {
        delete xml;
        xml = NULL;
    }
}

