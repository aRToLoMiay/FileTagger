#pragma once

#include "ITagDBReader.h"

class ConsoleTagDBReader :
    public ITagDBReader
{
public:
    ConsoleTagDBReader() {};
    ~ConsoleTagDBReader();

    virtual TagDB* read() override;
    virtual void write(TagDB* db) override;

protected:
    void writeTagMap(TagMap<QString>* tm);
    void writeTags(Tags* tags);
};
