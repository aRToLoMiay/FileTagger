#pragma once

#include "TagDB.h"

#include <QDomDocument>
#include <qlist.h>

class TagDBManager
{
public:
    TagDBManager();
    TagDBManager(QString path);
    ~TagDBManager();

    static QString getFilename();

    void add(QString filename);
    void add(QString name, QString filename);
    void remove(QString name);
    void rescan();
    QString getFilename(QString name);
    TagDB* getTagDB(QString name);
    QList<QString> elements();

protected:
    void clear();
    TagDB* readFromFile(QString path);

private:
    QString path;
    QMap<QString, QString> dbs; // <basename, filename>
};
