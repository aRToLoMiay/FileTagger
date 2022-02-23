#pragma once

#include "ErrorHandler.h"
#include "ConsoleErrorHandler.h"
#include "mainwindow.h"

#include <qapplication.h>

class FileTaggerApp {
public:
    FileTaggerApp(int argc, char* argv[]);
    ~FileTaggerApp();

    int exec();

protected:
    void init(int argc, char* argv[]);
    void setup();

private:
    QApplication* a;
    MainWindow* w;
};

