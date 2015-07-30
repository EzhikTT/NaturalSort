#include "Function.h"


QStringList sortGroupedString(QMap<groupType, QStringList> &sort)
{
	QStringList res; // ������������ ������

	// ����� ������� ��� ������ ������
	sortByProtocol(sort[protocol]);
	sortByDisk(sort[disk]);
	sortByFilenameExtension(sort[filenameExtension]);
	sortByEmail(sort[email]);
	sortByLexeme(sort[other]);

	// ������ � �������������� ������ ��������������� ����� 
	res<<sort[protocol]<<sort[disk]<<sort[filenameExtension]<<sort[email]<<sort[other];

	// ������� ������ �� �������
	return res;
}


void sortByLexeme(QStringList &sortList)
{
	// ����� ��� �������� ����� � ��������� ��������� �������
	// ���� ����� - ��������� ������, �������� - ������� ������
	QMap<QString, QStringList> strMap;

	// ����� ��� �������� ����� � ��������� �������� �������
	// ���� ����� - ��������� ������, �������� - ������� ������
	QMap<double, QStringList> numMap;

	QList<double> sortingKeyNum; // ���� ��� ���������� �������� ������

	QStringList sortingKeyStr; // ���� ��� ���������� ��������� ������

	QStringList res;	// �������������� ����

	QString temp; // ����� ��� ������� �������������� ������

	QString buf; // ����� ��� ����� - ������

	QString str; // ����� ��� ������ �� �������� ����� - ����� ������

	QString aIter; // ����� ��� �������� ����� ��� ������������ ��������� ������

	QString aIterKlein; // ����� ��� ������ �� ������ ��� ������ ������ �� ������

	double num; // ����� ��� �������� ����� ��� �������� �����

	double aIterNum; // ����� ��� ��������� ����� ��� ������������ ��������� ������
	
	// ���������� ����� �����
	for(int i=0; i<sortList.count(); i++)
	{
		// �������� � ����� ������� ������ ��� ����������
		temp=sortList[i];
		
		// ���������� ����� �� ��������� �����
		if(temp[0].isNumber())
		{
			// ��������� �����
			buf=temp.section(QRegExp("[A-z]"), 0, 0);

			// ������� ����� �� ������ � �����
			num=buf.toDouble();

			// ��������� ��������
			str=temp.remove(buf);

			/*// ���������� �����, ���� ������� ������ �� ������ 
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
		// ���������� ����� �� ����������� �����
		else
		{
			// ��������� �����
			buf=temp.section(QRegExp("\\d"), 0, 0);

			// ��������� ��������
			str=temp.remove(buf);

			/*// ���������� �����, ���� ������� ������ �� ������ 
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
	
	// ���������� ����� � �������� ������
	// ���������� �������� ��� ������� �����
	QMap<double, QStringList>::iterator itn=numMap.begin();
	
	for(;itn!=numMap.end(); itn++)
	{
		if(itn.value().count()>1)
		{
			sortByLexeme(itn.value());
		}
	}

	// ������� ������ � ����
	itn=numMap.begin();
	for(;itn!=numMap.end(); itn++)
	{
		sortingKeyNum<<itn.key();
	}

	// ���������� ������
	//sortingKeyNum.sort();
	qStableSort(sortingKeyNum.begin(), sortingKeyNum.end());

	// ���������� ����� �� ��������� ������
	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator its=strMap.begin();
	
	for(;its!=strMap.end(); its++)
	{
		if(its.value().count()>1)
		{
			sortByLexeme(its.value());
		}
	}

	// ������� ������ � ����
	its=strMap.begin();
	for(;its!=strMap.end(); its++)
	{
		sortingKeyStr<<its.key();
	}

	// ���������� ������
	//sortingKeyStr.sort();
	qStableSort(sortingKeyStr.begin(), sortingKeyStr.end(), caseInsensitiveLessThan);

	// ���������� ��������� ����� ������ �� �������� �����
	for(int j=0; j<sortingKeyNum.count(); j++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIterNum=sortingKeyNum[j];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int k=0; k<numMap[aIterNum].count(); k++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=QString::number(aIterNum)+numMap[aIterNum][k];

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// ���������� ��������� ����� ������ �� ��������� �����
	for(int j=0; j<sortingKeyStr.count(); j++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKeyStr[j];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int k=0; k<strMap[aIter].count(); k++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=aIter+strMap[aIter][k];

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// ������ ������� ����� �� ������������
	sortList=res;
}


QMap<groupType, QStringList> groupForSort(QStringList &input)
{
	QMap<groupType, QStringList> res;	// �������������� ����� � �������������� ������ �� �������

	QString temp;	// ��������� ��� ������� �������������� ������

	// ���� ��� ������������� ����� �� ������� 
	for(int i=0; i<input.count(); i++)
	{
		// �������� � ����� ������� ������ ��� ����������
		temp=input[i];

		// ������� ��� ����� �������� ��������
		if(temp.contains(":\\"))
		{
			res[disk]<<temp;
		}
		// ������� ��� ������ e-mail �������
		else if(temp.contains("@") && temp.count(".")==1)
		{
			res[email]<<temp;
		}
		// ������� ��� ������ ���������� �������
		else if(temp.contains("://") || temp.contains(":") || temp.contains("ntp") || (temp.contains("@") && temp.indexOf(":", temp.indexOf("@"))!=-1))
		{
			res[protocol]<<temp;
		}
		// ������� ��� ������ ���������� ������
		else if(temp.count(".")==1)
		{
			res[filenameExtension]<<temp;
		}
		// ������� ��� �����, �� �������� �� � ���� �� �����
		else
		{
			res[other]<<temp;
		}
	}

	// ����������� ����� � ������������ �����
	return res;
}


void sortByProtocol(QStringList &sortList)
{
	// ����� ��� �������� ������ �� ��������� �������
	// ���� ����� - ��� , �������� - ������ ����
	QMap<protocolType, QStringList> sortingMap;

	QStringList res;	// �������������� ����

	QString temp; // ����� ��� ������� �������������� ������

	QString buf; // ����� ��� ����� - ������

	QString str; // ����� ��� ������ �� �������� ����� - ����� ������

	QString aIterKlein; // ����� ��� ������ �� ������ ��� ������ ������ �� ������

	// ���������� ����� �����
	for(int i=0; i<sortList.count(); i++)
	{
		// �������� � ����� ������� ������ ��� ����������
		temp=sortList[i];

		// ������� ��� ������ ���������� �������
		if(temp.contains("DHCP"))
		{
			// ��������� ������
			str=temp.remove(QString("DHCP:"));

			// ���������� �������� �����
			sortingMap[dhcp]<<temp;
		}
		else if(temp.contains("DNS"))
		{
			// ��������� ������
			str=temp.remove(QString("DNS:"));

			// ���������� �������� �����
			sortingMap[dns]<<temp;
		}
		else if(temp.contains("ftp"))
		{
			// ��������� ������
			str=temp.remove(QString("ftp://"));

			// ���������� �������� �����
			sortingMap[ftp]<<temp;
		}
		else if(temp.contains("https"))
		{
			// ��������� ������
			str=temp.remove(QString("https://"));

			// ���������� �������� �����
			sortingMap[https]<<temp;
		}
		else if(temp.contains("http"))
		{
			// ��������� ������
			str=temp.remove(QString("http://"));

			// ���������� �������� �����
			sortingMap[http]<<temp;
		}
		else if(temp.contains("nntp"))
		{
			// ���������� �������� �����
			sortingMap[nntp]<<temp;
		}
		else if(temp.contains("ntp"))
		{
			// ���������� �������� �����
			sortingMap[ntp]<<temp;
		}
		else if(temp.contains("@") && temp.indexOf(":", temp.indexOf("@"))!=-1)
		{
			// ���������� �������� �����
			sortingMap[ssh]<<temp;
		}
		else if(temp.contains("telnet"))
		{
			// ��������� ������
			str=temp.remove(QString("telnet://"));

			// ���������� �������� �����
			sortingMap[telnet]<<temp;
		}
		else 
		{
			// ���������� �������� �����
			sortingMap[otherProtocol]<<temp;
		}
	}

	// ���������� �������� ��� ������� �����
	QMap<protocolType, QStringList>::iterator it=sortingMap.begin();
	
	for(;it!=sortingMap.end(); it++)
	{
		if(it.value().count()>1)
		{
			sortByLexeme(it.value());
		}
	}

	// �������� � �������� ���� �������� ��� ������������� ����� 	
	for(int k=0; k<sortingMap[dhcp].count(); k++)
	{
		// �������� � ����� ������� ������ ��� ����������
		aIterKlein="DHCP:"+sortingMap[dhcp][k];

		// ���������� ������ � �������� ����
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[dns].count(); k++)
	{
		// �������� � ����� ������� ������ ��� ����������
		aIterKlein="DNS:"+sortingMap[dns][k];

		// ���������� ������ � �������� ����
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[ftp].count(); k++)
	{
		// �������� � ����� ������� ������ ��� ����������
		aIterKlein="ftp://"+sortingMap[ftp][k];

		// ���������� ������ � �������� ����
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[http].count(); k++)
	{
		// �������� � ����� ������� ������ ��� ����������
		aIterKlein="http://"+sortingMap[http][k];

		// ���������� ������ � �������� ����
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[https].count(); k++)
	{
		// �������� � ����� ������� ������ ��� ����������
		aIterKlein="https://"+sortingMap[https][k];

		// ���������� ������ � �������� ����
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[ntp].count(); k++)
	{
		// ���������� ������ � �������� ����
		res<<sortingMap[ntp][k];
	}
	for(int k=0; k<sortingMap[nntp].count(); k++)
	{
		// ���������� ������ � �������� ����
		res<<sortingMap[nntp][k];
	}
	for(int k=0; k<sortingMap[ssh].count(); k++)
	{
		// ���������� ������ � �������� ����
		res<<sortingMap[ssh][k];
	}
	for(int k=0; k<sortingMap[telnet].count(); k++)
	{
		// �������� � ����� ������� ������ ��� ����������
		aIterKlein="telnet://"+sortingMap[telnet][k];

		// ���������� ������ � �������� ����
		res<<aIterKlein;
	}
	for(int k=0; k<sortingMap[otherProtocol].count(); k++)
	{
		// ���������� ������ � �������� ����
		res<<sortingMap[otherProtocol][k];
	}	

	// ������ ������� ����� �� ������������
	sortList=res;
}


void sortByDisk(QStringList &sortList)
{
	// ����� ��� �������� ����� �� ���������� ��������
	// ���� ����� - ��� , �������� - ������ ����
	QMap<QString, QStringList> sortingMap;

	QStringList res;	// �������������� ����

	QStringList sortingKey; // ���� ��� ���������� ������

	QString temp; // ����� ��� ������� �������������� ������

	QString buf; // ����� ��� ����� - ������

	QString str; // ����� ��� ������ �� �������� ����� - ����� ������

	QString aIter; // ����� ��� ����� ��� ������������ ��������� ������

	QString aIterKlein; // ����� ��� ������ �� ������ ��� ������ ������ �� ������

	// ���������� ����� �����
	for(int i=0; i<sortList.count(); i++)
	{
		// �������� � ����� ������� ������ ��� ����������
		temp=sortList[i];
		
		// ��������� ����� �����
		buf=temp.section(":\\", 0, 0);

		// ��������� ����
		str=temp.remove(buf+QString(":\\"));

		// ���������� �������� ����� ��� �������� ���� ��� �����
		if(sortingMap.contains(buf))
		{
			sortingMap[buf]<<str;
		}
		else
		{ 
			sortingMap.insert(buf, QStringList(str));
		}
	}

	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator it=sortingMap.begin();
	
	for(;it!=sortingMap.end(); it++)
	{
		if(it.value().count()>1)
		{
			sortByLexeme(it.value());
		}
	}

	// ������� ������ � ����
	it=sortingMap.begin();
	for(;it!=sortingMap.end(); it++)
	{
		sortingKey<<it.key();
	}

	// ���������� ������
	sortingKey.sort();

	// ���������� ��������� �����
	for(int j=0; j<sortingKey.count(); j++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[j];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int k=0; k<sortingMap[aIter].count(); k++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=aIter+":\\"+sortingMap[aIter][k];

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// ������ ������� ����� �� ������������
	sortList=res;
}


void sortByFilenameExtension(QStringList &sortList)
{
	// ����� ��� �������� ������� �� ������� 
	// ���� ����� - �����, �������� - �����
	// ���� ���������� ����� - ����������, �������� - ������ ���� ������
	QMap<fEtype, QMap<QString, QStringList>> sortingMap;	

	QStringList res;	// �������������� ����

	QStringList sortingKey; // ���� ��� ���������� ������

	QString temp; // ����� ��� ������� �������������� ������

	QString buf; // ����� ��� ����� - ������

	QString str; // ����� ��� ������ �� �������� ����� - ����� ������

	QString aIter; // ����� ��� ����� ��� ������������ ��������� ������

	QString aIterKlein; // ����� ��� ������ �� ������ ��� ������ ������ �� ������

	// ���������� ����� ��������
	for(int i=0; i<sortList.count(); i++)
	{
		// �������� � ����� ������� ������ ��� ����������
		temp=sortList[i];

		// ��������� ����������
		buf=temp.section(".", 1);

		// ��������� �����
		str=temp.remove(QString(".")+buf);
		
		// ���������� ����� � ����������� �� ����������
		if(buf=="3ds" || buf=="fbx" || buf=="ma" || buf=="dwg" || buf=="dfx" || buf=="max" || buf=="mb" || buf=="a3d" || buf=="lws" || buf=="unity" || buf=="bmp" || buf=="jpeg" || buf=="jpg" || buf=="gif" || buf=="png" || buf=="psd" || buf=="tga")
		{			
			// ���������� �������� ����� ��� �������� ���� ��� �����
			if(sortingMap[grafics].contains(buf))
			{
				sortingMap[grafics][buf]<<str;
			}
			else
			{ 
				sortingMap[grafics].insert(buf, QStringList(str));
			}
		}
		else if(buf=="aa" || buf=="mp3" || buf=="aac" || buf=="flac" || buf=="wav" || buf=="wma" || buf=="midi")
		{
			// ���������� �������� ����� ��� �������� ���� ��� �����
			if(sortingMap[sound].contains(buf))
			{
				sortingMap[sound][buf]<<str;
			}
			else
			{ 
				sortingMap[sound].insert(buf, QStringList(str));
			}
		}
		else if(buf=="3gp" || buf=="avi" || buf=="flv" || buf=="mpeg" || buf=="mkv")
		{
			// ���������� �������� ����� ��� �������� ���� ��� �����
			if(sortingMap[video].contains(buf))
			{
				sortingMap[video][buf]<<str;
			}
			else
			{ 
				sortingMap[video].insert(buf, QStringList(str));
			}
		}
		else if(buf=="txt" || buf=="rtf" || buf=="tex" || buf=="doc" || buf=="docx" || buf=="pdf" || buf=="djv" || buf=="fb2" || buf=="odt")
		{
			// ���������� �������� ����� ��� �������� ���� ��� �����
			if(sortingMap[text].contains(buf))
			{
				sortingMap[text][buf]<<str;
			}
			else
			{ 
				sortingMap[text].insert(buf, QStringList(str));
			}
		}
		else if(buf=="xml" || buf=="html" || buf=="xhtml" || buf=="php")
		{
			// ���������� �������� ����� ��� �������� ���� ��� �����
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
			// ���������� �������� ����� ��� �������� ���� ��� �����
			if(sortingMap[exefile].contains(buf))
			{
				sortingMap[exefile][buf]<<str;
			}
			else
			{ 
				sortingMap[exefile].insert(buf, QStringList(str));
			}
		}
		else if(buf=="cpp" || buf=="c" || buf=="bas" || buf=="asm" || buf=="java" || buf=="js" || buf=="cs" || buf=="py" || buf=="pas" || buf=="rbw" || buf=="rb")
		{
			// ���������� �������� ����� ��� �������� ���� ��� �����
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
			// ���������� �������� ����� ��� �������� ���� ��� �����
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
			// ���������� �������� ����� ��� �������� ���� ��� �����
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

	// ������ � ������� ���������, �� � ���� ������ �������� �� ��������� � enum'� �� ������
	// � ������� ������� ���� 0-8 � ���������� ����� ���� ��� � ����� ������� �����. 
	// ��� ������ ������ �� ��������� � enum'�. � ����� ����� GetName, �� �� ���� ��������� ��������.
	// ��� ������� ����������� ���� ���� ����, � �� ��� 100500?
	// ��� ��������� ���������� � enum'�

	for(int j=0; j<9; j++)
	{
		fEtype v;
		v=static_cast<fEtype>(j);
		// ���������� �������� ��� ������� ����� 
		QMap<QString, QStringList>::iterator itg=sortingMap[v].begin();
		
		for(;itg!=sortingMap[v].end(); itg++)
		{
			if(itg.value().count()>1)
			{
				sortByLexeme(itg.value());
			}
		}

		// ������� ������ � ����
		itg=sortingMap[v].begin();
		for(;itg!=sortingMap[v].end(); itg++)
		{
			sortingKey<<itg.key();
		}

		// ���������� ������
		sortingKey.sort();

		// ���������� ��������� �����
		for(int l=0; l<sortingKey.count(); l++)
		{
			// �������� � ����� ������� ������ ��� �����
			aIter=sortingKey[l];

			// �������� � �������� ���� �������� ��� ������������� ����� 
			for(int p=0; p<sortingMap[v][aIter].count(); p++)
			{
				// �������� � ����� ������� ������ ��� ����������
				aIterKlein=sortingMap[v][aIter][p]+"."+aIter;

				// ���������� ������ � �������� ����
				res<<aIterKlein;
			}
		}
		// �������� ������ ������
		sortingKey.clear();
	}




	/*
	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator its=sortingMap[sound].begin();
	
	for(;its!=sortingMap[sound].end(); its++)
	{
		if(its.value().count()>1)
		{
			sortByLexeme(its.value());
		}
	}

	// ������� ������ � ����
	its=sortingMap[sound].begin();
	for(;its!=sortingMap[sound].end(); its++)
	{
		sortingKey<<its.key();
	}

	// ���������� ������
	sortingKey.sort();

	// ���������� ��������� �����
	for(int l=0; l<sortingKey.count(); l++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[l];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int p=0; p<sortingMap[sound][aIter].count(); p++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=sortingMap[sound][aIter][p]+"."+aIter;

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// �������� ������ ������
	sortingKey.clear();

	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator itv=sortingMap[video].begin();
	
	for(;itv!=sortingMap[video].end(); itv++)
	{
		if(itv.value().count()>1)
		{
			sortByLexeme(itv.value());
		}
	}

	// ������� ������ � ����
	itv=sortingMap[video].begin();
	for(;itv!=sortingMap[video].end(); itv++)
	{
		sortingKey<<itv.key();
	}

	// ���������� ������
	sortingKey.sort();

	// ���������� ��������� �����
	for(int l=0; l<sortingKey.count(); l++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[l];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int p=0; p<sortingMap[video][aIter].count(); p++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=sortingMap[video][aIter][p]+"."+aIter;

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// �������� ������ ������
	sortingKey.clear();

	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator itt=sortingMap[text].begin();
	
	for(;itt!=sortingMap[text].end(); itt++)
	{
		if(itt.value().count()>1)
		{
			sortByLexeme(itt.value());
		}
	}

	// ������� ������ � ����
	itt=sortingMap[text].begin();
	for(;itt!=sortingMap[text].end(); itt++)
	{
		sortingKey<<itt.key();
	}

	// ���������� ������
	sortingKey.sort();

	// ���������� ��������� �����
	for(int l=0; l<sortingKey.count(); l++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[l];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int p=0; p<sortingMap[text][aIter].count(); p++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=sortingMap[text][aIter][p]+"."+aIter;

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// �������� ������ ������
	sortingKey.clear();

	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator itw=sortingMap[webpage].begin();
	
	for(;itw!=sortingMap[webpage].end(); itw++)
	{
		if(itw.value().count()>1)
		{
			sortByLexeme(itw.value());
		}
	}

	// ������� ������ � ����
	itw=sortingMap[webpage].begin();
	for(;itw!=sortingMap[webpage].end(); itw++)
	{
		sortingKey<<itw.key();
	}

	// ���������� ������
	sortingKey.sort();

	// ���������� ��������� �����
	for(int l=0; l<sortingKey.count(); l++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[l];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int p=0; p<sortingMap[webpage][aIter].count(); p++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=sortingMap[webpage][aIter][p]+"."+aIter;

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// �������� ������ ������
	sortingKey.clear();

	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator ite=sortingMap[exefile].begin();
	
	for(;ite!=sortingMap[exefile].end(); ite++)
	{
		if(ite.value().count()>1)
		{
			sortByLexeme(ite.value());
		}
	}

	// ������� ������ � ����
	ite=sortingMap[exefile].begin();
	for(;ite!=sortingMap[exefile].end(); ite++)
	{
		sortingKey<<ite.key();
	}

	// ���������� ������
	sortingKey.sort();

	// ���������� ��������� �����
	for(int l=0; l<sortingKey.count(); l++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[l];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int p=0; p<sortingMap[exefile][aIter].count(); p++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=sortingMap[exefile][aIter][p]+"."+aIter;

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// �������� ������ ������
	sortingKey.clear();

	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator itr=sortingMap[refenceCodeFile].begin();
	
	for(;itr!=sortingMap[refenceCodeFile].end(); itr++)
	{
		if(itr.value().count()>1)
		{
			sortByLexeme(itr.value());
		}
	}

	// ������� ������ � ����
	itr=sortingMap[refenceCodeFile].begin();
	for(;itr!=sortingMap[refenceCodeFile].end(); itr++)
	{
		sortingKey<<itr.key();
	}

	// ���������� ������
	sortingKey.sort();

	// ���������� ��������� �����
	for(int l=0; l<sortingKey.count(); l++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[l];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int p=0; p<sortingMap[refenceCodeFile][aIter].count(); p++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=sortingMap[refenceCodeFile][aIter][p]+"."+aIter;

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// �������� ������ ������
	sortingKey.clear();

	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator ito=sortingMap[objFile].begin();
	
	for(;ito!=sortingMap[objFile].end(); ito++)
	{
		if(ito.value().count()>1)
		{
			sortByLexeme(ito.value());
		}
	}

	// ������� ������ � ����
	ito=sortingMap[objFile].begin();
	for(;ito!=sortingMap[objFile].end(); ito++)
	{
		sortingKey<<ito.key();
	}

	// ���������� ������
	sortingKey.sort();

	// ���������� ��������� �����
	for(int l=0; l<sortingKey.count(); l++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[l];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int p=0; p<sortingMap[objFile][aIter].count(); p++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=sortingMap[objFile][aIter][p]+"."+aIter;

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// �������� ������ ������
	sortingKey.clear();

	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator itf=sortingMap[otherFilenameExtension].begin();
	
	for(;itf!=sortingMap[otherFilenameExtension].end(); itf++)
	{
		if(itf.value().count()>1)
		{
			sortByLexeme(itf.value());
		}
	}

	// ������� ������ � ����
	itf=sortingMap[otherFilenameExtension].begin();
	for(;itf!=sortingMap[otherFilenameExtension].end(); itf++)
	{
		sortingKey<<itf.key();
	}

	// ���������� ������
	sortingKey.sort();

	// ���������� ��������� �����
	for(int l=0; l<sortingKey.count(); l++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[l];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int p=0; p<sortingMap[otherFilenameExtension][aIter].count(); p++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=sortingMap[otherFilenameExtension][aIter][p]+"."+aIter;

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}*/

	// ������ ������� ����� �� ������������
	sortList=res;
}


void sortByEmail(QStringList &sortList)
{
	// ����� ��� �������� ������� �� ������� 
	// ���� ����� - �����, �������� - ������ ������� ����� ������
	QMap<QString, QStringList> sortingMap;	

	QStringList res;	// �������������� ����

	QStringList sortingKey; // ���� ��� ���������� ������

	QString temp; // ����� ��� ������� �������������� ������

	QString buf; // ����� ��� ����� - ������

	QString str; // ����� ��� ������ �� �������� ����� - ����� ������

	QString aIter; // ����� ��� ����� ��� ������������ ��������� ������

	QString aIterKlein; // ����� ��� ������ �� ������ ��� ������ ������ �� ������

	// ���������� ����� ��������
	for(int i=0; i<sortList.count(); i++)
	{
		// �������� � ����� ������� ������ ��� ����������
		temp=sortList[i];
		
		// ��������� ������
		buf=temp.section("@", 1);

		// ��������� �����
		str=temp.remove(QString("@")+buf);

		// ���������� �������� ����� ��� �������� ���� ��� �����
		if(sortingMap.contains(buf))
		{
			sortingMap[buf]<<str;
		}
		else
		{ 
			sortingMap.insert(buf, QStringList(str));
		}
	}

	// ���������� �������� ��� ������� �����
	QMap<QString, QStringList>::iterator it=sortingMap.begin();
	
	for(;it!=sortingMap.end(); it++)
	{
		if(it.value().count()>1)
		{
			sortByLexeme(it.value());
		}
	}

	// ������� ������ � ����
	it=sortingMap.begin();
	for(;it!=sortingMap.end(); it++)
	{
		sortingKey<<it.key();
	}

	// ���������� ������
	//sortByLexeme(sortingKey);
	sortingKey.sort();

	// ���������� ��������� �����
	for(int j=0; j<sortingKey.count(); j++)
	{
		// �������� � ����� ������� ������ ��� �����
		aIter=sortingKey[j];

		// �������� � �������� ���� �������� ��� ������������� ����� 
		for(int k=0; k<sortingMap[aIter].count(); k++)
		{
			// �������� � ����� ������� ������ ��� ����������
			aIterKlein=sortingMap[aIter][k]+"@"+aIter;

			// ���������� ������ � �������� ����
			res<<aIterKlein;
		}
	}

	// ������ ������� ����� �� ������������
	sortList=res;
}


bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
{
    return s1.toLower() < s2.toLower();
}