#include "testSortByFilenameExtention.h"

testSortByFilenameExtention::testSortByFilenameExtention(void)
{
}

// ������ ��� �������������
void testSortByFilenameExtention::test1_stringWereSorted()
{
	QStringList test, ideal;

	test<<"Test.fbx"<<"You.max"<<"Lolp.mp3"<<"Joup.avi"<<"Hhhht.mpeg"<<"Main.cpp"<<"Ops.obj";
	ideal<<"Test.fbx"<<"You.max"<<"Lolp.mp3"<<"Joup.avi"<<"Hhhht.mpeg"<<"Main.cpp"<<"Ops.obj";

	sortByFilenameExtention(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// ������ �� �������������
void testSortByFilenameExtention::test2_stringWereNotSorted()
{
	QStringList test, ideal;

	test<<"Ops.obj"<<"Hhhht.mpeg"<<"Lolp.mp3"<<"Test.fbx"<<"Joup.avi"<<"Main.cpp"<<"You.max";
	ideal<<"Test.fbx"<<"You.max"<<"Lolp.mp3"<<"Joup.avi"<<"Hhhht.mpeg"<<"Main.cpp"<<"Ops.obj";

	sortByFilenameExtention(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// ������� ������ � ������������ ������������
void testSortByFilenameExtention::test3_stringWhithUnknowExtention()
{
	QStringList test, ideal;

	test<<"Utr.iso"<<"Ops.obj"<<"Hhhht.mpeg"<<"Lolp.mp3"<<"Test.fbx"<<"Joup.avi"<<"Main.cpp"<<"You.max";
	ideal<<"Test.fbx"<<"You.max"<<"Lolp.mp3"<<"Joup.avi"<<"Hhhht.mpeg"<<"Main.cpp"<<"Ops.obj"<<"Utr.iso";

	sortByFilenameExtention(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}


testSortByFilenameExtention::~testSortByFilenameExtention(void)
{
}
