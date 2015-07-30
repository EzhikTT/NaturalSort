#pragma once

#include "Function.h"

/*!
 * \file testSortByDisk.h
 * \brief ���� ������� �� ���������� ������� ������ ������������ ������� sortByDisk
*/

/*!
 * \class testSortByDisk
 * \brief ����� ������������ ������� sortByDisk 
*/
class testSortByDisk:public QObject
{
	Q_OBJECT

public:
	testSortByDisk(void);
	~testSortByDisk(void);

private slots:

	// ������ ��� �������������
	void test1_stringWereSorted();

	// ������ �� �������������
	void test2_stringWereNotSorted();
};
