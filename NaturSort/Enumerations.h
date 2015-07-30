#pragma once

#include "Libs.h"

/*!
 * \file Enumerations.h
 * \brief ���� ������� �� ������������ 
*/


/*!
* \enum groupType
* \brief ������������ ����� ����� ��� ����������
*/
enum groupType
{
	protocol,			//!< ��������� �������
	disk,				//!< ����� ��������
	filenameExtension,	//!< ���������� �����
	email,				//!< E-mail �����
	other,				//!< ������, �� ���������� ��� ����������������� ������ 
};

/*!
* \enum protocolType
* \brief ������������ ����� ����������
*/
enum protocolType
{
	dhcp,			//!< �������� DHCP
	dns,			//!< �������� DNS
	ftp,			//!< �������� FTP
	http,			//!< �������� HTTP
	https,			//!< �������� HTTPS
	ntp,			//!< �������� NTP
	nntp,			//!< �������� NNTP
	ssh,			//!< �������� SSH
	telnet,			//!< �������� Telnet
	otherProtocol,	//!< ����������� ��������� �������
};

/*!
* \enum fEtype
* \brief ������������ ����� ���������� ������ 
*/
enum fEtype
{
	grafics=0,					//!< ����������� �����
	sound=1,					//!< �������� �����
	video=2,					//!< ����� �����
	text=3,						//!< ��������� �����
	webpage=4,					//!< ���� ���-�������
	exefile=5,					//!< ����������� �����
	refenceCodeFile=6,			//!< ����� ������������ ����
	objFile=7,					//!< ��������� �����
	otherFilenameExtension=8,	//!< ����� � ������������ ������������
};