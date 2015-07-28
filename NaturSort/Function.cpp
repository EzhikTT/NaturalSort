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
			res[filenameExtention]<<temp;
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

	QString aIterKlein; // ����� ��� ������ �� ������ ��� ������� 

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
		sortByLexeme(it.value());
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

	QString aIterKlein; // ����� ��� ������ �� ������ ��� ������� 

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
		sortByLexeme(it.value());
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

	QString aIterKlein; // ����� ��� ������ �� ������ ��� ������� 

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
		sortByLexeme(it.value());
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