#pragma once

#include "Function.h"

class testSortByFilenameExtension:public QObject
{
	Q_OBJECT

public:
	testSortByFilenameExtension(void);
	~testSortByFilenameExtension(void);

private slots:

	// Строки уже отсортированы
	void test1_stringWereSorted();

	// Строки не отсортированы
	void test2_stringWereNotSorted();

	// Имеются строки с неизвестными расширениями
	void test3_stringWhithUnknowExtention();
};
