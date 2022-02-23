#include "ErrorHandler.h"

IErrorHandler* ErrorHandler::handler = NULL;

void ErrorHandler::setErrorHandler(IErrorHandler* errorHandler) {
    if (ErrorHandler::handler != NULL)
    {
        delete ErrorHandler::handler;
    }
    ErrorHandler::handler = errorHandler;
};

void ErrorHandler::error(QString message) {
    if (ErrorHandler::handler != NULL) {
        ErrorHandler::handler->show(message);
    }
};
