#pragma once

#include "SearchRuleFabric.h"
#include "TagMap.h"
#include "Tags.h"

#include "qdebug.h"
#include "qstring.h"

typedef TagMap<int> TestTM;

void searchRulesTest();

namespace {
    TestTM* createTestsedTagMap(int num) {
        TestTM* result = new TestTM();
        for (int i = 0; i < num; i++) {
            int k = i + 1;
            Tags* tags = new Tags();
            for (int j = 2; j <= k / 2; j++) {
                if (k % j == 0) {
                    tags->addTag(QString::number(j));
                }
            }
            result->map.insert(k, tags);
        }
        return result;
    }

    void printTagMap(TestTM* tm) {
        foreach(int key, tm->map.keys()) {
            qDebug() << "  " << key << " : " << tm->map.value(key)->getTags();
        }
    }
};

void searchRulesTest() {
    qDebug() << "==== Search Rules Test ====";
    TestTM* tm = createTestsedTagMap(15);
    qDebug() << "Started tag map :";
    printTagMap(tm);

    QString tag = "2";

    qDebug() << "Contained tag \"" << tag << "\" :";
    printTagMap(tm->getAppropriated(SearchRuleFabric::get(SearchRuleFabric::CONTAIN, tag)));
    qDebug() << "Uncontained tag \"" << tag << "\" :";
    printTagMap(tm->getAppropriated(SearchRuleFabric::get(SearchRuleFabric::UNCONTAIN, tag)));
    qDebug() << "Contain all elements :";
    printTagMap(tm->getAppropriated(SearchRuleFabric::get(SearchRuleFabric::ALL_CONTAIN)));
    qDebug() << "Contain no elements :";
    printTagMap(tm->getAppropriated(SearchRuleFabric::get(SearchRuleFabric::NOTHING_CONTAIN)));

    qDebug() << "   =     End Test      =";
}