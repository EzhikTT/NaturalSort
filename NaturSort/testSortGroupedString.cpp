#include "testSortGroupedString.h"

testSortGroupedString::testSortGroupedString(void)
{
}

// Имеются строки во всех группах для сортировки
void testSortGroupedString::test1_allGroupsForSorting()
{
	QStringList test, ideal, check;
	QMap<groupType, QStringList> testMap;

	test<<"Hhhht.mpeg"<<"http://www.youtube.com/"<<"D:\\Install\\"<<"abbys@gmail.com"<<"Main.cpp"<<"679lolp"<<"kolp@rambler.ru"<<"890htr"<<"C:\\Programm files\\pop"<<"https://www.youtube.com/";
	ideal<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"C:\\Programm files\\pop"<<"D:\\Install\\"<<"Hhhht.mpeg"<<"Main.cpp"<<"abbys@gmail.com"<<"kolp@rambler.ru"<<"679lolp"<<"890htr";

	testMap=groupForSort(test);

	check=sortGroupedString(testMap);

	for(int i=0; i<check.count(); i++)
	{
		QCOMPARE(check.value(i), ideal.value(i));
	}
	QCOMPARE(check.count(), ideal.count());
}

// Не все группы содержат строки для сортировки
void testSortGroupedString::test2_notAllGroupsForSorting()
{
	QStringList test, ideal, check;
	QMap<groupType, QStringList> testMap;

	test<<"Hhhht.mpeg"<<"http://www.youtube.com/"<<"D:\\Install\\"<<"abbys@gmail.com"<<"kolp@rambler.ru"<<"C:\\Programm files\\pop"<<"https://www.youtube.com/";
	ideal<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"C:\\Programm files\\pop"<<"D:\\Install\\"<<"Hhhht.mpeg"<<"abbys@gmail.com"<<"kolp@rambler.ru";

	testMap=groupForSort(test);

	check=sortGroupedString(testMap);

	for(int i=0; i<check.count(); i++)
	{
		QCOMPARE(check.value(i), ideal.value(i));
	}
	QCOMPARE(check.count(), ideal.count());
}

void testSortGroupedString::test3_strangeSituation()
{
	QStringList test, ideal, check;
	QMap<groupType, QStringList> testMap;

	test<<"D:\\1.txt"<<"D:\\22_2.txt"<<"10_kps.xml"<<"11_rules.xml"<<"32_rules.txt"<<"01_test.xml"<<"02_fest.xml"<<"prc.xml"<<"01.xml"<<"_01.xml"<<"http://example.com"<<"htpp://example2.com";
	ideal<<"http://example.com"<<"htpp://example2.com"<<"D:\\1txt"<<"D:\\22_2.txt"<<"32_rules.txt"<<"1.xml"<<"1_test.xml"<<"2_fest.xml"<<"10_kps.xml"<<"11_rules.xml"<<"_01.xml"<<"prc.xml";

	testMap=groupForSort(test);

	check=sortGroupedString(testMap);

	for(int i=0; i<check.count(); i++)
	{
		QCOMPARE(check.value(i), ideal.value(i));
	}
	QCOMPARE(check.count(), ideal.count());
}

testSortGroupedString::~testSortGroupedString(void)
{
}
