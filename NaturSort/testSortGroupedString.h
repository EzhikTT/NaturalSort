#pragma once

#include "Function.h"

/*!
 * \file testSortGroupedString.h
 * \brief Файл состоит из класса тестирования функции sortGroupedString
*/

/*!
 * \class testSortGroupedString
 * \brief Класс тестирования функции sortGroupedString 
*/

class testSortGroupedString:public QObject
{
	Q_OBJECT

public:
	testSortGroupedString(void);
	~testSortGroupedString(void);

private slots:

	// Имеются строки во всех группах для сортировки
	void test1_allGroupsForSorting();

	// Не все группы содержат строки для сортировки
	void test2_notAllGroupsForSorting();

	// Спорная ситуация 
	void test3_strangeSituation();
};
