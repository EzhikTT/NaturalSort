#include "Enumerations.h"
#include "Libs.h"

/*!
 * \file Function.h
 * \brief ���� ������� �� ���������� �������� �������
*/

/*!
* \fn QStringList sortGroupedString(QMap<groupType, QStringList> &sort)
* \brief ������� ��������� ������������ ���������� �����
* \param[in,out] sort  �����, ��� ���� - ��� ������, �������� - ����� ����� ��� ������
* \return ��������������� ������
*/
QStringList sortGroupedString(QMap<groupType, QStringList> &sort);

/*!
* \fn void sortByLexeme(QStringList &sortList)
* \brief ������� ��������� ������������ ���������� ����� ��������
* \param[in,out] sortList  ����� �����
*/
void sortByLexeme(QStringList &sortList);

/*!
* \fn QMap<groupType, QStringList> groupForSort(QStringList &input)
* \brief ������� ��������� ������������ ������ �� ������� ����������
* \param [in] sortList  ����� �����
* \return �����, ��� ����  ��� ������, �������� - ����� ����� ��� ������
*/
QMap<groupType, QStringList> groupForSort(QStringList &input);

/*!
* \fn void sortByProtocol(QStringList &sortList)
* \brief ������� ��������� ������������ ���������� ����� ������ ���������� �������
* \param[in,out] sortList  ����� �����
*/
void sortByProtocol(QStringList &sortList);

/*!
* \fn void sortByDisk(QStringList &sortList)
* \brief ������� ��������� ������������ ���������� ����� ������ ��������� ��������
* \param[in,out] sortList  ����� �����
*/
void sortByDisk(QStringList &sortList);

/*!
* \fn void sortByFilenameExtension(QStringList &sortList)
* \brief ������� ��������� ������������ ���������� ����� ������ ���������� ������
* \param[in,out] sortList ����� �����
*/
void sortByFilenameExtension(QStringList &sortList);

/*!
* \fn void sortByEmail(QStringList &sortList)
* \brief ������� ��������� ������������ ���������� ����� ������ e-mail �������
* \param[in,out] sortList ����� �����
*/
void sortByEmail(QStringList &sortList);

/*!
* \fn bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
* \brief ������� ��������� ���� �����
* \param[in] s1  ������ ������
* \param[in] s2  ������ ������
* \return ���������� ��������� ���������
*/
bool caseInsensitiveLessThan(const QString &s1, const QString &s2);