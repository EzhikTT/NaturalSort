#pragma once

#include "Function.h"

class testSortByEmail:public QObject
{
	Q_OBJECT

public:
	testSortByEmail(void);
	~testSortByEmail(void);

private slots:

	// ������ ��� �������������
	void test1_stringWereSorted();

	// ������ �� �������������
	void test2_stringWereNotSorted();
};
