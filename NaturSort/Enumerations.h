#pragma once

#include "Libs.h"

/*!
 * \file Enumerations.h
 * \brief Файл состоит из перечислений 
*/


/*!
* \enum groupType
* \brief Перечисление типов групп для сортировки
*/
enum groupType
{
	protocol,			//!< Протоколы доступа
	disk,				//!< Место хранения
	filenameExtension,	//!< Расширение файла
	email,				//!< E-mail адрес
	other,				//!< Строки, не подходящие под вышеперечисленные группы 
};

/*!
* \enum protocolType
* \brief Перечесление видов протоколов
*/
enum protocolType
{
	dhcp,			//!< Протокол DHCP
	dns,			//!< Протокол DNS
	ftp,			//!< Протокол FTP
	http,			//!< Протокол HTTP
	https,			//!< Протокол HTTPS
	ntp,			//!< Протокол NTP
	nntp,			//!< Протокол NNTP
	ssh,			//!< Протокол SSH
	telnet,			//!< Протокол Telnet
	otherProtocol,	//!< Неизвестные протоколы доступа
};

/*!
* \enum fEtype
* \brief Перечесление видов расширения файлов 
*/
enum fEtype
{
	grafics=0,					//!< Графические файлы
	sound=1,					//!< Звуковые файлы
	video=2,					//!< Видео файлы
	text=3,						//!< Текстовые файлы
	webpage=4,					//!< Файл веб-страниц
	exefile=5,					//!< Выполняемые файлы
	refenceCodeFile=6,			//!< Файлы программного кода
	objFile=7,					//!< Объектные файлы
	otherFilenameExtension=8,	//!< Файлы с неизвестными расширениями
};