#pragma once

#include <qstring.h>
#include <qstringlist.h>

class Tags
{
public:
    Tags();
    ~Tags();

    QStringList getTags();
    void addTag(QString tag);
    void deleteTag(QString tag);

    bool contains(QString tag);
    bool contains(QStringList tags);

protected:
    QStringList tags;
};
