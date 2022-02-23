#include "FileTaggerApp.h"


FileTaggerApp::FileTaggerApp(int argc, char* argv[])
{
    init(argc, argv);
    setup();
}

FileTaggerApp:: ~FileTaggerApp() {
    if (a != NULL) {
        delete a;
    }
    if (w != NULL) {
        delete w;
    }
}

int FileTaggerApp::exec() {
    w->show();
    return a->exec();
}

void FileTaggerApp::init(int argc, char* argv[]) {
    a = new QApplication(argc, argv);
    w = new MainWindow();
}

void FileTaggerApp::setup() {
    ErrorHandler::setErrorHandler(new ConsoleErrorHandler());
}
