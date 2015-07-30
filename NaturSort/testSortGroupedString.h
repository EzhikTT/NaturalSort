#pragma once

#include "Function.h"

/*!
 * \file testSortGroupedString.h
 * \brief ���� ������� �� ������ ������������ ������� sortGroupedString
*/

/*!
 * \class testSortGroupedString
 * \brief ����� ������������ ������� sortGroupedString 
*/

class testSortGroupedString:public QObject
{
	Q_OBJECT

public:
	testSortGroupedString(void);
	~testSortGroupedString(void);

private slots:

	// ������� ������ �� ���� ������� ��� ����������
	void test1_allGroupsForSorting();

	// �� ��� ������ �������� ������ ��� ����������
	void test2_notAllGroupsForSorting();

	// ������� �������� 
	void test3_strangeSituation();
};
