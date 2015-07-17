#include "Libs.h"




/*!
* Функция выполняет естественную сортировку строк
*\param [in|out] sortList - набор строк
*/
void sort(QStringList &sortList);

/*!
* Функция выполняет распределяют строки по группам сортировки
*\param [in] sortList - набор строк
*\return карта, где ключ - тип группы, значение - набор строк для группы
*/
QMap<typeData, QStringList> groupingForSort(QStringList &input);

/*!
* Функция выполняет естественную сортировку строк группы протоколов доступа
*\param [in|out] sortList - набор строк
*/
void sortProtocol(QStringList &sortList);

/*!
* Функция выполняет естественную сортировку строк группы устройств хранения
*\param [in|out] sortList - набор строк
*/
void sortDisk(QStringList &sortList);

/*!
* Функция выполняет естественную сортировку строк группы расширения файлов
*\param [in|out] sortList - набор строк
*/
void sortFilenameExtention(QStringList &sortList);

/*!
* Функция выполняет естественную сортировку строк группы e-mail адресов
*\param [in|out] sortList - набор строк
*/
void sortEmail(QStringList &sortList);