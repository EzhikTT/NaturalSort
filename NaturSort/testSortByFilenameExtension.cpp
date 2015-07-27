#include "testSortByFilenameExtension.h"

testSortByFilenameExtension::testSortByFilenameExtension(void)
{
}

// ������ ��� �������������
void testSortByFilenameExtension::test1_stringWereSorted()
{
	QStringList test, ideal;

	test<<"Test.fbx"<<"You.max"<<"Lolp.mp3"<<"Joup.avi"<<"Hhhht.mpeg"<<"Main.cpp"<<"Ops.obj";
	ideal<<"Test.fbx"<<"You.max"<<"Lolp.mp3"<<"Joup.avi"<<"Hhhht.mpeg"<<"Main.cpp"<<"Ops.obj";

	sortByFilenameExtension(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// ������ �� �������������
void testSortByFilenameExtension::test2_stringWereNotSorted()
{
	QStringList test, ideal;

	test<<"Ops.obj"<<"Hhhht.mpeg"<<"Lolp.mp3"<<"Test.fbx"<<"Joup.avi"<<"Main.cpp"<<"You.max";
	ideal<<"Test.fbx"<<"You.max"<<"Lolp.mp3"<<"Joup.avi"<<"Hhhht.mpeg"<<"Main.cpp"<<"Ops.obj";

	sortByFilenameExtension(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// ������� ������ � ������������ ������������
void testSortByFilenameExtension::test3_stringWhithUnknowExtention()
{
	QStringList test, ideal;

	test<<"Utr.iso"<<"Ops.obj"<<"Hhhht.mpeg"<<"Lolp.mp3"<<"Test.fbx"<<"Joup.avi"<<"Main.cpp"<<"You.max";
	ideal<<"Test.fbx"<<"You.max"<<"Lolp.mp3"<<"Joup.avi"<<"Hhhht.mpeg"<<"Main.cpp"<<"Ops.obj"<<"Utr.iso";

	sortByFilenameExtension(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}


testSortByFilenameExtension::~testSortByFilenameExtension(void)
{
}
