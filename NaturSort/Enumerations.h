#pragma once

#include "Libs.h"


// Перечисление типов групп для сортировки
enum groupType
{
	protocol,			// Протоколы доступа
	disk,				// Место хранения
	filenameExtention,	// Расширение файла
	email,				// E-mail адрес
	other,				// Строки, не подходящие под вышеперечисленные группы 
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
	otherP,
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
	otherFE,
};