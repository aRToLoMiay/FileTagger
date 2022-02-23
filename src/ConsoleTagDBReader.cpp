#include "ConsoleTagDBReader.h"

#include <qdebug.h>
#include <QTextStream>

QTextStream cout(stdout);
QTextStream cin(stdin);

TagDB* ConsoleTagDBReader::read() {
    TagDB* result = new TagDB();
    cout << "Console TadDB input NOT implemented.\n";
    return result;
}

void ConsoleTagDBReader::write(TagDB* db) {
    cout << "TagDB output:";
    cout << "\n\tname: " << db->getName();
    cout << "\n\tpath: " << db->getPath();
    writeTagMap(db->getTM());
}

void ConsoleTagDBReader::writeTagMap(TagMap<QString>* tm) {
    cout << "\n\tTagMap: ";
    if (tm == NULL) {
        cout << "\n\t\tNULL";
        return;
    }

    foreach(QString path, tm->map.keys()) {
        cout << "\n\t\tpath: " << path;
        writeTags(tm->map.value(path));
    }
}

void ConsoleTagDBReader::writeTags(Tags* tags) {
    cout << "\n\t\tTags:";
    foreach(QString tag, tags->getTags()) {
        cout << "\n\t\t\t" << tag;
    }
}
