#include "test_sort.h"

test_sort::test_sort(void)
{
}

void test_sort::test1_allGroupsForSorting()
{
	QStringList test, ideal, check;
	QMap<typeData, QStringList> testMap;

	test<<"Hhhht.mpeg"<<"http://www.youtube.com/"<<"D:\\Install\\"<<"abbys@gmail.com"<<"Main.cpp"<<"679lolp"<<"kolp@rambler.ru"<<"890htr"<<"C:\\Programm files\\pop"<<"https://www.youtube.com/";
	ideal<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"C:\\Programm files\\pop"<<"D:\\Install\\"<<"Hhhht.mpeg"<<"Main.cpp"<<"abbys@gmail.com"<<"kolp@rambler.ru"<<"679lolp"<<"890htr";

	testMap=groupForSort(test);

	check=sort(testMap);

	for(int i=0; i<check.count(); i++)
	{
		QCOMPARE(check.value(i), ideal.value(i));
	}
	QCOMPARE(check.count(), ideal.count());
}

void test_sort::test2_notAllGroupsForSorting()
{
	QStringList test, ideal, check;
	QMap<typeData, QStringList> testMap;

	test<<"Hhhht.mpeg"<<"http://www.youtube.com/"<<"D:\\Install\\"<<"abbys@gmail.com"<<"kolp@rambler.ru"<<"C:\\Programm files\\pop"<<"https://www.youtube.com/";
	ideal<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"C:\\Programm files\\pop"<<"D:\\Install\\"<<"Hhhht.mpeg"<<"abbys@gmail.com"<<"kolp@rambler.ru";

	testMap=groupForSort(test);

	check=sort(testMap);

	for(int i=0; i<check.count(); i++)
	{
		QCOMPARE(check.value(i), ideal.value(i));
	}
	QCOMPARE(check.count(), ideal.count());
}

test_sort::~test_sort(void)
{
}
