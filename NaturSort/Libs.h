#include <QStringList>
#include <QMap>
#include <QTest>
#include <QObject>


// ������������ ����� ����� ��� ����������
enum typeData
{
	protocol,
	disk,
	filenameExtention,
	email,
	other,
};


// ������������ ����� ����������
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


// ������������ ����� ���������� ������ 
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