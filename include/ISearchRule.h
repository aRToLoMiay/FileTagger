#pragma once

#include "Tags.h"

class ISearchRule {
public:
    virtual bool isAppropriate(Tags* element) = 0;
};

//��������� ������� :
//- �������� ���� � ������������ � ���������� ����������
//- �� �������� ���� � ������������ � ���������� ����������
