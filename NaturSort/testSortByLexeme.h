#pragma once

#include "Function.h"

class testSortByLexeme:public QObject
{
	Q_OBJECT

public:
	testSortByLexeme(void);
	~testSortByLexeme(void);

private slots:	

	// ������ ��� �������������
	void test1_stringWereSorted();

	// ������ �������� � ���������, � �������� �����
	void test2_stringConsistOfLettersAndNumbers();	

	// ������ ������� ������ �� ����
	void test3_stringConsistOnlyOfLetters();

	// ������ ������� ������ �� ����
	void test4_stringConsistOnlyOfNumbers();

	// �� ��� ������ ����� �������� �����
	void test5_notAllStringsAreNumbers();

	// �� ��� ������ ����� ��������� �����
	void test6_notAllStringsAreLetters();
};
