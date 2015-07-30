#pragma once

#include "Function.h"

/*!
 * \file testGroupForSort.h
 * \brief Файл состоит из реализации методов класса тестирования функции groupForSort
*/

/*!
 * \class testGroupForSort
 * \brief Класс тестирования функции groupForSort 
*/

class testGroupForSort:public QObject
{
	Q_OBJECT

public:
	testGroupForSort(void);
	~testGroupForSort(void);

private slots:

	// Содержатся строки для всех групп
	void test1_containsStringsForAllGroups();

	// Содержаться строки не для всех групп
	void test2_notContainsStringsForAllGroups();
};
