#pragma once

#include "Function.h"

/*!
 * \file testSortByProtocol.h
 * \brief ���� ������� �� ���������� ������� ������ ������������ ������� sortByProtocol
*/

/*!
 * \class testSortByProtocol
 * \brief ����� ������������ ������� sortByProtocol 
*/
class testSortByProtocol:public QObject
{
	Q_OBJECT

public:
	testSortByProtocol(void);
	~testSortByProtocol(void);

private slots:

	// ������ ��� �������������
	void test1_stringWereSorted();

	// ������ �� �������������
	void test2_stringWereNotSorted();

	// ������� ������, �� ������������� ������������ � ���������� �����������
	void test3_stringWhithUnknowProtocol();
};
