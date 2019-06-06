#include "GaborNoise.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "MathFun2d.h"





int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GaborNoise w;
	w.show();
	return a.exec();
}
