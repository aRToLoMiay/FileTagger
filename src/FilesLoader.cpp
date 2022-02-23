#include "FilesLoader.h"

#include "ErrorHandler.h"

#include <qdebug.h>
void FilesLoader::print() {
    qDebug() << "Files:\n";
    if (files.size() == 0) {
        qDebug() << "\t--empty--";
    }
    foreach(QString file, files) {
        qDebug() << "\t" << file;
    }
}

FilesLoader::FilesLoader() {
    // DO NOTHING
}

FilesLoader::FilesLoader(QString path) {
    setPath(path);
}

FilesLoader::~FilesLoader() {
    // DO NOTHING
}

void FilesLoader::setPath(QString path) {
    if (path.contains("\\")) {
        path.replace("\\", "/");
    }
    this->path = path;
    update();
}

QString FilesLoader::getPath() { return path; }

QStringList FilesLoader::getFiles() { return files; }

// return files in loader and in list
QStringList FilesLoader::getDuplicates(QStringList files) {
    QStringList result;
    foreach(QString file, files) {
        if (this->files.contains(file)) {
            result.append(file);
        }
    }
    return result;
}

// return files in loader, but not in list
QStringList FilesLoader::getMissing(QStringList files) {
    QStringList result;
    foreach(QString file, this->files) {
        if (!files.contains(file)) {
            result.append(file);
        }
    }
    return result;
}

// return files not in loader, but in list
QStringList FilesLoader::getExtra(QStringList files) {
    QStringList result;
    foreach(QString file, files) {
        if (!this->files.contains(file)) {
            result.append(file);
        }
    }
    return result;
}

void FilesLoader::update() {
    if (path == "") {
        ErrorHandler::error(QObject::tr("Задан некорректный путь к дирректории: ") + path);
        return;
    }

    findDirFiles(path);
}

void FilesLoader::findDirFiles(QString path) {
    QDir dir(path);
    if (!dir.exists()) {
        ErrorHandler::error(QObject::tr("Дирректория по выбранному пути не существет: ") + path);
        return;
    }

    dir.setFilter(QDir::Files | QDir::AllDirs);
    dir.setSorting(QDir::Name);
    QFileInfoList list = dir.entryInfoList();

    foreach(QFileInfo finfo, list) {
        if (finfo.isFile()) {
            files.append(finfo.canonicalFilePath().replace(this->path + "/", ""));
        }
        else if (finfo.isDir()) {
            if ((finfo.fileName() != "..") && (finfo.fileName() != ".")) {
                findDirFiles(finfo.absoluteFilePath());
            }
        }
    }
}
