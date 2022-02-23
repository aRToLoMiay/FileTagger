#include "Testsh.h"

#include "ConsoleTagDBReader.h"
#include "ErrorHandler.h"
#include "XmlTagDBReader.h"
#include "XmlTDBMReader.h"

#include <QDebug>
#include <qfileinfo.h>

int tagsManagerTest() {
    QString path = "G:/Projects/Programming/FileTagger/resource/base/";
    QString fileName = "_index_.xml";

    XmlTDBMReader* reader = new XmlTDBMReader(path + fileName);

    TagDBManager* manager = reader->read();
    qDebug() << "Elements in manager:";
    foreach(QString db, manager->elements()) {
        qDebug() << "\t\t" << db;
    }
    manager->rescan();
    qDebug() << "Elements in manager:";
    foreach(QString db, manager->elements()) {
        qDebug() << "\t\t" << db;
    }

    reader->write(manager);
    
    return 0;
}

int tagsRWTest() {
    QString path = "G:/Projects/Programming/db.xml";

    XmlTagDBReader* reader = new XmlTagDBReader();
    if (!reader->setup(path)) {
        return -1;
    }

    TagDB* db = reader->read();
    db->rescan();

    if (db->hasExtra()) {
        qDebug() << "Founded new files:";
        foreach(QString file, db->getExtra()) {
            qDebug() << "\t" << file;
        }
    }

    ConsoleTagDBReader* writer = new ConsoleTagDBReader();
    writer->write(db);
    reader->write(db);
    return 0;
}
