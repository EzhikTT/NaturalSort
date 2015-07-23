#pragma once

#include "Function.h"

class testSortByLexeme:public QObject
{
	Q_OBJECT

public:
	testSortByLexeme(void);
	~testSortByLexeme(void);

private slots:	

	// Строки уже отсортированы
	void test1_stringWereSorted();

	// Строки содержат и буквенные, и цифровые части
	void test2_stringConsistOfLettersAndNumbers();	

	// Строки состоят только из букв
	void test3_stringConsistOnlyOfLetters();

	// Строки состоят только из цифр
	void test4_stringConsistOnlyOfNumbers();

	// Не все строки имеют цифровую часть
	void test5_notAllStringsAreNumbers();

	// Не все строки имеют буквенную часть
	void test6_notAllStringsAreLetters();
};
