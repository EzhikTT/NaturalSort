#include <QtCore/QCoreApplication>

#include "Testing.h"
#include "Function.h"
#include "In-Out.h"

/*!
 * \file main.cpp
 * \brief Файл состоит из главной функции
*/


/*! 
* \fn int main(int argc, char *argv[])
* \brief Функция выполняет выполняется запуск тестирования и программы
* \param[in] argc  Количество аргументов командной строки
* \param[in] argv  Список аргументов командной строки
* \return 0
*/
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	// Выполнение функции в зависимости от параметров коммандной строки
	// Запуск тестирования
	if(argc==2 && !strcmp(argv[1], "-t"))
	{
		testing();
	}
	// Запуск основной программы сортировки
	else if(argc==3)
	{
		QStringList sort, out;
		QMap<groupType, QStringList> groupingStr;

		sort=read(QString(argv[1]));
		groupingStr=groupForSort(sort);
		out=sortGroupedString(groupingStr);
		write(QString(argv[2]), out);
	}
	// Ошибка при неверном количестве аргументов
	else
	{
		printf("Format command is incorrect.\n");
	}

	return a.exec();
}
