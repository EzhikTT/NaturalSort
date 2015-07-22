#pragma once

//#include "Libs.h"
#include "Function.h"
//#include <QTest>
//#include <QObject>


class test_sort:public QObject
{
	Q_OBJECT

public:
	test_sort(void);
	~test_sort(void);

private slots:

	// Имеются строки во всех группах для сортировки
	void test1_allGroupsForSorting();

	// Не все группы содержат строки для сортировки
	void test2_notAllGroupsForSorting();
};
