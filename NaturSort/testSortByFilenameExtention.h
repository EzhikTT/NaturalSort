#pragma once

#include "Function.h"

class testSortByFilenameExtention:public QObject
{
	Q_OBJECT

public:
	testSortByFilenameExtention(void);
	~testSortByFilenameExtention(void);

private slots:

	// ������ ��� �������������
	void test1_stringWereSorted();

	// ������ �� �������������
	void test2_stringWereNotSorted();

	// ������� ������ � ������������ ������������
	void test3_stringWhithUnknowExtention();
};
