#include <QtCore/QCoreApplication>

#include "Testing.h"
#include "Function.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	testing();

	return a.exec();
}
