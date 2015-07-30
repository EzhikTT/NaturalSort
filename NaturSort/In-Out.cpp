#include "In-Out.h"


QStringList read(const QString &fileName)
{
	QStringList res;	// ������������ ������

	QFile File(fileName); // �������� ����� � �����

	// ��������� ���� �� ������
	if(File.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&File);
		while (!in.atEnd())
        {
            QString str=in.readLine();
			if(str!="\n")
			{
				res<<str;
			}
        }
		// �������� �����
        File.close(); 
	}

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