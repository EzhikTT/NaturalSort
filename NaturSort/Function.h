#include "Enumerations.h"
#include "Libs.h"

/*!
 * \file Function.h
 * \brief Файл состоит из прототипов основных функций
*/

/*!
* \fn QStringList sortGroupedString(QMap<groupType, QStringList> &sort)
* \brief Функция выполняет естественную сортировку строк
* \param[in,out] sort  карта, где ключ - тип группы, значение - набор строк для группы
* \return Отсортированные строки
*/
QStringList sortGroupedString(QMap<groupType, QStringList> &sort);

/*!
* \fn void sortByLexeme(QStringList &sortList)
* \brief Функция выполняет естественную сортировку строк названию
* \param[in,out] sortList  Набор строк
*/
void sortByLexeme(QStringList &sortList);

/*!
* \fn QMap<groupType, QStringList> groupForSort(QStringList &input)
* \brief Функция выполняет распределяют строки по группам сортировки
* \param [in] sortList  набор строк
* \return Карта, где ключ  тип группы, значение - набор строк для группы
*/
QMap<groupType, QStringList> groupForSort(QStringList &input);

/*!
* \fn void sortByProtocol(QStringList &sortList)
* \brief Функция выполняет естественную сортировку строк группы протоколов доступа
* \param[in,out] sortList  Набор строк
*/
void sortByProtocol(QStringList &sortList);

/*!
* \fn void sortByDisk(QStringList &sortList)
* \brief Функция выполняет естественную сортировку строк группы устройств хранения
* \param[in,out] sortList  Набор строк
*/
void sortByDisk(QStringList &sortList);

/*!
* \fn void sortByFilenameExtension(QStringList &sortList)
* \brief Функция выполняет естественную сортировку строк группы расширения файлов
* \param[in,out] sortList Набор строк
*/
void sortByFilenameExtension(QStringList &sortList);

/*!
* \fn void sortByEmail(QStringList &sortList)
* \brief Функция выполняет естественную сортировку строк группы e-mail адресов
* \param[in,out] sortList Набор строк
*/
void sortByEmail(QStringList &sortList);

/*!
* \fn bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
* \brief Функция сравнения двух строк
* \param[in] s1  Первая строка
* \param[in] s2  Вторая строка
* \return Логический результат сравнения
*/
bool caseInsensitiveLessThan(const QString &s1, const QString &s2);