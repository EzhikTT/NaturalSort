#pragma once

#include "Function.h"

class testSortByFilenameExtention:public QObject
{
	Q_OBJECT

public:
	testSortByFilenameExtention(void);
	~testSortByFilenameExtention(void);

private slots:

	// Строки уже отсортированы
	void test1_stringWereSorted();

	// Строки не отсортированы
	void test2_stringWereNotSorted();

	// Имеются строки с неизвестными расширениями
	void test3_stringWhithUnknowExtention();
};
