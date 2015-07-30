#pragma once

#include "Function.h"

/*!
 * \file testSortByEmail.h
 * \brief ���� ������� �� ���������� ������� ������ ������������ ������� sortByEmail
*/

/*!
 * \class testSortByEmail
 * \brief ����� ������������ ������� sortByEmail 
*/
class testSortByEmail:public QObject
{
	Q_OBJECT

public:
	testSortByEmail(void);
	~testSortByEmail(void);

private slots:

	// ������ ��� �������������
	void test1_stringWereSorted();

	// ������ �� �������������
	void test2_stringWereNotSorted();
};
