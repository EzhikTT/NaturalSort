#pragma once

#include "Libs.h"


// ������������ ����� ����� ��� ����������
enum groupType
{
	protocol,			// ��������� �������
	disk,				// ����� ��������
	filenameExtension,	// ���������� �����
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
	otherProtocol,
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
	otherFilenameExtension,
};