#pragma once

#include "TagMap.h"

template<class T>
class ITagMapReader {
public:
    virtual TagMap<T>* get() = 0;
};
