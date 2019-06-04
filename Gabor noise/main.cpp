#include "GaborNoise.h"
#include <QtWidgets/QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GaborNoise w;
	w.show();
	std::cout << 123;
	return a.exec();
}
