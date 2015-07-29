#include "Enumerations.h"
#include "Libs.h"

/*!
*\fn Функция выполняет естественную сортировку строк
*\param [in|out] sort - карта, где ключ - тип группы, значение - набор строк для группы
*\return отсортированные строки
*/
QStringList sortGroupedString(QMap<groupType, QStringList> &sort);

/*!
*\fn Функция выполняет естественную сортировку строк названию
*\param [in|out] sortList - набор строк
*/
void sortByLexeme(QStringList &sortList);

/*!
*\fn Функция выполняет распределяют строки по группам сортировки
*\param [in] sortList - набор строк
*\return карта, где ключ - тип группы, значение - набор строк для группы
*/
QMap<groupType, QStringList> groupForSort(QStringList &input);

/*!
* Функция выполняет естественную сортировку строк группы протоколов доступа
*\param [in|out] sortList - набор строк
*/
void sortByProtocol(QStringList &sortList);

/*!
*\fn Функция выполняет естественную сортировку строк группы устройств хранения
*\param [in|out] sortList - набор строк
*/
void sortByDisk(QStringList &sortList);

/*!
*\fn Функция выполняет естественную сортировку строк группы расширения файлов
*\param [in|out] sortList - набор строк
*/
void sortByFilenameExtension(QStringList &sortList);

/*!
*\fn Функция выполняет естественную сортировку строк группы e-mail адресов
*\param [in|out] sortList - набор строк
*/
void sortByEmail(QStringList &sortList);

/*!
*\fn Функция сравнения двух строк
*\param [in] s1 - первая строка
*\param [in] s2 - вторая строка
*\return логический результат сравнения
*/
bool caseInsensitiveLessThan(const QString &s1, const QString &s2);