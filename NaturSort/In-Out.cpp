#include "In-Out.h"


QStringList read(const QString &fileName)
{
	QStringList res;	// ������������ ������

	QFile File(fileName); // �������� ����� � �����

	QString rAll;

	// ��������� ���� �� ������
	if(File.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&File);

		rAll=in.readAll();

		// �������� �����
        File.close(); 
	}

	res=rAll.split("\n", QString::SkipEmptyParts);
	return res;
}

void write(const QString &fileName, QStringList &out)
{
	QFile File(fileName); // �������� ����� � �����

	// ��������� ���� �� ������
	if(File.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream in(&File);
		for(int i=0; i<out.count(); i++)
        {
            QString str=out[i];
			in<<str<<"\n";
        }
		// �������� �����
        File.close(); 
	}
}