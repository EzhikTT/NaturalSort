#pragma once

#include "Function.h"

/*!
 * \file testSortByDisk.h
 * \brief Файл состоит из реализации методов класса тестирования функции sortByDisk
*/

/*!
 * \class testSortByDisk
 * \brief Класс тестирования функции sortByDisk 
*/
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
