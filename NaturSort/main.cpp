#include <QtCore/QCoreApplication>

#include "Testing.h"
#include "Function.h"
#include "In-Out.h"

/*!
 * \file main.cpp
 * \brief ���� ������� �� ������� �������
*/


/*! 
* \fn int main(int argc, char *argv[])
* \brief ������� ��������� ����������� ������ ������������ � ���������
* \param[in] argc  ���������� ���������� ��������� ������
* \param[in] argv  ������ ���������� ��������� ������
* \return 0
*/
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	// ���������� ������� � ����������� �� ���������� ���������� ������
	// ������ ������������
	if(argc==2 && !strcmp(argv[1], "-t"))
	{
		testing();
	}
	// ������ �������� ��������� ����������
	else if(argc==3)
	{
		QStringList sort, out;
		QMap<groupType, QStringList> groupingStr;

		sort=read(QString(argv[1]));
		groupingStr=groupForSort(sort);
		out=sortGroupedString(groupingStr);
		write(QString(argv[2]), out);
	}
	// ������ ��� �������� ���������� ����������
	else
	{
		printf("Format command is incorrect.\n");
	}

	return a.exec();
}
