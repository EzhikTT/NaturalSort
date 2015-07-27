#include "Enumerations.h"
#include "Libs.h"

/*!
* Функция выполняет естественную сортировку строк
*\param [in|out] sort - карта, где ключ - тип группы, значение - набор строк для группы
*\return отсортированные строки
*/
QStringList sortGroupedString(QMap<groupType, QStringList> &sort);

/*!
* Функция выполняет естественную сортировку строк названию
*\param [in|out] sortList - набор строк
*/
void sortByLexeme(QStringList &sortList);

/*!
* Функция выполняет распределяют строки по группам сортировки
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
* Функция выполняет естественную сортировку строк группы устройств хранения
*\param [in|out] sortList - набор строк
*/
void sortByDisk(QStringList &sortList);

/*!
* Функция выполняет естественную сортировку строк группы расширения файлов
*\param [in|out] sortList - набор строк
*/
void sortByFilenameExtension(QStringList &sortList);

/*!
* Функция выполняет естественную сортировку строк группы e-mail адресов
*\param [in|out] sortList - набор строк
*/
void sortByEmail(QStringList &sortList);