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
	// Карта для хранения ссылок по протоколу доступа
	// Ключ карты - имя , значения - список путь
	QMap<protocolType, QStringList> sortingMap;

	QStringList res;	// Результирующий лист

	QString temp; // Буфер для текущей обрабатываемой строки

	QString buf; // Буфер для ключа - домена

	QString str; // Буфер для одного из значений ключа - имени адреса

	QString aIterKlein; // Буфер для строки из списка для каждого 

	// Заполнение карты путей
	for(int i=0; i<sortList.count(); i++)
	{
		// Загрузка в бущер текущей строки для сортировки
		temp=sortList[i];

		// Условия для разных протоколов доступа
		if(temp.contains("DHCP"))
		{
			// Получение адреса
			str=temp.remove(QString("DHCP:"));

			// Заполнение значение карты
			sortingMap[dhcp]<<temp;
		}
		else if(temp.contains("DNS"))
		{
			// Получение адреса
			str=temp.remove(QString("DNS:"));

			// Заполнение значение карты
			sortingMap[dns]<<temp;
		}
		else if(temp.contains("ftp"))
		{
			// Получение адреса
			str=temp.remove(QString("ftp://"));

			// Заполнение значение карты
			sortingMap[ftp]<<temp;
		}
		else if(temp.contains("https"))
		{
			// Получение адреса
			str=temp.remove(QString("https://"));

			// Заполнение значение карты
			sortingMap[https]<<temp;
		}
		else if(temp.contains("http"))
		{
			// Получение адреса
			str=temp.remove(QString("http://"));

			// Заполнение значение карты
			sortingMap[http]<<temp;
		}
		else if(temp.contains("nntp"))
		{
			// Заполнение значение карты
			sortingMap[nntp]<<temp;
		}
		else if(temp.contains("ntp"))
		{
			// Заполнение значение карты
			sortingMap[ntp]<<temp;
		}
		else if(temp.contains("@") && temp.indexOf(":", temp.indexOf("@"))!=-1)
		{
			// Заполнение значение карты
			sortingMap[ssh]<<temp;
		}
		else if(temp.contains("telnet"))
		{
			// Получение адреса
			str=temp.remove(QString("telnet://"));

			// Заполнение значение карты
			sortingMap[telnet]<<temp;
		}
		else 
		{
			// Заполнение значение карты
			sortingMap[otherProtocol]<<temp;
		}
	}

	// Сортировка значений для каждого ключа
	QMap<protocolType, QStringList>::iterator it=sortingMap.begin();
	
	for(;it!=sortingMap.end(); it++)
	{
		sortByLexeme(it.value());
	}

	// Загрузка в выходной лист значений для определенного ключа 	
	for(int k=0; k<sortingMap[dhcp].count(); k++)
	{
		// Загрузка в буфер текущей строки для сортировки
		aIterKlein="DHCP:"+sortingMap[dhcp][k];

		// Добавление строки в выходной лист
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[dns].count(); k++)
	{
		// Загрузка в буфер текущей строки для сортировки
		aIterKlein="DNS:"+sortingMap[dns][k];

		// Добавление строки в выходной лист
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[ftp].count(); k++)
	{
		// Загрузка в буфер текущей строки для сортировки
		aIterKlein="ftp://"+sortingMap[ftp][k];

		// Добавление строки в выходной лист
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[http].count(); k++)
	{
		// Загрузка в буфер текущей строки для сортировки
		aIterKlein="http://"+sortingMap[http][k];

		// Добавление строки в выходной лист
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[https].count(); k++)
	{
		// Загрузка в буфер текущей строки для сортировки
		aIterKlein="https://"+sortingMap[https][k];

		// Добавление строки в выходной лист
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[ntp].count(); k++)
	{
		// Добавление строки в выходной лист
		res<<sortingMap[ntp][k];
	}
	for(int k=0; k<sortingMap[nntp].count(); k++)
	{
		// Добавление строки в выходной лист
		res<<sortingMap[nntp][k];
	}
	for(int k=0; k<sortingMap[ssh].count(); k++)
	{
		// Добавление строки в выходной лист
		res<<sortingMap[ssh][k];
	}
	for(int k=0; k<sortingMap[telnet].count(); k++)
	{
		// Загрузка в буфер текущей строки для сортировки
		aIterKlein="telnet://"+sortingMap[telnet][k];

		// Добавление строки в выходной лист
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[otherProtocol].count(); k++)
	{
		// Добавление строки в выходной лист
		res<<sortingMap[otherProtocol][k];
	}	

	// Замена данного листа на возвращаемый
	sortList=res;
}


void sortByDisk(QStringList &sortList)
{
	// Карта для хранения путей по устройству хранения
	// Ключ карты - имя , значения - список путь
	QMap<QString, QStringList> sortingMap;

	QStringList res;	// Результирующий лист

	QStringList sortingKey; // Лист для сортировки ключей

	QString temp; // Буфер для текущей обрабатываемой строки

	QString buf; // Буфер для ключа - домена

	QString str; // Буфер для одного из значений ключа - имени адреса

	QString aIter; // Буфер для ключа при формировании выходного списка

	QString aIterKlein; // Буфер для строки из списка для каждого 

	// Заполнение карты путей
	for(int i=0; i<sortList.count(); i++)
	{
		// Загрузка в бущер текущей строки для сортировки
		temp=sortList[i];
		
		// Получение имени диска
		buf=temp.section(":\\", 0, 0);

		// Получение пути
		str=temp.remove(buf+QString(":\\"));

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

	// Сортировка значений для каждого ключа
	QMap<QString, QStringList>::iterator it=sortingMap.begin();
	
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
	sortingKey.sort();

	// Заполнение выходного листа
	for(int j=0; j<sortingKey.count(); j++)
	{
		// Загрузка в бущер текущей строки для ключа
		aIter=sortingKey[j];

		// Загрузка в выходной лист значений для определенного ключа 
		for(int k=0; k<sortingMap[aIter].count(); k++)
		{
			// Загрузка в буфер текущей строки для сортировки
			aIterKlein=aIter+":\\"+sortingMap[aIter][k];

			// Добавление строки в выходной лист
			res<<aIterKlein;
		}
	}

	// Замена данного листа на возвращаемый
	sortList=res;
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

	// Сортировка значений для каждого ключа
	QMap<QString, QStringList>::iterator it=sortingMap.begin();
	
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
	//sortByLexeme(sortingKey);
	sortingKey.sort();

	// Заполнение выходного листа
	for(int j=0; j<sortingKey.count(); j++)
	{
		// Загрузка в бущер текущей строки для ключа
		aIter=sortingKey[j];

		// Загрузка в выходной лист значений для определенного ключа 
		for(int k=0; k<sortingMap[aIter].count(); k++)
		{
			// Загрузка в буфер текущей строки для сортировки
			aIterKlein=sortingMap[aIter][k]+"@"+aIter;

			// Добавление строки в выходной лист
			res<<aIterKlein;
		}
	}

	// Замена данного листа на возвращаемый
	sortList=res;
}