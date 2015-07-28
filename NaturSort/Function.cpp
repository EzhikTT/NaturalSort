#include "Function.h"


QStringList sortGroupedString(QMap<groupType, QStringList> &sort)
{
	QStringList res;

	return res;
}


void sortByLexeme(QStringList &sortList)
{
}


QMap<groupType, QStringList> groupForSort(QStringList &input)
{
	QMap<groupType, QStringList> res;

	QString temp;

	for(int i=0; i<input.count(); i++)
	{
		temp=input[i];

		if(temp.contains(":\\"))
		{
			res[disk]<<temp;
		}
		else if(temp.contains("@") && temp.count(".")==1)
		{
			res[email]<<temp;
		}
		else if(temp.contains("://") || temp.contains(":") || temp.contains("ntp") || (temp.contains("@") && temp.indexOf(":", temp.indexOf("@"))!=-1))
		{
			res[protocol]<<temp;
		}
		else if(temp.contains(".") && temp.count(".")==1)
		{
			res[filenameExtention]<<temp;
		}
		else
		{
			res[other]<<temp;
		}
	}

	return res;
}

void sortByProtocol(QStringList &sortList)
{
}


void sortByDisk(QStringList &sortList)
{
}


void sortByFilenameExtension(QStringList &sortList)
{
}


void sortByEmail(QStringList &sortList)
{
}