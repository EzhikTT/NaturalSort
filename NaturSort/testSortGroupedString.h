#pragma once

//#include "Libs.h"
#include "Function.h"
//#include <QTest>
//#include <QObject>


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
};
