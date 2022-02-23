#pragma once

#include "IErrorHandler.h"

class ErrorHandler
{
public:
    void test() { ErrorHandler::handler = NULL; };

    static void setErrorHandler(IErrorHandler* errorHandler);
    static void error(QString message);

protected:
private:
    ErrorHandler() {};
    ~ErrorHandler() {};

    static IErrorHandler* handler;
};
