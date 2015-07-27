#include "Enumerations.h"
#include "Libs.h"

/*!
* ������� ��������� ������������ ���������� �����
*\param [in|out] sort - �����, ��� ���� - ��� ������, �������� - ����� ����� ��� ������
*\return ��������������� ������
*/
QStringList sortGroupedString(QMap<groupType, QStringList> &sort);

/*!
* ������� ��������� ������������ ���������� ����� ��������
*\param [in|out] sortList - ����� �����
*/
void sortByLexeme(QStringList &sortList);

/*!
* ������� ��������� ������������ ������ �� ������� ����������
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
* ������� ��������� ������������ ���������� ����� ������ ��������� ��������
*\param [in|out] sortList - ����� �����
*/
void sortByDisk(QStringList &sortList);

/*!
* ������� ��������� ������������ ���������� ����� ������ ���������� ������
*\param [in|out] sortList - ����� �����
*/
void sortByFilenameExtension(QStringList &sortList);

/*!
* ������� ��������� ������������ ���������� ����� ������ e-mail �������
*\param [in|out] sortList - ����� �����
*/
void sortByEmail(QStringList &sortList);