#pragma once

#include "Function.h"

class testSortByFilenameExtension:public QObject
{
	Q_OBJECT

public:
	testSortByFilenameExtension(void);
	~testSortByFilenameExtension(void);

private slots:

	// ������ ��� �������������
	void test1_stringWereSorted();

	// ������ �� �������������
	void test2_stringWereNotSorted();

	// ������� ������ � ������������ ������������
	void test3_stringWhithUnknowExtention();
};
