#pragma once

#include "Function.h"

class testSortByDisk:public QObject
{
	Q_OBJECT

public:
	testSortByDisk(void);
	~testSortByDisk(void);

private slots:

	// Строки уже отсортированы
	void test1_stringWereSorted();

	// Строки не отсортированы
	void test2_stringWereNotSorted();
};
