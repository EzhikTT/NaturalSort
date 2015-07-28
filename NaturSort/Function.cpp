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
}


void sortByDisk(QStringList &sortList)
{
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

	QMap<QString, QStringList>::iterator it=sortingMap.begin();

	// ���������� �������� ��� ������� �����
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
	sortByLexeme(sortingKey);

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