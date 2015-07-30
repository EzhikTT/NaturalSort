#include "Libs.h"

/*!
 * \file In-Out.h
 * \brief Файл состоит из прототипов функций ввода/вывода
*/

/*!
* \fn QStringList read(const QString &fileName)
* \brief Функция выполняет загурузку строк из файла
* \param[in] fileName  Имя файла
* \return Список строк
*/
QStringList read(const QString &fileName);

/*!
* \fn void write(const QString &fileName, QStringList &out)
* \brief Функция выполняет загурузку списка строк в файл
* \param[in] fileName  Имя файла
* \param[in] out Список строк
*/
void write(const QString &fileName, QStringList &out);
