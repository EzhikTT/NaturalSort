#include "Testing.h"

/*!
 * \file Testing.cpp
 * \brief ���� ������� �� ���������� ������� ������������
*/

void testing()
{
	testGroupForSort tGFS;
	testSortByDisk tSBD;
	testSortByEmail tSBE;
	testSortByFilenameExtension tSBFE;
	testSortByLexeme tSBL;
	testSortByProtocol tSBP;
	testSortGroupedString tSGS;

	QTest::qExec(&tGFS); 
	QTest::qExec(&tSBD);
	QTest::qExec(&tSBE);
	QTest::qExec(&tSBFE);
	QTest::qExec(&tSBL);
	QTest::qExec(&tSBP);
	QTest::qExec(&tSGS); 
}