#pragma once

#include "Function.h"

/*!
 * \file testSortByProtocol.h
 * \brief Файл состоит из реализации методов класса тестирования функции sortByProtocol
*/

/*!
 * \class testSortByProtocol
 * \brief Класс тестирования функции sortByProtocol 
*/
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
