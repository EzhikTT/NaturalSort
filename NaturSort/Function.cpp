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
	QMap<groupType, QStringList> res;	// Результирующая карта с распредленными строка по группам

	QString temp;	// Временная для текущей распределяемой строки

	// Цицл для распределения строк по группам 
	for(int i=0; i<input.count(); i++)
	{
		// Загрузка в бущер текущей строки для сортировки
		temp=input[i];

		// Условие для групп устройсв хранения
		if(temp.contains(":\\"))
		{
			res[disk]<<temp;
		}
		// Условие для группы e-mail адресов
		else if(temp.contains("@") && temp.count(".")==1)
		{
			res[email]<<temp;
		}
		// Условие для группы протоколов доступа
		else if(temp.contains("://") || temp.contains(":") || temp.contains("ntp") || (temp.contains("@") && temp.indexOf(":", temp.indexOf("@"))!=-1))
		{
			res[protocol]<<temp;
		}
		// Условие для группы расширений файлов
		else if(temp.count(".")==1)
		{
			res[filenameExtention]<<temp;
		}
		// Условие для строк, не попавших ни в одну из групп
		else
		{
			res[other]<<temp;
		}
	}

	// Возвращение карты с группировкой строк
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