#include "Libs.h"


/*!
* ������� ��������� ������������ ���������� �����
*\param [in|out] sort - �����, ��� ���� - ��� ������, �������� - ����� ����� ��� ������
*\return ��������������� ������
*/
QStringList sort(QMap<typeData, QStringList> &sort);

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
QMap<typeData, QStringList> groupForSort(QStringList &input);

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
void sortByFilenameExtention(QStringList &sortList);

/*!
* ������� ��������� ������������ ���������� ����� ������ e-mail �������
*\param [in|out] sortList - ����� �����
*/
void sortByEmail(QStringList &sortList);