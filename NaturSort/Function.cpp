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
	// Карта для хранения адресов по доменам 
	// Ключ карты - домен, значения - список адресов этого домена
	QMap<QString, QStringList> sortingMap;	

	QStringList res;	// Результирующий лист

	QStringList sortingKey; // Лист для сортировки ключей

	QString temp; // Буфер для текущей обрабатываемой строки

	QString buf; // Буфер для ключа - домена

	QString str; // Буфер для одного из значений ключа - имени адреса

	QString aIter; // Буфер для ключа при формировании выходного списка

	QString aIterKlein; // Буфер для строки из списка для каждого 

	// Заполнение карты адресами
	for(int i=0; i<sortList.count(); i++)
	{
		// Загрузка в бущер текущей строки для сортировки
		temp=sortList[i];
		
		// Получение домена
		buf=temp.section("@", 1);

		// Получение имени
		str=temp.remove(QString("@")+buf);

		// Заполнение значение карты или создание поля для ключа
		if(sortingMap.contains(buf))
		{
			sortingMap[buf]<<str;
		}
		else
		{ 
			sortingMap.insert(buf, QStringList(str));
		}
	}

	QMap<QString, QStringList>::iterator it=sortingMap.begin();

	// Сортировка значений для каждого ключа
	for(;it!=sortingMap.end(); it++)
	{
		sortByLexeme(it.value());
	}

	// Записей ключей в лист
	it=sortingMap.begin();
	for(;it!=sortingMap.end(); it++)
	{
		sortingKey<<it.key();
	}

	// Сортировка ключей
	sortByLexeme(sortingKey);

	// Заполнение выходного листа
	for(int j=0; j<sortingKey.count(); j++)
	{
		// Загрузка в бущер текущей строки для улюча
		aIter=sortingKey[j];

		// Загрузка в выходной лист значений для определенного ключа 
		for(int k=0; k<sortingMap[aIter].count(); k++)
		{
			// Загрузка в бущер текущей строки для сортировки
			aIterKlein=sortingMap[aIter][k]+"@"+aIter;

			// Добавление строки в выходной лист
			res<<aIterKlein;
		}
	}

	// Замена данного листа на возвращаемый
	sortList=res;
}