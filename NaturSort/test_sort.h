#pragma once

//#include "Libs.h"
#include "Function.h"
//#include <QTest>
//#include <QObject>


class test_sort:public QObject
{
	Q_OBJECT

public:
	test_sort(void);
	~test_sort(void);

private slots:

	// ������� ������ �� ���� ������� ��� ����������
	void test1_allGroupsForSorting();

	// �� ��� ������ �������� ������ ��� ����������
	void test2_notAllGroupsForSorting();
};
