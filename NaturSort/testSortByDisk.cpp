#include "testSortByDisk.h"

testSortByDisk::testSortByDisk(void)
{
}

// Строки уже отсортированы
void testSortByDisk::test1_stringWereSorted()
{
	QStringList test, ideal;

	test<<"A:\\go-go"<<"C:\\Games\\GaMa"<<"C:\\Programm files\\pop"<<"D:\\Install\\"<<"F:\\"<<"F:\\Video\\";
	ideal<<"A:\\go-go"<<"C:\\Games\\GaMa"<<"C:\\Programm files\\pop"<<"D:\\Install\\"<<"F:\\"<<"F:\\Video\\";

	sortByDisk(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// Строки не отсортированы
void testSortByDisk::test2_stringWereNotSorted()
{
	QStringList test, ideal;

	test<<"C:\\Programm files\\pop"<<"A:\\go-go"<<"D:\\Install\\"<<"C:\\Games\\GaMa"<<"F:\\Video\\"<<"F:\\";
	ideal<<"A:\\go-go"<<"C:\\Games\\GaMa"<<"C:\\Programm files\\pop"<<"D:\\Install\\"<<"F:\\"<<"F:\\Video\\";

	sortByDisk(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

testSortByDisk::~testSortByDisk(void)
{
}
