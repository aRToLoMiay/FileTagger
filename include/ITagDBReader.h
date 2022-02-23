#pragma once

#include "TagDB.h"

class ITagDBReader {
public:
    virtual TagDB* read() = 0;
    virtual void write(TagDB* db) = 0;
};
