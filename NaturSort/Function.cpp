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

	for(int i=0; i<input.count(); i++)
	{
		if(input.value(i).contains(":\\"))
		{
			res[disk]<<input.value(i);
		}
		else if(input.value(i).contains("@") && (input.value(i).lastIndexOf(".")==2 ||input.value(i).lastIndexOf(".")==1))
		{
			res[email]<<input.value(i);
		}
		else if(input.value(i).contains("://") || input.value(i).contains(":") || input.value(i).contains("ntp") || (input.value(i).contains("@") && input.value(i).indexOf(":", input.value(i).indexOf("@"))!=-1))
		{
			res[protocol]<<input.value(i);
		}
		else if(input.value(i).contains(".") && input.value(i).count(".")==1)
		{
			res[filenameExtention]<<input.value(i);
		}
		else
		{
			res[other]<<input.value(i);
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