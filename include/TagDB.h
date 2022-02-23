#pragma once

#include "TagMap.h"

#include <qlist.h>
#include <qstring.h>

class TagDB
{
public:
    TagDB();
    ~TagDB();

    QString getName();
    void setName(QString name);

    QString getPath();
    void setPath(QString path);

    TagMap<QString>* getTM();
    void setTM(TagMap<QString>* tm);

    QStringList getExtra();
    QStringList getMissing();
    bool hasExtra();
    bool hasMissing();
    bool isCorrect();

    void rescan();

protected:
    void readFiles();

private:
    QString name;
    QString path;

    QStringList extra;
    QStringList missing;

    TagMap<QString>* tm;
};
