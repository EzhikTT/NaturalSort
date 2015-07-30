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
	grafics=0,
	sound=1,
	video=2,
	text=3,
	webpage=4,
	exefile=5,
	refenceCodeFile=6,
	objFile=7,
	otherFilenameExtension=8,
};