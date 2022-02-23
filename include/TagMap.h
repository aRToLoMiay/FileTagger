#pragma once

#include "ISearchRule.h"
#include "Tags.h"

#include <qmap.h>

template<class T>
class TagMap
{
public:
    TagMap() {
        // DO NOTHING
    }
    TagMap(const TagMap& copy) {
        init(copy.elems);
    }
    ~TagMap() {
        // DO NOTHING
    }

    TagMap* getAppropriated(ISearchRule* rule) {
        TagMap* result = new TagMap();

        foreach(Tags* tags, map.values()) {
            if (rule->isAppropriate(tags)) {
                result->map.insert(map.key(tags), tags);
            }
        }
        return result;
    }
    TagMap* getAppropriated(QList<ISearchRule*> rules) {
        TagMap<T>* result = new TagMap();
        foreach(Tags* tags, map.values()) {
            bool flag = true;
            foreach(ISearchRule* rule, rules) {
                if (!rule->isAppropriate(tags)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result->map.insert(map.key(tags), tags);
            }
        }
        return result;
    }

    QMap<T, Tags*> map;

protected:
    void init(QMap<Tags*, T> elems) {
        this->map.clear();
        this->map.insert(elems);
    }
};
