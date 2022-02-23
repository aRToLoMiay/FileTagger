#pragma once
#include "IErrorHandler.h"

#include <qmessagebox.h>

class QMessageErrorHandler :
    public IErrorHandler
{
public:
    virtual void show(QString message) override {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(message);
        msgBox.exec();
    };
};
