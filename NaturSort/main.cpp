#include <QtCore/QCoreApplication>

#include "Testing.h"
#include "Function.h"
#include "In-Out.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	/*QStringList test, out;

	test<<"D:\\1.txt"<<"D:\\22_2.txt"<<"10_kps.xml"<<"11_rules.xml"<<"32_rules.txt"<<"01_test.xml"<<"02_fest.xml"<<"prc.xml"<<"01.xml"<<"_01.xml"<<"http://example.com"<<"htpp://example2.com";

	QMap<groupType, QStringList> groupingStr;

	//sort=read(QString(argv[1]));
	groupingStr=groupForSort(test);
	out=sortGroupedString(groupingStr);
	write(QString("testOut.txt"), out);*/

	if(argc==2 && !strcmp(argv[1], "-t"))
	{
		testing();
	}
	else if(argc==3)
	{
		QStringList sort, out;
		QMap<groupType, QStringList> groupingStr;

		sort=read(QString(argv[1]));
		groupingStr=groupForSort(sort);
		out=sortGroupedString(groupingStr);
		write(QString(argv[2]), out);
	}
	else
	{
		printf("Format command is incorrect.\n");
	}

	return a.exec();
}
