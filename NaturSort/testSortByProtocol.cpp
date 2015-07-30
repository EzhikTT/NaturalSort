#include "testSortByProtocol.h"

/*!
 * \file testSortByProtocol.cpp
 * \brief Файл состоит из реализации методов класса тестирования функции sortByProtocol
*/

testSortByProtocol::testSortByProtocol(void)
{
}

// Строки уже отсортированы
void testSortByProtocol::test1_stringWereSorted()
{
	QStringList test, ideal;

	test<<"DHCP: 192.177.0.1"<<"DNS: 192.168.0.0"<<"ftp://public.ftp-servers.com/"<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"pool.ntp.org"<<"nntp:comp.infosystems.gopher/086"<<"git@github.com:EzhikTT/NaturalSort.git"<<"telnet://guest:password@apollo.polyn.kiae.su";
	ideal<<"DHCP: 192.177.0.1"<<"DNS: 192.168.0.0"<<"ftp://public.ftp-servers.com/"<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"pool.ntp.org"<<"nntp:comp.infosystems.gopher/086"<<"git@github.com:EzhikTT/NaturalSort.git"<<"telnet://guest:password@apollo.polyn.kiae.su";

	sortByProtocol(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// Строки не отсортированы
void testSortByProtocol::test2_stringWereNotSorted()
{
	QStringList test, ideal;

	test<<"https://www.youtube.com/"<<"DHCP: 192.177.0.1"<<"ftp://public.ftp-servers.com/"<<"nntp:comp.infosystems.gopher/086"<<"git@github.com:EzhikTT/NaturalSort.git"<<"DNS: 192.168.0.0"<<"telnet://guest:password@apollo.polyn.kiae.su"<<"http://www.youtube.com/"<<"pool.ntp.org";
	ideal<<"DHCP: 192.177.0.1"<<"DNS: 192.168.0.0"<<"ftp://public.ftp-servers.com/"<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"pool.ntp.org"<<"nntp:comp.infosystems.gopher/086"<<"git@github.com:EzhikTT/NaturalSort.git"<<"telnet://guest:password@apollo.polyn.kiae.su";

	sortByProtocol(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

// Имеются строки, не принадлежащие перечислению с известными протоколами
void testSortByProtocol::test3_stringWhithUnknowProtocol()
{
	QStringList test, ideal;

	test<<"news:comp.infosystems.gopher"<<"https://www.youtube.com/"<<"DHCP: 192.177.0.1"<<"ftp://public.ftp-servers.com/"<<"nntp:comp.infosystems.gopher/086"<<"git@github.com:EzhikTT/NaturalSort.git"<<"DNS: 192.168.0.0"<<"telnet://guest:password@apollo.polyn.kiae.su"<<"http://www.youtube.com/"<<"pool.ntp.org";
	ideal<<"DHCP: 192.177.0.1"<<"DNS: 192.168.0.0"<<"ftp://public.ftp-servers.com/"<<"http://www.youtube.com/"<<"https://www.youtube.com/"<<"pool.ntp.org"<<"nntp:comp.infosystems.gopher/086"<<"git@github.com:EzhikTT/NaturalSort.git"<<"telnet://guest:password@apollo.polyn.kiae.su"<<"news:comp.infosystems.gopher";

	sortByProtocol(test);

	for(int i=0; i<test.count(); i++)
	{
		QCOMPARE(test.value(i), ideal.value(i));
	}
	QCOMPARE(test.count(), ideal.count());
}

testSortByProtocol::~testSortByProtocol(void)
{
}
