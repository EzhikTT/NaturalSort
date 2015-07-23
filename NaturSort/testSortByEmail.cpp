#include "testSortByEmail.h"

testSortByEmail::testSortByEmail(void)
{
}

// Строки уже отсортированы
void testSortByEmail::test1_stringWereSorted()
{
	QStringList test, ideal;

	test<<"abbys@gmail.com"<<"plop@gmail.com"<<"tesrt@hotmail.com"<<"grymb@mail.ru"<<"kolp@rambler.ru"<<"moon@yandex.ru"<<"moop@yandex.ru";
	ideal<<"abbys@gmail.com"<<"plop@gmail.com"<<"tesrt@hotmail.com"<<"grymb@mail.ru"<<"kolp@rambler.ru"<<"moon@yandex.ru"<<"moop@yandex.ru";

	sortByEmail(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// Строки не отсортированы
void testSortByEmail::test2_stringWereNotSorted()
{
	QStringList test, ideal;

	test<<"moop@yandex.ru"<<"plop@gmail.com"<<"tesrt@hotmail.com"<<"grymb@mail.ru"<<"moon@yandex.ru"<<"yopy@rambler.ru"<<"kolp@rambler.ru"<<"abbys@gmail.com";
	ideal<<"abbys@gmail.com"<<"plop@gmail.com"<<"tesrt@hotmail.com"<<"grymb@mail.ru"<<"kolp@rambler.ru"<<"yopy@rambler.ru"<<"moon@yandex.ru"<<"moop@yandex.ru";

	sortByEmail(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

testSortByEmail::~testSortByEmail(void)
{
}
