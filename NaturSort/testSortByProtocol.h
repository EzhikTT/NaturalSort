#pragma once

#include "Function.h"

class testSortByProtocol:public QObject
{
	Q_OBJECT

public:
	testSortByProtocol(void);
	~testSortByProtocol(void);

private slots:

	// ������ ��� �������������
	void test1_stringWereSorted();

	// ������ �� �������������
	void test2_stringWereNotSorted();

	// ������� ������, �� ������������� ������������ � ���������� �����������
	void test3_stringWhithUnknowProtocol();
};
