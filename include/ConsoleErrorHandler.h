#pragma once

#include "IErrorHandler.h"

#include <qdebug.h>

class ConsoleErrorHandler :
    public IErrorHandler
{
public:
    virtual void show(QString message) override {
        qWarning() << "[!] Error found:\n" << message;
    };
};
