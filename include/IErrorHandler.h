#pragma once

#include <qstring.h>

class IErrorHandler {
public:
    virtual void show(QString message) = 0;
};