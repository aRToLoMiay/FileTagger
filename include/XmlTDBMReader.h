#pragma once

#include "TagDBManager.h"
#include "XmlReader.h"

class XmlTDBMReader :
    public XmlReader
{
public:
    XmlTDBMReader();
    XmlTDBMReader(QString path);
    ~XmlTDBMReader();

    TagDBManager* read();
    void write(TagDBManager* manager);

    static QDomElement toXml(TagDBManager* manager);
    static TagDBManager* fromXml(QDomElement& e);

protected:
    TagDBManager* readManager(QDomElement& e);
    QDomElement managerToXml(TagDBManager* manager);

    TagDB* readTagDB(QDomElement& e);
};

