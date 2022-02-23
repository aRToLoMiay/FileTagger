#pragma once

#include "qdir.h"
#include "qfile.h"
#include "qfileinfo.h"
#include "qstring.h"

class FilesLoader
{
public:
    FilesLoader();
    FilesLoader(QString path);
    ~FilesLoader();

    void setPath(QString path);
    QString getPath();
    QStringList getFiles();

    QStringList getDuplicates(QStringList files); // return files in loader and in list
    QStringList getMissing(QStringList files); // return files in loader, but not in list
    QStringList getExtra(QStringList files); // return files not in loader, but in list

    void print();

    void update();

protected:
    void findDirFiles(QString path);

private:
    QString path;
    QStringList files;
};
