#pragma once

#include "Libs.h"


// Перечисление типов групп для сортировки
enum groupType
{
	protocol,			// Протоколы доступа
	disk,				// Место хранения
	filenameExtension,	// Расширение файла
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
	otherProtocol,
};


// Перечесление видов расширения файлов 
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