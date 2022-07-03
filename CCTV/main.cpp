#include "cctv.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CCTV w;
	w.show();
	return a.exec();
}
