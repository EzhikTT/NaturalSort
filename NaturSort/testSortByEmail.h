#pragma once

#include "Function.h"

class testSortByEmail:public QObject
{
	Q_OBJECT

public:
	testSortByEmail(void);
	~testSortByEmail(void);

private slots:

	// Строки уже отсортированы
	void test1_stringWereSorted();

	// Строки не отсортированы
	void test2_stringWereNotSorted();
};
