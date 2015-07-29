#include "testSortByLexeme.h"

testSortByLexeme::testSortByLexeme(void)
{
}

// Строки уже отсортированы
void testSortByLexeme::test1_stringWereSorted(void)
{
	QStringList test, ideal;

	test<<"34bbn"<<"76nut"<<"5674lopl"<<"5674moon"<<"Klio87"<<"Klio888";
	ideal<<"34bbn"<<"76nut"<<"5674lopl"<<"5674moon"<<"Klio87"<<"Klio888";

	sortByLexeme(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// Строки содержат и буквенные, и цифровые части
void testSortByLexeme::test2_stringConsistOfLettersAndNumbers(void)
{
	QStringList test, ideal;

	test<<"Klio888"<<"34bbn"<<"5674moon"<<"76nut"<<"5674lopl"<<"Klio87";
	ideal<<"34bbn"<<"76nut"<<"5674lopl"<<"5674moon"<<"Klio87"<<"Klio888";

	sortByLexeme(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// Строки состоят только из букв
void testSortByLexeme::test3_stringConsistOnlyOfLetters(void)
{
	QStringList test, ideal;

	test<<"Klio"<<"moon"<<"nut"<<"Kli"<<"lopl"<<"bbn";
	ideal<<"bbn"<<"Kli"<<"Klio"<<"lopl"<<"moon"<<"nut";

	sortByLexeme(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// Строки состоят только из цифр
void testSortByLexeme::test4_stringConsistOnlyOfNumbers(void)
{
	QStringList test, ideal;

	test<<"7640"<<"67"<<"33"<<"666"<<"7896";
	ideal<<"33"<<"67"<<"666"<<"7640"<<"7896";

	sortByLexeme(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// Не все строки имеют цифровую часть
void testSortByLexeme::test5_notAllStringsAreNumbers(void)
{
	QStringList test, ideal;

	test<<"34bbn"<<"Klipp"<<"5674lopl"<<"Klio"<<"76nut"<<"5674moon";
	ideal<<"34bbn"<<"76nut"<<"5674lopl"<<"5674moon"<<"Klio"<<"Klipp";

	sortByLexeme(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// Не все строки имеют буквенную часть
void testSortByLexeme::test6_notAllStringsAreLetters(void)
{
	QStringList test, ideal;

	test<<"768"<<"Klio888"<<"3454"<<"87";
	ideal<<"87"<<"768"<<"3454"<<"Klio888";

	sortByLexeme(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

testSortByLexeme::~testSortByLexeme(void)
{
}
