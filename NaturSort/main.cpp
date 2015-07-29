#include <QtCore/QCoreApplication>

#include "Testing.h"
#include "Function.h"
#include "In-Out.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	char flag;
	char temp[256]={};

	QStringList sorting, out;

	QMap<groupType, QStringList> gropingStr;

	printf("Run testing functions? y/n \n");
	scanf("%c", &flag);
	if(flag=='y')
	{
		testing();
	}

	printf("Enter the file name: \n");
	gets(temp);
	gets(temp);
	
	QString fileName(temp);

	sorting=read(fileName);

	gropingStr=groupForSort(sorting);

	out=sortGroupedString(gropingStr);

	fileName=fileName.remove(".txt");

	fileName+=QString("_out.txt");

	save(fileName, out);

	printf("\nSort files saved successfully. It has postfix \"_out\"");

	return a.exec();
}
