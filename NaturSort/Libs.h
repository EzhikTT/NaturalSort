#include <QStringList>
#include <QMap>
#include <QTest>
#include <QObject>


// Перечисление типов групп для сортировки
enum typeData
{
	protocol,
	disk,
	filenameExtention,
	email,
	other,
};


// Перечесление видов протоколов
enum protocolType
{
	dhcp,
	dns,
	ftp,
	http,
	https,
	ntp,
	nntp,
	ssh,
	telnet,
};


// Перечесление видов расширения файлов 
enum fEtype
{
	grafics,
	sound,
	video,
	text,
	webpage,
	exefile,
	refenceCodeFile,
	objFile,
};