#include "In-Out.h"


QStringList read(const QString &fileName)
{
	QStringList res;	// Возвращаемый список

	QFile File(fileName); // Привязка имени к файлу

	QString rAll;

	// Открываем файл на чтение
	if(File.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&File);

		rAll=in.readAll();

		// Закрытие файла
        File.close(); 
	}

	res=rAll.split("\n", QString::SkipEmptyParts);
	return res;
}

void write(const QString &fileName, QStringList &out)
{
	QFile File(fileName); // Привязка имени к файлу

	// Открываем файл на запись
	if(File.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream in(&File);
		for(int i=0; i<out.count(); i++)
        {
            QString str=out[i];
			in<<str<<"\n";
        }
		// Закрытие файла
        File.close(); 
	}
}