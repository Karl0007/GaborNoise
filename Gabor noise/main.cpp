#include "GaborNoise.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "MathFun2d.h"
#include "ParaTable.h"
#include <qcolordialog.h>




int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ParaTable w;
	w.show();
	return a.exec();
}
