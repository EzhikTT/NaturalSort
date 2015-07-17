#include "Libs.h"




/*!
* ������� ��������� ������������ ���������� �����
*\param [in|out] sortList - ����� �����
*/
void sort(QStringList &sortList);

/*!
* ������� ��������� ������������ ������ �� ������� ����������
*\param [in] sortList - ����� �����
*\return �����, ��� ���� - ��� ������, �������� - ����� ����� ��� ������
*/
QMap<typeData, QStringList> groupingForSort(QStringList &input);

/*!
* ������� ��������� ������������ ���������� ����� ������ ���������� �������
*\param [in|out] sortList - ����� �����
*/
void sortProtocol(QStringList &sortList);

/*!
* ������� ��������� ������������ ���������� ����� ������ ��������� ��������
*\param [in|out] sortList - ����� �����
*/
void sortDisk(QStringList &sortList);

/*!
* ������� ��������� ������������ ���������� ����� ������ ���������� ������
*\param [in|out] sortList - ����� �����
*/
void sortFilenameExtention(QStringList &sortList);

/*!
* ������� ��������� ������������ ���������� ����� ������ e-mail �������
*\param [in|out] sortList - ����� �����
*/
void sortEmail(QStringList &sortList);