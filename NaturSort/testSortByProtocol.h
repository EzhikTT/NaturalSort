#pragma once

#include "Function.h"

class testSortByProtocol:public QObject
{
	Q_OBJECT

public:
	testSortByProtocol(void);
	~testSortByProtocol(void);

private slots:

	// Строки уже отсортированы
	void test1_stringWereSorted();

	// Строки не отсортированы
	void test2_stringWereNotSorted();

	// Имеются строки, не принадлежащие перечислению с известными протоколами
	void test3_stringWhithUnknowProtocol();
};
