#pragma once

#include "Function.h"

class testGroupForSort:public QObject
{
	Q_OBJECT

public:
	testGroupForSort(void);
	~testGroupForSort(void);

private slots:

	// ���������� ������ ��� ���� �����
	void test1_containsStringsForAllGroups();

	// ����������� ������ �� ��� ���� �����
	void test2_notContainsStringsForAllGroups();
};
