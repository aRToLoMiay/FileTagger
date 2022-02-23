#pragma once

#include <QDomDocument>
#include <qstring.h>

class XmlReader
{
public:
    XmlReader();
    ~XmlReader();

    bool setup(QString path);

    bool isValid();

    bool copy(QString path);
    bool move(QString newPath);
    bool rename(QString newName);
    bool create();
    bool remove();

protected:
    QDomDocument* readXml(QString path);
    bool writeXml(QString path, QDomDocument* xml);

    void init();
    void clear();

    QString path;
    QDomDocument* xml;
};
