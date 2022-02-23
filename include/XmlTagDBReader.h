#pragma once

#include "ITagDBReader.h"
#include "XmlReader.h"

#include <QDomDocument>

class XmlTagDBReader :
    public ITagDBReader, public XmlReader
{
public:
    XmlTagDBReader();
    XmlTagDBReader(QString path);
    ~XmlTagDBReader();

    virtual TagDB* read() override;
    virtual void write(TagDB* db) override;

    static QDomElement toXml(TagDB* db);
    static TagDB* fromXml(QDomElement& e);

protected:
    TagDB* readTagDB(QDomElement& e);
    QDomElement tagDBToXml(TagDB* db);

    TagMap<QString>* readTagMap(QDomElement& e);
    Tags* readTags(QDomElement& e);

    QDomElement tagMapToXml(TagMap<QString>* tm);
    QDomElement tagsToXml(Tags* tags);
};
