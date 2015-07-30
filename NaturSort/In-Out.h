#include "Libs.h"

/*!
 * \file In-Out.h
 * \brief ���� ������� �� ���������� ������� �����/������
*/

/*!
* \fn QStringList read(const QString &fileName)
* \brief ������� ��������� ��������� ����� �� �����
* \param[in] fileName  ��� �����
* \return ������ �����
*/
QStringList read(const QString &fileName);

/*!
* \fn void write(const QString &fileName, QStringList &out)
* \brief ������� ��������� ��������� ������ ����� � ����
* \param[in] fileName  ��� �����
* \param[in] out ������ �����
*/
void write(const QString &fileName, QStringList &out);
