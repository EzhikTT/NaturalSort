#include "Libs.h"



// ������������ ����� ����� ��� ����������
enum groupType
{
	protocol,			// ��������� �������
	disk,				// ����� ��������
	filenameExtention,	// ���������� �����
	email,				// E-mail �����
	other,				// ������, �� ���������� ��� ����������������� ������ 
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