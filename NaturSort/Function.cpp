#include "Function.h"


QStringList sortGroupedString(QMap<groupType, QStringList> &sort)
{
	QStringList res; // Возвращаемый список

	// Вызов функций для каждой группы
	sortByProtocol(sort[protocol]);
	sortByDisk(sort[disk]);
	sortByFilenameExtension(sort[filenameExtension]);
	sortByEmail(sort[email]);
	sortByLexeme(sort[other]);

	// Запись в результирующий список отсортированных групп 
	res<<sort[protocol]<<sort[disk]<<sort[filenameExtension]<<sort[email]<<sort[other];

	// Возврат списка из функции
	return res;
}


void sortByLexeme(QStringList &sortList)
{
	// Карта для хранения строк с начальной текстовой строкой
	// Ключ карты - начальная строка, значения - остаток строки
	QMap<QString, QStringList> strMap;

	// Карта для хранения строк с начальной числовой строкой
	// Ключ карты - начальная строка, значения - остаток строки
	QMap<double, QStringList> numMap;

	QList<double> sortingKeyNum; // Лист для сортировки числовых ключей

	QStringList sortingKeyStr; // Лист для сортировки строковых ключей

	QStringList res;	// Результирующий лист

	QString temp; // Буфер для текущей обрабатываемой строки

	QString buf; // Буфер для ключа - домена

	QString str; // Буфер для одного из значений ключа - имени адреса

	QString aIter; // Буфер для строкого ключа при формировании выходного списка

	QString aIterKlein; // Буфер для строки из списка для каждой строки из списка

	double num; // Буфер для хранения ключа для числовой карты

	double aIterNum; // Буфер для числового ключа при формировании выходного списка
	
	// Заполнение карты путей
	for(int i=0; i<sortList.count(); i++)
	{
		// Загрузка в бущер текущей строки для сортировки
		temp=sortList[i];
		
		// Заполнение карты по числовому ключу
		if(temp[0].isNumber())
		{
			// Получение ключа
			buf=temp.section(QRegExp("[A-z]"), 0, 0);

			// Перевод ключа из строки в число
			num=buf.toDouble();

			// Получение значения
			str=temp.remove(buf);

			/*// Заполнение карты, если остаток строки не пустой 
			if(!str.isEmpty())
			{*/
				if(numMap.contains(num))
				{
					numMap[num]<<str;
				}
				else
				{ 
					numMap.insert(num, QStringList(str));
				}
			//}
		}
		// Заполнение карты по нечисловому ключу
		else
		{
			// Получение ключа
			buf=temp.section(QRegExp("\\d"), 0, 0);

			// Получение значения
			str=temp.remove(buf);

			/*// Заполнение карты, если остаток строки не пустой 
			if(!str.isEmpty())
			{*/
				if(strMap.contains(buf))
				{
					strMap[buf]<<str;
				}
				else
				{ 
					strMap.insert(buf, QStringList(str));
				}
			//}
		}
	}
	
	// Сортировка карты с числовым ключом
	// Сортировка значений для каждого ключа
	QMap<double, QStringList>::iterator itn=numMap.begin();
	
	for(;itn!=numMap.end(); itn++)
	{
		if(itn.value().count()>1)
		{
			sortByLexeme(itn.value());
		}
	}

	// Записей ключей в лист
	itn=numMap.begin();
	for(;itn!=numMap.end(); itn++)
	{
		sortingKeyNum<<itn.key();
	}

	// Сортировка ключей
	//sortingKeyNum.sort();
	qStableSort(sortingKeyNum.begin(), sortingKeyNum.end());

	// Сортировка карты со строковым ключом
	// Сортировка значений для каждого ключа
	QMap<QString, QStringList>::iterator its=strMap.begin();
	
	for(;its!=strMap.end(); its++)
	{
		if(its.value().count()>1)
		{
			sortByLexeme(its.value());
		}
	}

	// Записей ключей в лист
	its=strMap.begin();
	for(;its!=strMap.end(); its++)
	{
		sortingKeyStr<<its.key();
	}

	// Сортировка ключей
	//sortingKeyStr.sort();
	qStableSort(sortingKeyStr.begin(), sortingKeyStr.end(), caseInsensitiveLessThan);

	// Заполнение выходного листа полями из числовой карты
	for(int j=0; j<sortingKeyNum.count(); j++)
	{
		// Загрузка в бущер текущей строки для ключа
		aIterNum=sortingKeyNum[j];

		// Загрузка в выходной лист значений для определенного ключа 
		for(int k=0; k<numMap[aIterNum].count(); k++)
		{
			// Загрузка в буфер текущей строки для сортировки
			aIterKlein=QString::number(aIterNum)+numMap[aIterNum][k];

			// Добавление строки в выходной лист
			res<<aIterKlein;
		}
	}

	// Заполнение выходного листа полями из строковой карты
	for(int j=0; j<sortingKeyStr.count(); j++)
	{
		// Загрузка в бущер текущей строки для ключа
		aIter=sortingKeyStr[j];

		// Загрузка в выходной лист значений для определенного ключа 
		for(int k=0; k<strMap[aIter].count(); k++)
		{
			// Загрузка в буфер текущей строки для сортировки
			aIterKlein=aIter+strMap[aIter][k];

			// Добавление строки в выходной лист
			res<<aIterKlein;
		}
	}

	// Замена данного листа на возвращаемый
	sortList=res;
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
			res[filenameExtension]<<temp;
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

	QString aIterKlein; // Буфер для строки из списка для каждой строки из списка

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
		if(it.value().count()>1)
		{
			sortByLexeme(it.value());
		}
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

	QString aIterKlein; // Буфер для строки из списка для каждой строки из списка

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
		if(it.value().count()>1)
		{
			sortByLexeme(it.value());
		}
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
	// Карта для хранения адресов по доменам 
	// Ключ карты - домен, значения - карты
	// Ключ внутренней карты - расширение, значение - список имен файлов
	QMap<fEtype, QMap<QString, QStringList>> sortingMap;	

	QStringList res;	// Результирующий лист

	QStringList sortingKey; // Лист для сортировки ключей

	QString temp; // Буфер для текущей обрабатываемой строки

	QString buf; // Буфер для ключа - домена

	QString str; // Буфер для одного из значений ключа - имени адреса

	QString aIter; // Буфер для ключа при формировании выходного списка

	QString aIterKlein; // Буфер для строки из списка для каждой строки из списка

	QStringList graficsL, soundL, videoL, textL, webpageL, refenceCodeFileL; // Списки с расширениями файлов для соответствующих групп

	// Заполнение списков форматами 
	graficsL<<"3ds"<<"fbx"<<"ma"<<"dwg"<<"dfx"<<"max"<<"mb"<<"a3d"<<"lws"<<"unity"<<"bmp"<<"jpeg"<<"jpg"<<"gif"<<"png"<<"psd"<<"tga";
	soundL<<"aa"<<"mp3"<<"aac"<<"flac"<<"wav"<<"wma"<<"midi";
	videoL<<"3gp"<<"avi"<<"flv"<<"mpeg"<<"mkv";
	textL<<"txt"<<"rtf"<<"tex"<<"doc"<<"docx"<<"pdf"<<"djv"<<"fb2"<<"odt";
	webpageL<<"xml"<<"html"<<"xhtml"<<"php";
	refenceCodeFileL<<"cpp"<<"c"<<"bas"<<"asm"<<"java"<<"js"<<"cs"<<"py"<<"pas"<<"rbw"<<"rb";

	// Заполнение карты адресами
	for(int i=0; i<sortList.count(); i++)
	{
		// Загрузка в бущер текущей строки для сортировки
		temp=sortList[i];

		// Получение расширения
		buf=temp.section(".", 1);

		// Получение имени
		str=temp.remove(QString(".")+buf);
		
		// Заполнение карты в зависимости от расширения
		if(graficsL.contains(buf))
		{			
			// Заполнение значение карты или создание поля для ключа
			if(sortingMap[grafics].contains(buf))
			{
				sortingMap[grafics][buf]<<str;
			}
			else
			{ 
				sortingMap[grafics].insert(buf, QStringList(str));
			}
		}
		else if(soundL.contains(buf))
		{
			// Заполнение значение карты или создание поля для ключа
			if(sortingMap[sound].contains(buf))
			{
				sortingMap[sound][buf]<<str;
			}
			else
			{ 
				sortingMap[sound].insert(buf, QStringList(str));
			}
		}
		else if(videoL.contains(buf))
		{
			// Заполнение значение карты или создание поля для ключа
			if(sortingMap[video].contains(buf))
			{
				sortingMap[video][buf]<<str;
			}
			else
			{ 
				sortingMap[video].insert(buf, QStringList(str));
			}
		}
		else if(textL.contains(buf))
		{
			// Заполнение значение карты или создание поля для ключа
			if(sortingMap[text].contains(buf))
			{
				sortingMap[text][buf]<<str;
			}
			else
			{ 
				sortingMap[text].insert(buf, QStringList(str));
			}
		}
		else if(webpageL.contains(buf))
		{
			// Заполнение значение карты или создание поля для ключа
			if(sortingMap[webpage].contains(buf))
			{
				sortingMap[webpage][buf]<<str;
			}
			else
			{ 
				sortingMap[webpage].insert(buf, QStringList(str));
			}
		}
		else if(buf=="exe" || buf=="bat")
		{
			// Заполнение значение карты или создание поля для ключа
			if(sortingMap[exefile].contains(buf))
			{
				sortingMap[exefile][buf]<<str;
			}
			else
			{ 
				sortingMap[exefile].insert(buf, QStringList(str));
			}
		}
		else if(refenceCodeFileL.contains(buf))
		{
			// Заполнение значение карты или создание поля для ключа
			if(sortingMap[refenceCodeFile].contains(buf))
			{
				sortingMap[refenceCodeFile][buf]<<str;
			}
			else
			{ 
				sortingMap[refenceCodeFile].insert(buf, QStringList(str));
			}
		}
		else if(buf=="obj")
		{
			// Заполнение значение карты или создание поля для ключа
			if(sortingMap[objFile].contains(buf))
			{
				sortingMap[objFile][buf]<<str;
			}
			else
			{ 
				sortingMap[objFile].insert(buf, QStringList(str));
			}
		}
		else
		{
			// Заполнение значение карты или создание поля для ключа
			if(sortingMap[otherFilenameExtension].contains(buf))
			{
				sortingMap[otherFilenameExtension][buf]<<str;
			}
			else
			{ 
				sortingMap[otherFilenameExtension].insert(buf, QStringList(str));
			}
		}
	}

	// Сортировка и запись в выходящий список значений карты
	for(int j=0; j<9; j++)
	{
		fEtype v;
		v=static_cast<fEtype>(j);

		// Сортировка значений для каждого ключа 
		QMap<QString, QStringList>::iterator itg=sortingMap[v].begin();
		
		for(;itg!=sortingMap[v].end(); itg++)
		{
			if(itg.value().count()>1)
			{
				sortByLexeme(itg.value());
			}
		}

		// Записей ключей в лист
		itg=sortingMap[v].begin();
		for(;itg!=sortingMap[v].end(); itg++)
		{
			sortingKey<<itg.key();
		}

		// Сортировка ключей
		sortingKey.sort();

		// Заполнение выходного листа
		for(int l=0; l<sortingKey.count(); l++)
		{
			// Загрузка в бущер текущей строки для ключа
			aIter=sortingKey[l];

			// Загрузка в выходной лист значений для определенного ключа 
			for(int p=0; p<sortingMap[v][aIter].count(); p++)
			{
				// Загрузка в буфер текущей строки для сортировки
				aIterKlein=sortingMap[v][aIter][p]+"."+aIter;

				// Добавление строки в выходной лист
				res<<aIterKlein;
			}
		}
		// Отчистка списка ключей
		sortingKey.clear();
	}

	// Замена данного листа на возвращаемый
	sortList=res;
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

	QString aIterKlein; // Буфер для строки из списка для каждой строки из списка

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
		if(it.value().count()>1)
		{
			sortByLexeme(it.value());
		}
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


bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
{
    return s1.toLower() < s2.toLower();
}