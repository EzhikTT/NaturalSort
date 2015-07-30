#pragma once

#include "Function.h"

/*!
 * \file testSortByEmail.h
 * \brief Файл состоит из реализации методов класса тестирования функции sortByEmail
*/

/*!
 * \class testSortByEmail
 * \brief Класс тестирования функции sortByEmail 
*/
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
