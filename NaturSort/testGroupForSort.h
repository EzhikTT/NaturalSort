#pragma once

#include "Function.h"

class testGroupForSort:public QObject
{
	Q_OBJECT

public:
	testGroupForSort(void);
	~testGroupForSort(void);

private slots:

	// Содержатся строки для всех групп
	void test1_containsStringsForAllGroups();

	// Содержаться строки не для всех групп
	void test2_notContainsStringsForAllGroups();
};
