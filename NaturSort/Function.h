#include "Enumerations.h"
#include "Libs.h"

/*!
*\fn ������� ��������� ������������ ���������� �����
*\param [in|out] sort - �����, ��� ���� - ��� ������, �������� - ����� ����� ��� ������
*\return ��������������� ������
*/
QStringList sortGroupedString(QMap<groupType, QStringList> &sort);

/*!
*\fn ������� ��������� ������������ ���������� ����� ��������
*\param [in|out] sortList - ����� �����
*/
void sortByLexeme(QStringList &sortList);

/*!
*\fn ������� ��������� ������������ ������ �� ������� ����������
*\param [in] sortList - ����� �����
*\return �����, ��� ���� - ��� ������, �������� - ����� ����� ��� ������
*/
QMap<groupType, QStringList> groupForSort(QStringList &input);

/*!
* ������� ��������� ������������ ���������� ����� ������ ���������� �������
*\param [in|out] sortList - ����� �����
*/
void sortByProtocol(QStringList &sortList);

/*!
*\fn ������� ��������� ������������ ���������� ����� ������ ��������� ��������
*\param [in|out] sortList - ����� �����
*/
void sortByDisk(QStringList &sortList);

/*!
*\fn ������� ��������� ������������ ���������� ����� ������ ���������� ������
*\param [in|out] sortList - ����� �����
*/
void sortByFilenameExtension(QStringList &sortList);

/*!
*\fn ������� ��������� ������������ ���������� ����� ������ e-mail �������
*\param [in|out] sortList - ����� �����
*/
void sortByEmail(QStringList &sortList);

/*!
*\fn ������� ��������� ���� �����
*\param [in] s1 - ������ ������
*\param [in] s2 - ������ ������
*\return ���������� ��������� ���������
*/
bool caseInsensitiveLessThan(const QString &s1, const QString &s2);