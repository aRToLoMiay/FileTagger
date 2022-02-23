#pragma once

#include "ITagMapReader.h"

template<class T>
class TestTagMapReader :
    public ITagMapReader<T>
{
public:
    TestTagMapReader();
    ~TestTagMapReader();

    virtual TagMap<T>* get() override;

    void setNum(int num);

protected:
    int num;
};

// REALISATION //

template<class T>
TestTagMapReader<T>::TestTagMapReader() {
    // DO NOTHING
}

template<class T>
TestTagMapReader<T>::~TestTagMapReader() {
    // DO NOTHING
}

template<class T>
TagMap<T>* TestTagMapReader<T>::get() {
    TagMap<T>* result = new TagMap();
    for (int i = 0; i < num; i++) {
        int k = i + 1;
        TMElem* elem = new TMElem();
        elem->setElement(new int(k));
        for (int j = 2; j <= k / 2; j++) {
            if (k % j == 0) {
                elem->addTag(QString::number(j));
            }
        }
        result->elems.append(elem);
    }
    return result;
}

template<class T>
void TestTagMapReader<T>::setNum(int num) { this->num = num; }
