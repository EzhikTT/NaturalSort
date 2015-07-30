#include "testGroupForSort.h"

/*!
 * \file testGroupForSort.cpp
 * \brief Файл состоит из реализации методов класса тестирования функции groupForSort
*/

testGroupForSort::testGroupForSort(void)
{
}

// Содержатся строки для всех групп
void testGroupForSort::test1_containsStringsForAllGroups()
{
	QStringList testL;
	QMap<groupType, QStringList> testM;

	testL<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"C:\\Programm files\\pop"<<"D:\\Install\\"<<"Hhhht.mpeg"<<"Main.cpp"<<"679lolp"<<"kolp@rambler.ru"<<"abbys@gmail.com"<<"890htr";
	
	testM=groupForSort(testL);
	
	QCOMPARE(testM.value(protocol).value(0), QString("http://www.youtube.com/"));
	QCOMPARE(testM.value(protocol).value(1), QString("https://www.youtube.com/"));

	QCOMPARE(testM.value(disk).value(0), QString("C:\\Programm files\\pop"));
	QCOMPARE(testM.value(disk).value(1), QString("D:\\Install\\"));

	QCOMPARE(testM.value(filenameExtension).value(0), QString("Hhhht.mpeg"));
	QCOMPARE(testM.value(filenameExtension).value(1), QString("Main.cpp"));

	QCOMPARE(testM.value(email).value(0), QString("kolp@rambler.ru"));
	QCOMPARE(testM.value(email).value(1), QString("abbys@gmail.com"));

	QCOMPARE(testM.value(other).value(0), QString("679lolp"));
	QCOMPARE(testM.value(other).value(1), QString("890htr"));
}

// Содержатся строки для всех групп
void testGroupForSort::test2_notContainsStringsForAllGroups()
{
	QStringList testL;
	QMap<groupType, QStringList> testM;

	testL<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"Hhhht.mpeg"<<"Main.cpp"<<"kolp@rambler.ru"<<"abbys@gmail.com";
	
	testM=groupForSort(testL);
	
	QCOMPARE(testM.value(protocol).value(0), QString("http://www.youtube.com/"));
	QCOMPARE(testM.value(protocol).value(1), QString("https://www.youtube.com/"));

	QCOMPARE(testM.value(disk).count(), 0);

	QCOMPARE(testM.value(filenameExtension).value(0), QString("Hhhht.mpeg"));
	QCOMPARE(testM.value(filenameExtension).value(1), QString("Main.cpp"));

	QCOMPARE(testM.value(email).value(0), QString("kolp@rambler.ru"));
	QCOMPARE(testM.value(email).value(1), QString("abbys@gmail.com"));

	QCOMPARE(testM.value(other).count(), 0);
}

testGroupForSort::~testGroupForSort(void)
{
}
